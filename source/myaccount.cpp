#include "myaccount.h"
#include "ui_myaccount.h"

myAccount::myAccount(const User &connected, const QString &user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myAccount), connected(connected), user(user)
{
    ui->setupUi(this);
    setFixedSize(650, 700);
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    prepareAccount();
    displayAccount();

}

myAccount::~myAccount()
{
    delete ui;
}

void myAccount::prepareAccount(){
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

void myAccount::displayAccount(){
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

    if(account.getType()==1){
        ui->historyButton->hide();
    }
}

void myAccount::on_modifyButton_clicked()
{
    accountDialog *dialog = new accountDialog(id, connected);
    dialog->show();
    connect(dialog, SIGNAL(refresh(bool)), this, SLOT(refreshSlot(bool)));
}

void myAccount::on_closeButton_clicked()
{
    this->close();
}

void myAccount::on_historyButton_clicked()
{
    accountHistory *history = new accountHistory(connected, user);
    history->show();
}

void myAccount::refreshSlot(bool b){
    if(b){
        emit refresh(true);
        prepareAccount();
        displayAccount();
    }
    else this->close();
}
