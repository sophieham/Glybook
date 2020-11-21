#include "accountdialog.h"
#include "ui_accountdialog.h"

accountDialog::accountDialog(const int &id, const User &connected, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accountDialog), id(id), connected(connected)
{
    ui->setupUi(this);
    if(ui->adm_RB->isChecked()){
        ui->sub_RB->setChecked(false);
    }
    if(ui->sub_RB->isChecked()){
        ui->adm_RB->setChecked(false);
    }

    QSqlQuery displayQry("SELECT * FROM `users` LEFT JOIN u_subscriber ON users.username = u_subscriber.subscriber_username WHERE id="+QString::number(id));
    if(displayQry.next()){
        setUsername(displayQry.value(3).toString());

        ui->lNameEdit->setText(displayQry.value(1).toString());
        ui->fNameEdit->setText(displayQry.value(2).toString());
        ui->userEdit->setText(getUsername());
        ui->addressEdit->setText(displayQry.value(7).toString());
        ui->phoneEdit->setText(displayQry.value(8).toString());
        ui->resvLimitEdit->setText(displayQry.value(9).toString());
        if(connected.getType()==1){
            ui->adm_RB->setChecked(true);
            setRank(1);
        }
        else {
            ui->sub_RB->setChecked(true);
            setRank(0);
            ui->adm_RB->hide();
            ui->resvLimitEdit->setEnabled(false);
        }
    }

}

accountDialog::~accountDialog()
{
    delete ui;
}

// appui sur le bouton "Save"
// enregistre les donn�es du formulaire dans la base de donn�e et affiche un message si tout s'est bien pass�
void accountDialog::on_dialogButton_accepted()
{

    QString fName = ui->fNameEdit->text();
    QString lName = ui->lNameEdit->text();
    setUsername(ui->userEdit->text());
    QString pass = ui->passEdit->text();
    QString address = ui->addressEdit->text();
    QString phone = ui->phoneEdit->text();
    int limit =  ui->resvLimitEdit->text().toInt();
    setRank(1);


    QSqlQuery updateSubDb;
        if(ui->sub_RB->isChecked()){
            setRank(0);
            updateSubDb.prepare("UPDATE `u_subscriber` SET `address` = :address, `phone` = :phone, `max_books` = :limit WHERE `u_subscriber`.`subscriber_username` = :user ");
            updateSubDb.bindValue(":address", address);
            updateSubDb.bindValue(":phone", phone);
            updateSubDb.bindValue(":limit", limit);
            updateSubDb.bindValue(":user", getUsername());
        }

        QSqlQuery updateDb;
        if(!(pass.isEmpty())){
            updateDb.prepare("UPDATE `users` SET `lastName` = :lName, `firstName` = :fName, `pass` = :pass, `rank` = :rank WHERE `users`.`id` = :id");
            updateDb.bindValue(":pass", cryptoHashClass::hashPass(pass));
        }
        else{
            updateDb.prepare("UPDATE `users` SET `lastName` = :lName, `firstName` = :fName, `rank` = :rank WHERE `users`.`id` = :id");
        }
        updateDb.bindValue(":lName", lName);
        updateDb.bindValue(":fName", fName);
        updateDb.bindValue(":rank", getRank());
        updateDb.bindValue(":id", id);


        if(updateDb.exec()){
            updateSubDb.exec();
            QMessageBox::information(this, "Sucess!", "Account has been modified!");
            emit refresh(true);
            this->close();
        }
}

QString accountDialog::getUsername() const
{
    return username;
}

void accountDialog::setUsername(const QString &user)
{
    username = user;
}

short accountDialog::getRank() const
{
    return rank;
}

void accountDialog::setRank(const short &number)
{
    rank = number;
}

void accountDialog::on_dialogButton_rejected()
{
    this->close();
}
