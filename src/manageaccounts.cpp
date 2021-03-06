#include "manageaccounts.h"
#include "ui_manageaccounts.h"

manageAccounts::manageAccounts(const User &connected, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manageAccounts), connected(connected)
{
    ui->setupUi(this);

    setFixedSize(900, 700);
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    displayAccountList();
}

manageAccounts::~manageAccounts(){
    delete ui;
}

// affiche la liste de tous les comptes selon leur noms, pr�noms et type de compte (0: abonn�, 1: admin)
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
// ouvre une nouvelle page en fonction de la ligne cliqu�e pour modifier l'utilisateur ad�quat
void manageAccounts::on_accList_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    myAccount *showAccount = new myAccount(connected, ui->accList->item(row, 3)->text());
    showAccount->show();
    connect(showAccount, SIGNAL(refresh(bool)), this, SLOT(refreshSlot(bool)));
}

// actions pour le clic sur "ajouter un utilisateur"
// ajoute un compte (abonn� ou admin) � la base de donn�e si tous les champs sont remplis
// recharge le tableau des comptes
void manageAccounts::on_addAccBtn_clicked()
{
    int rank = 0;
    QString lName = ui->lNameTxt_2->text();
    QString fName = ui->fNameTxt_2->text();
    QString username = ui->userTxt_2->text();
    QString pass = cryptoHashClass::hashPass(ui->passTxt_2->text());
    QString address = ui->addressTxt_2->text();
    QString phone = ui->phoneTxt_2->text();
    int limit = ui->limitTxt_2->text().toInt();

    if(ui->admBtn_2->isChecked())
        rank=1;

    if(!(lName.isEmpty() && fName.isEmpty() && username.isEmpty())){
        // v�rifie si le nom d'utilisateur est pris ou pas
        QSqlQuery checkUsername;
        checkUsername.exec("SELECT * FROM users WHERE username = '"+username+"'");
        if(checkUsername.next()){
            QMessageBox::critical(this, "Error", "Username is already taken. Please choose another username.");
            return;
        }

        // on commence l'ajout dans la base de donn�e
        QSqlQuery addToDb;
        addToDb.prepare("INSERT INTO `users` (`id`, `lastName`, `firstName`, `username`, `pass`, `rank`) VALUES (NULL, :lName, :fName, :username, :pass, :rank) ");
        addToDb.bindValue(":lName", lName);
        addToDb.bindValue(":fName", fName);
        addToDb.bindValue(":username", username);
        addToDb.bindValue(":pass", pass);
        addToDb.bindValue(":rank", rank);
        if (addToDb.exec() && ui->admBtn_2->isChecked()){
            QMessageBox::information(this, "Success!", "The new administrator has been added to database!");
            ui->accList->clearContents();
            displayAccountList();
            return;
        }

        // ajout de la partie abbonn� si �a en est un
        if(ui->subBtn_2->isChecked() && !(address.isEmpty() && phone.isEmpty())){
            addToDb.prepare("INSERT INTO `u_subscriber` (`subscriber_username`, `address`, `phone`, `max_books`) VALUES (:username, :address, :phone, :limit) ");
            addToDb.bindValue(":username", username);
            addToDb.bindValue(":address", address);
            addToDb.bindValue(":phone", phone);
            addToDb.bindValue(":limit", limit);
            if(addToDb.exec()){
                QMessageBox::information(this, "Sucess!", "The new subscriber has been added to the database!");
                ui->accList->clearContents();
                displayAccountList();
                return;
            }
        }
        // si la partie abonn� n'est pas bien remplie
        else {
            QMessageBox::critical(this, "Error!", "Please fill all the fields!");
        }
    }
    // si les autres infos sont mal remplies
    else{
        QMessageBox::critical(this, "Error!", "Please fill first name, last name username and password fields!");
    }
}

// supprime le compte selectionn� en appuyant sur la touche delete
// ne peut pas supprimer des comptes qui ont deja une activit� (reservations ou favoris)
// affiche un message et actualise la page si �a s'est bien pass�
void manageAccounts::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Delete && connected.getType()==1){ // si on appuie sur delete et qu'on est admin
        int row = ui->accList->currentRow();
        int answer = QMessageBox::warning(this, "Delete a user", "Are you sure to delete "+ui->accList->item(row, 3)->text()+"? \nNote that you can only delete a account that is unused.", QMessageBox::Yes | QMessageBox::No);
        if(answer == QMessageBox::Yes){
            QSqlQuery delAccount;
            delAccount.exec("DELETE FROM `u_subscriber` WHERE `u_subscriber`.`subscriber_username` ='"+ui->accList->item(row, 3)->text()+"'");
            delAccount.exec("DELETE FROM `users` WHERE `users`.`username` ='"+ui->accList->item(row, 3)->text()+"'");
            if(delAccount.exec()){
                QMessageBox::information(this, "Success!", "This account has been successfully deleted!");
                ui->accList->clearContents();
                displayAccountList();
            }
            else{
                QMessageBox::critical(this, "Something went wrong...", "This account can't be deleted. It has active bookings and bookmarks");
            }
        }
    }
}

// d�coche l'autre bouton et rend modifiable certains champs propre a l'abonn�
void manageAccounts::on_subBtn_2_clicked()
{
    ui->admBtn_2->setChecked(false);
    ui->limitTxt_2->setEnabled(true);
    ui->phoneTxt_2->setEnabled(true);
    ui->addressTxt_2->setEnabled(true);
}

// d�coche l'autre bouton et rend non-modifiable certains champs propre � l'abonn�
void manageAccounts::on_admBtn_2_clicked()
{
    ui->subBtn_2->setChecked(false);
    ui->limitTxt_2->setEnabled(false);
    ui->phoneTxt_2->setEnabled(false);
    ui->addressTxt_2->setEnabled(false);
}

void manageAccounts::refreshSlot(bool b){
    if(b){
      ui->accList->clearContents();
      displayAccountList();
    }
}
