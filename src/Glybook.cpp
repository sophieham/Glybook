#include "glybook.h"
#include "ui_glybook.h"
#include "connection.h"

Glybook::Glybook(const QString &name, QWidget *parent) : QMainWindow(parent), ui(new Ui::Glybook), username(name)
{
    ui->setupUi(this);
    setFixedSize(1400, 800);
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    setupLibrary();
    setupAccount();
    ui->lbl_connected->setText("Connected: "+connectedUser->getUser());

    if(connectedUser->getType()==0)
      ui->menuAdmin->menuAction()->setVisible(false); // cache le menu admin

    fillBookingWidget();
    fillRecentWidget();
    fillBookmarkWidget();

    checkBookings();
}

Glybook::~Glybook()
{
    db.close();
    delete connection;
    delete connectedUser;

    delete ui;
}

// modifie le message d'accueil & celui des news avec ceux enregistrés dans la bdd
void Glybook::setupLibrary(){
    library = new Library();

    QSqlQuery query;
    query.exec("SELECT * FROM settings");
    query.last();

    library->setName(query.value(1).toString());
    library->setType(query.value(3).toString());
    library->setAddress(query.value(2).toString());

    ui->message->setText(query.value(4).toString());
    ui->title->setText(library->getName()+" "+library->getType()+" library");
    ui->address->setText(library->getAddress());

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

// vérifie si des réservations/emprunts se sont terminés depuis la dernière ouverture du programme et remet les livres disponibles
// on suppose que les livres n'ont jamais été réclamés/pas empruntés si la reservation se termine
// pareil pour simplifier on suppose que les emprunteurs ne rendent jamais les livres en retard
void Glybook::checkBookings(){
    QSqlQuery check;
    check.exec("SELECT bookID FROM `reservations` WHERE end_date<CURRENT_DATE AND checked=0");

    while(check.next()){
        QSqlQuery q;
        q.exec("UPDATE books SET `booked` = 0 WHERE books.ISBN = "
               "(SELECT bookID FROM `reservations` WHERE end_date < CURRENT_DATE LIMIT 1);"
               "UPDATE reservations SET checked=1 WHERE end_date<CURRENT_DATE");
    }

    check.exec("SELECT isbn FROM `loans` WHERE return_date<CURRENT_DATE AND checked=0");
    while(check.next()){
        QSqlQuery q;
        q.exec("UPDATE books SET `booked` = 0 WHERE books.ISBN = "
               "(SELECT bookID FROM `loans` WHERE end_date < CURRENT_DATE LIMIT 1);"
               "UPDATE loans SET checked=1 WHERE end_date<CURRENT_DATE");
    }
}

// ouvre le catalogue des livres
void Glybook::on_catalogButton_clicked()
{
    Catalog *catalog = new Catalog(*connectedUser);
    catalog->show();
    connect(catalog, SIGNAL(refresh(bool)), this, SLOT(refresh(bool)));
}

// affiche les 3 dernières réservations de livres
void Glybook::fillBookingWidget(){
    ui->bookingTable->verticalHeader()->setVisible(false);
    ui->bookingTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
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
        ui->bookingTable->setRowCount(row+1);
        ui->bookingTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // isbn
        ui->bookingTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // name
        ui->bookingTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // date de fin de reservation
        ui->bookingTable->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // username (caché)
        ++row;
    }

}

// affiche l'historique des réservations lors du double clique sur une réservation
void Glybook::on_bookingTable_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    // ouvre l'historique de l'utilisateur en question
    accountHistory *history = new accountHistory(*connectedUser, ui->bookingTable->item(row, 3)->text());
    history->show();
    connect(history, SIGNAL(refresh(bool)), this, SLOT(refresh(bool)));
}

