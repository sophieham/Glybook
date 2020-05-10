#include "accounthistory.h"
#include "ui_accounthistory.h"

accountHistory::accountHistory(const User &connected, const QString &user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::accountHistory), connected(connected), user(user)
{
    ui->setupUi(this);

    setFixedSize(700, 500);
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    displayHistory();
}

accountHistory::~accountHistory()
{
    delete ui;
}

// recupere l'historique a partir de la base de donn�e et l'affiche dans un tableau
void accountHistory::displayHistory(){
    QSqlQuery q;
    QSqlQuery count;
    if(connected.getType()==1 && user.isNull()){
        count.prepare("SELECT count(reservationID) FROM reservations");
        q.prepare("SELECT * FROM reservations");
    }
    else {
        count.prepare("SELECT count(reservationID) FROM reservations WHERE username = :user");
        count.bindValue(":user", user);
        q.prepare("SELECT * FROM reservations WHERE username = :user");
        q.bindValue(":user", user);
    }
    count.exec();
    count.first();
    ui->reservationView->setRowCount(count.value(0).toInt());

    q.exec();
    int row = 0;

    for(q.first(); q.isValid(); q.next(), ++row){
       ui->reservationView->setItem(row, 0, new QTableWidgetItem(q.value(1).toString())); // username
       ui->reservationView->setItem(row, 1, new QTableWidgetItem(q.value(2).toString())); // isbn
       ui->reservationView->setItem(row, 2, new QTableWidgetItem(q.value(3).toString())); // start
       ui->reservationView->setItem(row, 3, new QTableWidgetItem(q.value(4).toString())); // end
    }
}


// action lors du double clic sur une colonne
// appui sur un nom d'utilisateur => ouvre le profil associ�
// appui sur un identifiant de livre => ouvre la profil du livre associ�
void accountHistory::on_reservationView_cellDoubleClicked(int row, int column)
{
    QString information = ui->reservationView->item(row, column)->text();
    if(column==0){
         myAccount *acc = new myAccount(connected, information);
         acc->show();
    }
    else if(column==1){
         bookInformation *book = new bookInformation(connected, ui->reservationView->item(row, 1)->text());
         book->show();
         connect(book, SIGNAL(refresh(bool)), this, SLOT(refreshSlot(bool)));
    }
}

// actions lors de l'appui sur exporter
// propose d'enrengistrer les donn�es sur son ordinateur sous format csv ou txt
void accountHistory::on_exportButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Export", "bookhistory ("+QDate::currentDate().toString("dd-MM-yyyy")+")", "CSV files (.csv);;Text files (*.txt);;Any Files (*)", 0, 0); // getting the filename (full path)
    if(!filename.isNull()){
        QFile data(filename);
        if(data.open(QFile::WriteOnly |QFile::Truncate))
        {
            int row=0;
            QTextStream out(&data);
            QString columnsName = ui->reservationView->horizontalHeaderItem(0)->text()+";"+ui->reservationView->horizontalHeaderItem(1)->text()+";"+ui->reservationView->horizontalHeaderItem(2)->text()+";"+ui->reservationView->horizontalHeaderItem(3)->text()+"\n";
            out << columnsName;
            while (row < ui->reservationView->rowCount()) {
                QString information = ui->reservationView->item(row, 0)->text()+";"+ui->reservationView->item(row, 1)->text()+";" +ui->reservationView->item(row, 2)->text()+";"+ ui->reservationView->item(row, 3)->text()+"\n";
                out << information;
                ++row;
            }
            QMessageBox::information(this, "Success!", "Reservation data has been exported!");
        }
    }
}

// lors du clic sur close
void accountHistory::on_closeButton_clicked()
{
    this->close();
}

// actions quand une fenetre qui depend de celle-ci est modifi�e
void accountHistory::refreshSlot(bool b){
    if(b){
        // renvoi un signal pour modifier le tableau de bord (glybook.cpp)
        emit refresh(true);
    }
}
