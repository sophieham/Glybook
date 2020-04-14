#include "manageaccounts.h"
#include "ui_manageaccounts.h"

manageAccounts::manageAccounts(const User &connected, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manageAccounts), connected(connected)
{
    ui->setupUi(this);

    displayAccountList();
}

manageAccounts::~manageAccounts(){
    delete ui;
}

// affiche la liste de tous les comptes selon leur noms, prénoms et type de compte (0: abonné, 1: admin)
void manageAccounts::displayAccountList(){
    QSqlQuery listAccQ("SELECT count(id) FROM users");
    listAccQ.first();

    ui->accList->setRowCount(listAccQ.value(0).toInt());
    listAccQ.exec("SELECT lastName, firstName, rank, username FROM users");

    int row = 0;

    for(listAccQ.first(); listAccQ.isValid(); listAccQ.next(), ++row){
        ui->accList->setItem(row, 0, new QTableWidgetItem(listAccQ.value(0).toString())); // last name
        ui->accList->setItem(row, 1, new QTableWidgetItem(listAccQ.value(1).toString())); // first name
        ui->accList->setItem(row, 3, new QTableWidgetItem(listAccQ.value(3).toString())); // username
        if(listAccQ.value(2).toInt()==0){
             ui->accList->setItem(row, 2, new QTableWidgetItem("Subscriber"));
        }
        else
            ui->accList->setItem(row, 2, new QTableWidgetItem("Administrator"));

    }
    ui->accList->hideColumn(3);
}

// action lors d'un double clic sur une cellule du tableau d'utilisateurs
// ouvre une nouvelle page en fonction de la ligne cliquée pour modifier l'utilisateur adéquat
void manageAccounts::on_accList_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    myAccount *showAccount = new myAccount(connected, ui->accList->item(row, 3)->text());
    showAccount->show();
                        // METTRE A JOUR LE TABLEAU UNE FOIS LA MODIFICATION FAITE!!!!
}

QString manageAccounts::hashPass(QString text){
    QByteArray hash = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Sha256);
    QString pass=hash.toHex();
    return pass;
}

// actions pour le clic sur "ajouter un utilisateur"
// ajoute un compte (abonné ou admin) à la base de donnée si tous les champs sont remplis
// recharge le tableau des comptes
void manageAccounts::on_addAccBtn_clicked()
{
    int rank = 0;
    QString lName = ui->lNameTxt_2->text();
    QString fName = ui->fNameTxt_2->text();
    QString username = ui->userTxt_2->text();
    QString pass = hashPass(ui->passTxt_2->text());
    QString address = ui->addressTxt_2->text();
    QString phone = ui->phoneTxt_2->text();
    int limit = ui->limitTxt_2->text().toInt();

    if(ui->admBtn_2->isChecked())
        rank=1;

    if(!(lName.isEmpty() && fName.isEmpty() && username.isEmpty())){
        // vérifie si le nom d'utilisateur est pris ou pas
        QSqlQuery checkUsername;
        checkUsername.exec("SELECT * FROM users WHERE username = '"+username+"'");
        if(checkUsername.next()){
            QMessageBox::critical(this, "Error", "Username is already taken. Please choose another username.");
            return;
        }

        // on commence l'ajout dans la base de donnée
        QSqlQuery addToDb;
        addToDb.prepare("INSERT INTO `users` (`id`, `lastName`, `firstName`, `username`, `pass`, `rank`) VALUES (NULL, :lName, :fName, :username, :pass, :rank) ");
        addToDb.bindValue(":lName", lName);
        addToDb.bindValue(":fName", fName);
        addToDb.bindValue(":username", username);
        addToDb.bindValue(":pass", pass);
        addToDb.bindValue(":rank", rank);
        if (!(addToDb.exec()) && ui->admBtn_2->isChecked()){
            QMessageBox::information(this, "Success!", "The new administrator has been added to database!");
            return;
        }

        // ajout de la partie abbonné si ça en est un
        if(ui->subBtn_2->isChecked() && !(address.isEmpty() && phone.isEmpty())){
            addToDb.prepare("INSERT INTO `u_subscriber` (`subscriber_username`, `address`, `phone`, `max_books`) VALUES (:username, :address, :phone, :limit) ");
            addToDb.bindValue(":username", username);
            addToDb.bindValue(":address", address);
            addToDb.bindValue(":phone", phone);
            addToDb.bindValue(":limit", limit);
            if(addToDb.exec()){
                QMessageBox::information(this, "Sucess!", "The new subscriber has been added to the database!");
            }
        }
        // si la partie abonné n'est pas bien remplie
        else{
            QMessageBox::critical(this, "Error!", "Please fill all the fields!");
        }
    }
    // si les autres infos sont mal remplie
    else{
        QMessageBox::critical(this, "Error!", "Please fill all the fields!");
    }

    ui->accList->clearContents();
    displayAccountList();
}

// décoche l'autre bouton et rend modifiable certains champs propre a l'abonné
void manageAccounts::on_subBtn_2_clicked()
{
    ui->admBtn_2->setChecked(false);
    ui->limitTxt_2->setEnabled(true);
    ui->phoneTxt_2->setEnabled(true);
    ui->addressTxt_2->setEnabled(true);
}

// décoche l'autre bouton et rend non-modifiable certains champs propre à l'abonné
void manageAccounts::on_admBtn_2_clicked()
{
    ui->subBtn_2->setChecked(false);
    ui->limitTxt_2->setEnabled(false);
    ui->phoneTxt_2->setEnabled(false);
    ui->addressTxt_2->setEnabled(false);
}
