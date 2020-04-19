#include "bookinformation.h"
#include "ui_bookinformation.h"
#include <QIcon>

bookInformation::bookInformation(const User &connected, const QString &isbn, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookInformation), connected(connected), isbn(isbn)
{
    ui->setupUi(this);

    setFixedSize(650, 600);
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    displayBook();

    setButton();

    // change l'aspect du bouton "ajouter le livre aux favoris" si le livre est deja en favoris
    QSqlQuery query;
    query.exec("SELECT * FROM `b_bookmarks` WHERE bookID = '"+book.getIsbn()+"' AND userID = '"+connected.getUser()+"'");
    if(query.next()){
        ui->bookmark->setIcon(QIcon(":/icons/bookmarked.png"));
    }
}

bookInformation::~bookInformation()
{
    delete ui;
}

// défini la fonction du premier bouton
// "modifier le livre" pour un admin
// "reserver le livre" pour un abonné
void bookInformation::setButton(){
    if(connected.getType()){
        ui->reserved->setEnabled(true);
        ui->reserveButton->setText("Modify");
    }
}

// affiche les informations du livre a partir de la bdd
// si le livre est déjà réservé le bouton reserver est inutilisable
void bookInformation::displayBook(){
    QSqlQuery query;
    query.prepare("SELECT ISBN, books.name, b_author.name, b_genre.name, b_publisher.name, year_publication, booked, summary FROM books INNER JOIN b_author ON b_author.authorID = books.authorID INNER JOIN b_publisher ON b_publisher.publisherID = books.publisherID INNER JOIN b_genre ON b_genre.genreID = books.genreID WHERE isbn=:id");
    query.bindValue(":id", isbn);
    query.exec();
    if(query.first()){
        book.setIsbn(query.value(0).toString());
        book.setName(query.value(1).toString());
        book.setAuthor(query.value(2).toString());
        book.setGenre(query.value(3).toString());
        book.setPublisher(query.value(4).toString());
        book.setYear(query.value(5).toInt());
        book.setBooked(query.value(6).toInt());
        book.setSummary(query.value(7).toString());
    }
    else{
        QSqlError e = query.lastError();
        qDebug() << e;
    }

    ui->name->setText(book.getName());
    ui->author->setText(book.getAuthor());
    ui->editor->setText(book.getPublisher());
    ui->genre->setText(book.getGenre().getName());
    ui->year->setText(QString::number(book.getYear()));
    ui->summary->setPlainText(book.getSummary());
    if(book.isBooked()==1){ // pas libre
        ui->reserved->setText("Yes");
        ui->reserveButton->setEnabled(false);
    }
}

// actions lors de l'appui sur le bouton réserver
// commence une réservation pour 14 jours si l'utilisateur peut réserver
void bookInformation::on_reserveButton_clicked()
{
    if(connected.getType()){
        bookDialog *bookdialog = new bookDialog(isbn);
        bookdialog->show();
        connect(bookdialog, SIGNAL(refresh(bool)), this, SLOT(refreshSlot(bool)));
    }
    else{
        int answer = QMessageBox::question(this, "Booking "+book.getName(), "\n\nDo you want to book "+book.getName()+"?", QMessageBox::Yes | QMessageBox::No);
        if(answer == QMessageBox::Yes){
            if (!(book.isBooked()) && (connected.getLimit() > 0)) {
                resv.setLentBook(book);
                resv.setSubscriber(connected);
                resv.setEndDate(resv.getDatePlusDays(14));
                resv.setStartDate(resv.getDateNow());
                resv.addReservation();

                QMessageBox::information(this, "Success!", "Booked!");
                emit refresh(true);
            }
            else {
                QMessageBox::critical(this, "Erreur!", "You cannot book it, it is not available or you reach your booking limits");
            }
        }
    }
}

// actions lors du clic sur le bouton coeur en haut a droite
// ajoute un livre au favoris de l'utilisateur
// supprime le livre des favoris si il y etait deja
// affiche un message si tout s'est bien passé
void bookInformation::on_bookmark_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM `b_bookmarks` WHERE bookID = '"+book.getIsbn()+"' AND userID = '"+connected.getUser()+"'");
    if(query.next()){
        query.prepare("DELETE FROM `b_bookmarks` WHERE bookID= :book AND userID= :user");
        query.bindValue(":book", book.getIsbn());
        query.bindValue(":user", connected.getUser());
        ui->bookmark->setIcon(QIcon(":/icons/bookmark.png"));
        if(query.exec())
            QMessageBox::information(this, "Add to favorite", "You have delete this book from your bookmarks");

    }
    else{
        query.prepare("INSERT INTO `b_bookmarks` (`favID`, `bookID`, `userID`, `timestamp`) VALUES (NULL, :isbn, :user, current_timestamp())");
        query.bindValue(":isbn", book.getIsbn());
        query.bindValue(":user", connected.getUser());
        ui->bookmark->setIcon(QIcon(":/icons/bookmarked.png"));
        if(query.exec())
            QMessageBox::information(this, "Add to favorite", "You have bookmarked this book");   
    }

    // signale que les données ont été modifiés et qu'il faut recharger certaines pages
    emit refresh(true);
}


// actions a executer quand un signal est recu
void bookInformation::refreshSlot(bool b){
    if(b){
        displayBook();
    }
}

// ferme la page
void bookInformation::on_closeButton_clicked()
{
    this->close();
}
