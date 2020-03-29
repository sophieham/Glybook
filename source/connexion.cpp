#include "connexion.h"
#include "./ui_connexion.h"
#include <QMessageBox>

Connexion::Connexion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::connexion)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("glybook");
    db.setUserName("root");
    db.setPassword("");
    db.open();

    QSqlQuery firstTime("SELECT * from utilisateur");
    if(!firstTime.next()){ // vérifie s'il y a au moins un compte dans la bdd, sinon affiche de quoi se créer un compte
        Dialog* d = new Dialog(this);
        d->setModal(true);
        d->show();
        connect(d, SIGNAL(sendFirstData(QStringList)), this, SLOT(receiveFirstData(QStringList)));
    }
}

Connexion::~Connexion()
{
    delete ui;
}

void Connexion::receiveFirstData(QStringList data){
    QString fName = data[0];
    QString lName = data[1];
    QString user = data[2];
    QString pass = hashPass(data[3]);

    QSqlQuery addToDb;
    addToDb.prepare("INSERT INTO `utilisateur` (`id`, `lastName`, `firstName`, `username`, `pass`, `rank`) VALUES (NULL, :lName, :fName, :user, :pass, 1)");
    addToDb.bindValue(":lName", lName);
    addToDb.bindValue(":fName", fName);
    addToDb.bindValue(":user", user);
    addToDb.bindValue(":pass", pass);
    if(addToDb.exec()){
    QMessageBox::information(this, "Succès!", "Vous pouvez à present vous connecter!");
    }
}

QString Connexion::hashPass(QString text){
    QByteArray hash = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Sha256);
    QString pass=hash.toHex();
    return pass;
}


void Connexion::on_btnConnect_clicked()
{
    QString user =  ui->textUser->text();
    QString pass = hashPass(ui->textPass->text());

    if(!user.isEmpty()){
        QSqlQuery query("SELECT username, pass FROM utilisateur WHERE username= '"+user+"' AND pass = '"+pass+"'");
        if(query.next()){
            Glybook* page = new Glybook();
            page->show();
            this->close();
        }
        else QMessageBox::warning(this, "Echec!", "Combinaison nom d'utilisateur/mot de passe incorrecte!");
    }
}
