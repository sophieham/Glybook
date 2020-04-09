#include "myaccount.h"
#include "ui_myaccount.h"

myAccount::myAccount(const QString &user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myAccount), user(user)
{
    ui->setupUi(this);

    displayAccount();
    ui->lastName->setText(account.getLastName());
    ui->firstName->setText(account.getFirstName());
    ui->username->setText(account.getUser());
    if(account.getType()==1){
        ui->type->setText("Administrator");
        ui->labelAddress->clear();
        ui->labelPhone->clear();
        ui->labelReservation->clear();
    }
    else{
        ui->address->setText(account.getAddress());
        ui->phone->setText(account.getPhoneNo());
        ui->reservation->setText(QString::number(account.getLimit()));
    }
}

myAccount::~myAccount()
{
    delete ui;
}

void myAccount::displayAccount(){
    QSqlQuery query;
    query.prepare("SELECT * FROM users LEFT JOIN u_subscriber ON users.username = u_subscriber.subscriber_username WHERE username = :username");
    query.bindValue(":username", user);
    query.exec();
    if(query.next()){
        id = query.value(0).toInt();
        account.setLastName(query.value(1).toString());
        account.setFirstName(query.value(2).toString());
        account.setUser(user);
        account.setPswd(query.value(4).toString());
        account.setType(query.value(5).toInt());
        account.setLimit(new int(query.value(9).toInt()));
        account.setAddress(query.value(7).toString());
        account.setPhoneNo(query.value(8).toString());
    }
    else{
        this->close();
    }
}

void myAccount::on_modifyButton_clicked()
{
    accountDialog *dialog = new accountDialog(id);
    dialog->show();
}

void myAccount::on_closeButton_clicked()
{
    this->close();
}

void myAccount::on_historyButton_clicked()
{
    accountHistory *history = new accountHistory(id);
    history->show();
    //ouvrir une page historique des livres empruntés
}
