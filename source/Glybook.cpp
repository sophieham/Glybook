#include "glybook.h"
#include "ui_glybook.h"
#include "connection.h"

Glybook::Glybook(const QString &name, QWidget *parent) : QMainWindow(parent), ui(new Ui::Glybook), username(name)
{
    ui->setupUi(this);
    setFixedSize(1400, 800);
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    setupLibrary();
    ui->title->setText(library->getType()+" library "+library->getName());
    ui->address->setText(library->getAddress());

    setupAccount();
    ui->lbl_connected->setText("Connected: "+connectedUser->getUser());

    if(connectedUser->getType()==0)
      ui->menuAdmin->menuAction()->setVisible(false); // cache le menu admin

    fillBookingWidget();
    fillRecentWidget();
    fillBookmarkWidget();
}

void Glybook::setupLibrary(){
    library = new Library();

    QSqlQuery query;
    query.exec("SELECT * FROM settings");
    query.last();

    library->setName(query.value(1).toString());
    library->setType(query.value(3).toString());
    library->setAddress(query.value(2).toString());

    ui->message->setText(query.value(4).toString());
}

// récupère le nom d'utilisateur entré et prépare un objet utilisateur avec les données de son compte
void Glybook::setupAccount(){
    QSqlQuery dbSession;
    dbSession.prepare("SELECT * FROM `users` LEFT JOIN u_subscriber ON users.username = u_subscriber.subscriber_username WHERE username = :user ");
    dbSession.bindValue(":user", username);
    dbSession.exec();

    connectedUser = new User();

    if(dbSession.next()){
        id = dbSession.value(0).toInt();
        connectedUser->setUser(username);
        connectedUser->setPswd(dbSession.value(4).toString());
        connectedUser->setLastName(dbSession.value(1).toString());
        connectedUser->setFirstName(dbSession.value(2).toString());
        connectedUser->setType(dbSession.value(5).toString().toShort());
        if(dbSession.value(5).toString().toShort()==0){
           connectedUser->setAddress(dbSession.value(7).toString());
           connectedUser->setPhoneNo(dbSession.value(8).toString());
           connectedUser->setLimit(new int(dbSession.value(9).toString().toInt()));
        }
    }
}

void Glybook::fillBookingWidget(){
    ui->bookingTable->verticalHeader()->setVisible(false);
    ui->bookingTable->setRowCount(3);
    QSqlQuery query;
    if(!connectedUser->getType()){
        query.prepare("SELECT bookID, books.name, end_date, username FROM `reservations` INNER JOIN books ON books.ISBN = reservations.bookID WHERE username=:user ORDER BY reservationID desc LIMIT 3 ");
        query.bindValue(":user", connectedUser->getUser());
        ui->bookingTable->hideColumn(3);
    }
    else query.prepare("SELECT bookID, books.name, end_date, username FROM `reservations` INNER JOIN books ON books.ISBN = reservations.bookID ORDER BY reservationID desc LIMIT 3");
    query.exec();
    int row=0;
    while(query.next()){
        ui->bookingTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // isbn
        ui->bookingTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // name
        ui->bookingTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // limit date
        ui->bookingTable->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        ++row;
    }
    ui->bookingTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

}

void Glybook::fillRecentWidget(){
    ui->recentTable->verticalHeader()->setVisible(false);
    ui->recentTable->setRowCount(10);
    QSqlQuery query("SELECT ISBN, books.name, b_genre.name FROM `books` INNER JOIN b_genre ON b_genre.genreID = books.genreID ORDER BY timestamp DESC LIMIT 10 ");
    query.exec();

    int row=0;
    while(query.next()){
        ui->recentTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // isbn
        ui->recentTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // name
        ui->recentTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // genre
        ++row;
    }
    ui->recentTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->recentTable->hideColumn(0);
}

void Glybook::fillBookmarkWidget(){
    QSqlQuery query;
    query.prepare("SELECT books.name, bookID FROM `b_bookmarks` INNER JOIN books ON books.ISBN = b_bookmarks.bookID WHERE userID=:user");
    query.bindValue(":user", connectedUser->getUser());
    query.exec();
    while(query.next()){
    ui->bookmarksList->addItem(query.value(0).toString()+" (ISBN: "+query.value(1).toString()+")");
    }
}

void Glybook::on_catalogButton_clicked()
{
    Catalog *catalog = new Catalog(*connectedUser);
    catalog->show();
}

// ouvre un formulaire pour ajouter un nouveau livre
void Glybook::on_actionAddBook_triggered()
{
    bookDialog *dialog = new bookDialog("");
    dialog->setModal(true);
    dialog->show();
}

// ouvre une page de gestion d'utilisateurs
void Glybook::on_actionManageAcc_triggered()
{
    manageAccounts *ma = new manageAccounts(*connectedUser);
    ma->show();
}

void Glybook::on_actionStatistics_triggered()
{
    qDebug() << "Ajout prochain!";
}

void Glybook::on_actionMyAccount_triggered()
{
   myAccount *showAccount = new myAccount(*connectedUser, connectedUser->getUser());
   showAccount->show();
}

void Glybook::on_action_bookReservationsHistory_triggered()
{
    accountHistory *history;
    if(connectedUser->getType()==1)
        history = new accountHistory(*connectedUser);
    else
        history = new accountHistory(*connectedUser, connectedUser->getUser());
    history->show();
}

void Glybook::on_actionSettings_triggered()
{
    settings *settingsPage = new settings();
    settingsPage->show();
}

void Glybook::on_actionLogout_triggered()
{
    Login *logout = new Login();
    logout->show();
    this->close();
}

Glybook::~Glybook()
{
    db.close();
    delete connection;
    delete connectedUser;

    delete ui;
}


void Glybook::on_bookingTable_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    accountHistory *history = new accountHistory(*connectedUser, ui->bookingTable->item(row, 3)->text());
    history->show();
}

void Glybook::on_recentTable_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    bookInformation *book = new bookInformation(*connectedUser, ui->recentTable->item(row, 0)->text());
    book->show();
}

void Glybook::on_bookmarksList_doubleClicked(const QModelIndex &index)
{
    QStringList splitIsbn = ui->bookmarksList->item(index.row())->text().split("(ISBN: ");
    QString isbn = splitIsbn[1].remove(")");

    bookInformation *bookmarked = new bookInformation(*connectedUser, isbn);
    bookmarked->show();
}