// remplit le tableau avec les 10 derniers ajouts de livres
void Glybook::fillRecentWidget(){
    ui->recentTable->verticalHeader()->setVisible(false);
    ui->recentTable->setRowCount(12);
    QSqlQuery query;
    query.exec("SELECT ISBN, books.name, b_genre.name FROM `books` INNER JOIN b_genre ON b_genre.genreID = books.genreID ORDER BY timestamp DESC LIMIT 12 ");

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

// ouvre une page d'information à propos du livre qui a été double cliqué
void Glybook::on_recentTable_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    bookInformation *book = new bookInformation(*connectedUser, ui->recentTable->item(row, 0)->text());
    book->show();
    connect(book, SIGNAL(refresh(bool)), this, SLOT(refresh(bool)));
}


// remplit le tableau des favoris de l'utilisateur connecté
void Glybook::fillBookmarkWidget(){
    QSqlQuery query;
    query.prepare("SELECT books.name, bookID FROM `b_bookmarks` INNER JOIN books ON books.ISBN = b_bookmarks.bookID WHERE userID=:user");
    query.bindValue(":user", connectedUser->getUser());
    query.exec();
    while(query.next()){
    ui->bookmarksList->addItem(query.value(0).toString()+" (ISBN: "+query.value(1).toString()+")");
    }
}

// ouvre une page d'info sur le livre double cliqué
void Glybook::on_bookmarksList_doubleClicked(const QModelIndex &index)
{
    QStringList splitIsbn = ui->bookmarksList->item(index.row())->text().split("(ISBN: ");
    QString isbn = splitIsbn[1].remove(")");

    bookInformation *bookmarked = new bookInformation(*connectedUser, isbn);
    bookmarked->show();
    connect(bookmarked, SIGNAL(refresh(bool)), this, SLOT(refresh(bool)));
}

// ouvre un formulaire pour ajouter un nouveau livre
void Glybook::on_actionAddBook_triggered()
{
    bookDialog *dialog = new bookDialog("");
    dialog->setModal(true);
    dialog->show();
    connect(dialog, SIGNAL(refresh(bool)), this, SLOT(refresh(bool)));
}

// ouvre un formulaire pour ajouter un nouveau livre
void Glybook::on_actionNewLoan_triggered()
{
    LoanDialog *dialog = new LoanDialog();
    dialog->show();
}

// ouvre une page de gestion d'utilisateurs
void Glybook::on_actionManageAcc_triggered()
{
    manageAccounts *ma = new manageAccounts(*connectedUser);
    ma->show();
}

// ouvre la page statistiques dans le menu
void Glybook::on_actionStatistics_triggered()
{
    Statistics *statsPage = new Statistics();
    statsPage->show();
}

// ouvre la page "my account" dans le menu
void Glybook::on_actionMyAccount_triggered()
{
   myAccount *showAccount = new myAccount(*connectedUser, connectedUser->getUser());
   showAccount->show();
}

// ouvre la page "historique" dans le menu
void Glybook::on_action_bookReservationsHistory_triggered()
{
    accountHistory *history;
    if(connectedUser->getType()==1)
        history = new accountHistory(*connectedUser);
    else
        history = new accountHistory(*connectedUser, connectedUser->getUser());
    history->show();
    connect(history, SIGNAL(refresh(bool)), this, SLOT(refresh(bool)));
}

// ouvre la page settings dans le menu
void Glybook::on_actionSettings_triggered()
{
    settings *settingsPage = new settings();
    settingsPage->show();
    connect(settingsPage, SIGNAL(refresh(bool)), this, SLOT(refresh(bool)));
}

// ferme la page et ouvre une page connexion
void Glybook::on_actionLogout_triggered()
{
    Login *logout = new Login();
    logout->show();
    this->close();
}

// rafraichit les differents élements de la page
void Glybook::refresh(bool b){
    if(b){
        setupLibrary();
        ui->bookmarksList->clear();
        fillBookmarkWidget();
        ui->bookingTable->clearContents();
        fillBookingWidget();
        ui->recentTable->clearContents();
        fillRecentWidget();
    }
}
