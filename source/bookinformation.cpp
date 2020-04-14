#include "bookinformation.h"
#include "ui_bookinformation.h"

bookInformation::bookInformation(const User &connected, const QString &isbn, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookInformation), connected(connected), isbn(isbn)
{
    ui->setupUi(this);
    displayBook();
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

    setButton();
}

bookInformation::~bookInformation()
{
    delete ui;
}

void bookInformation::setButton(){
    if(connected.getType()){
        ui->reserved->setEnabled(true);
        ui->reserveButton->setText("Modify");
    }
}

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
        qDebug() << query.value(6).toInt();
        book.setSummary(query.value(7).toString());
    }
    else{
        QSqlError e = query.lastError();
        qDebug() << e;
    }
}

void bookInformation::on_reserveButton_clicked()
{
    if(connected.getType()){
        bookDialog *bookdialog = new bookDialog(isbn);
        bookdialog->show();
    }
    else{
        int answer = QMessageBox::question(this, "Emprunter "+book.getName(), "\n\nVoulez-vous réserver ce livre?", QMessageBox::Yes | QMessageBox::No);
        if(answer == QMessageBox::Yes){
            if (!(book.isBooked()) && (connected.getLimit() > 0)) {
                resv.setLentBook(book);
                resv.setSubscriber(connected);
                resv.setEndDate(resv.getDatePlusDays(14));
                resv.setStartDate(resv.getDateNow());
                resv.addReservation();

                QMessageBox::information(this, "Success!", "Book reserved!");
            }
            else {
                QMessageBox::critical(this, "Erreur!", "Vous ne pouvez pas emprunter ce livre, il n'est plus disponible ou alors vous assez trop emprunté");
            }
        }
    }
}

void bookInformation::on_closeButton_clicked()
{
    this->close();
}

void bookInformation::on_bookmark_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO `b_bookmarks` (`favID`, `bookID`, `userID`, `timestamp`) VALUES (NULL, :isbn, :user, current_timestamp())");
    query.bindValue(":isbn", book.getIsbn());
    query.bindValue(":user", connected.getUser());
    if(query.exec())
        QMessageBox::information(this, "Add to favorite", "You have bookmarked this book");

}
