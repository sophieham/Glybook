#include "connection.h"
#include "./ui_connection.h"


Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::connexion)
{
    ui->setupUi(this);

    setFixedSize(800, 600);
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    db.defaultConnection = "glybook";
    connection.connectToDb(db);

    QSqlQuery firstTime("SELECT * from users");
    if(!firstTime.next()){ // vérifie s'il y a au moins un compte dans la bdd, sinon affiche de quoi se créer un compte
        initialization = new Dialog(this);
        initialization->setModal(true);
        initialization->show();
        connect(initialization, SIGNAL(sendFirstData(QStringList)), this, SLOT(receiveFirstData(QStringList)));
    }
 }

Login::~Login()
{
    db.close();
    delete page;
    delete ui;
}

// slot qui recoit les données d'initialisation (si il y aucun compte dans la bdd)
// crée un compte avec les données et affiche un message si tout s'est bien passé
void Login::receiveFirstData(QStringList data){
    QString fName = data[0];
    QString lName = data[1];
    QString user = data[2];
    QString pass = cryptoHashClass::hashPass(data[3]);

    QSqlQuery addToDb;
    addToDb.prepare("INSERT INTO `users` (`id`, `lastName`, `firstName`, `username`, `pass`, `rank`) VALUES (NULL, :lName, :fName, :user, :pass, 1)");
    addToDb.bindValue(":lName", lName);
    addToDb.bindValue(":fName", fName);
    addToDb.bindValue(":user", user);
    addToDb.bindValue(":pass", pass);

    qDebug() << fName << user;
    if(addToDb.exec()){
    QMessageBox::information(this, "Succès!", "Vous pouvez à présent vous connecter!");
    }
}

// actions lors du clic sur connection
// verifie si un utilisateur correspond a la combinaison et ouvre le tableau de bord
// sinon affiche un message d'erreur
void Login::on_btnConnect_clicked()
{
    QString user =  ui->textUser->text();
    QString pass = cryptoHashClass::hashPass(ui->textPass->text());

    if(!user.isEmpty()){
        QSqlQuery query("SELECT * FROM `users` WHERE username= '"+user+"' AND pass = '"+pass+"'");
        if(query.next()){
            page = new Glybook(user);
            page->show();
            this->close();
        }
        else QMessageBox::warning(this, "Echec!", "Combinaison nom d'utilisateur/mot de passe incorrecte!");
    }
}
