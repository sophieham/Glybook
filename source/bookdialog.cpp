#include "bookdialog.h"
#include "ui_bookdialog.h"

bookDialog::bookDialog(const QString &isbn, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::bookDialog), id(isbn)
{
    ui->setupUi(this);
    displayBookData();
}

bookDialog::~bookDialog()
{
    delete ui;
}

// remplit le formulaire notamment la liste des auteurs, editeurs & genres
void bookDialog::displayBookData(){
    // on remplit chaque combo box
    QSqlQuery authorQuery("SELECT name FROM b_author ORDER BY name");
    while (authorQuery.next()){
        ui->authorList->addItem(authorQuery.value(0).toString());
    }

    QSqlQuery publisherQuery("SELECT name FROM b_publisher ORDER BY name");
    while (publisherQuery.next()){
        ui->publisherList->addItem(publisherQuery.value(0).toString());
    }

    QSqlQuery genreQuery("SELECT name FROM b_genre ORDER BY name");
    while (genreQuery.next()){
        ui->genreList->addItem(genreQuery.value(0).toString());
    }

    QSqlQuery displayQry("SELECT * FROM books WHERE isbn='"+id+"'");
    if(displayQry.next()){
        ui->send_pushButton->setText("Apply changes");
        ui->isbnLineEdit->setText(id);
        ui->isbnLineEdit->setEnabled(false);
        ui->nameLineEdit->setText(displayQry.value(1).toString());
        ui->authorList->setCurrentText(displayQry.value(2).toString());
        ui->publicationYearLineEdit->setText(displayQry.value(5).toString());
        ui->summaryTextEdit->setPlainText(displayQry.value(6).toString());
    }
}

// détermine si il s'agit d'une modification ou d'un ajout et envoie les données à la bdd
void bookDialog::on_send_pushButton_clicked()
{
    int booked=1;
    if(ui->freeCheckBox->isChecked())
        booked=0;

    if(ui->authorList->currentIndex() >= 2 && ui->publisherList->currentIndex() >= 2 && ui->genreList->currentIndex() >= 2){
        if(ui->send_pushButton->text()=="Apply changes"){
            QSqlQuery modifyQuery;
            modifyQuery.prepare("SELECT @id_author := authorID FROM b_author WHERE b_author.name= :author;"
                                "SELECT @id_publisher := publisherID FROM b_publisher WHERE b_publisher.name = :publisher; "
                                "SELECT @id_genre := genreID FROM b_genre WHERE b_genre.name = :genre; "
                                "UPDATE `books` SET `name`=:name, `authorID`= @id_author, `publisherID`= @id_publisher, `genreID`= @id_genre, `year_publication`= :year, `summary`= :summary, `booked`= :free WHERE isbn=:isbn");
            modifyQuery.bindValue(":isbn", id);
            modifyQuery.bindValue(":name", ui->nameLineEdit->text());
            modifyQuery.bindValue(":author", ui->authorList->currentText());
            modifyQuery.bindValue(":publisher", ui->publisherList->currentText());
            modifyQuery.bindValue(":genre", ui->genreList->currentText());
            modifyQuery.bindValue(":year", ui->publicationYearLineEdit->text());
            modifyQuery.bindValue(":summary", ui->summaryTextEdit->toPlainText());
            modifyQuery.bindValue(":free", booked);
            if(modifyQuery.exec()){
                QMessageBox::information(this, "Success", "Book has been modified!");
                this->close();
            }
        }
        if(ui->send_pushButton->text()=="Add a new book" && !(ui->nameLineEdit->text().isEmpty() && ui->publicationYearLineEdit->text().isEmpty())){
            QSqlQuery addQuery;
            addQuery.prepare("SELECT @id_author := authorID FROM b_author WHERE b_author.name=:author; "
                             "SELECT @id_publisher := publisherID FROM b_publisher WHERE b_publisher.name = :publisher; "
                             "SELECT @id_genre := genreID FROM b_genre WHERE b_genre.name = :genre; "
                             "INSERT INTO `books`(`ISBN`, `name`, `authorID`, `publisherID`, `genreID`, `year_publication`, `summary`, `booked`, `timestamp`) VALUES (:isbn, :name ,@id_author, @id_publisher, @id_genre, :year, :summary, :free, current_timestamp())");
            addQuery.bindValue(":isbn", ui->isbnLineEdit->text());
            addQuery.bindValue(":name", ui->nameLineEdit->text());
            addQuery.bindValue(":author", ui->authorList->currentText());
            addQuery.bindValue(":publisher", ui->publisherList->currentText());
            addQuery.bindValue(":genre", ui->genreList->currentText());
            addQuery.bindValue(":year", ui->publicationYearLineEdit->text());
            addQuery.bindValue(":summary", ui->summaryTextEdit->toPlainText());
            addQuery.bindValue(":free", booked);
            if(addQuery.exec()){
                QMessageBox::information(this, "Success", "Book has been added!");
                this->close();
                emit refresh(true);
            }
        }
    }
    else{
        QMessageBox::warning(this, "Error!", "Please fill all the fields!");
    }
}

// actions lorsque "ajouter un nouvel auteur" est sélectionné
void bookDialog::on_authorList_activated(int index)
{
    if(index==1){
        QString text = QInputDialog::getText(this, "QInputDialog::getText()", "Author name:", QLineEdit::Normal, "");
        if (!text.isEmpty()){
            QSqlQuery addToDb;
            addToDb.prepare("INSERT INTO `b_author` (`authorID`, `name`) VALUES (NULL, :name)");
            addToDb.bindValue(":name", text);
            if(addToDb.exec()){
                ui->authorList->clear();
                displayBookData();
                QMessageBox::information(this, "Author added!", "New author added! You can choose it now.");
            }
        }
        else{
            QMessageBox::warning(this, "Error!", "Please fill all the fields!");
        }
    }
}

// actions lorsque "ajouter un nouvel editeur" est sélectionné
void bookDialog::on_publisherList_activated(int index)
{
    if(index==1){
        QString text = QInputDialog::getText(this, "QInputDialog::getText()", "Publisher name:", QLineEdit::Normal, "");
        if (!text.isEmpty()){
            QSqlQuery addToDb;
            addToDb.prepare("INSERT INTO `b_publisher` (`publisherID`, `name`) VALUES (NULL, :name)");
            addToDb.bindValue(":name", text);
            if(addToDb.exec()){
                ui->publisherList->clear();
                displayBookData();
                QMessageBox::information(this, "Publisher added!", "New publisher added! You can choose it now.");
            }
        }
        else{
            QMessageBox::warning(this, "Error!", "Please fill all the fields!");
        }
    }
}

// actions lorsque "ajouter un nouveau genre" est sélectionné
void bookDialog::on_genreList_activated(int index)
{
    if(index==1){
        QString text = QInputDialog::getText(this, "QInputDialog::getText()", "Genre name:", QLineEdit::Normal, "");
        if (!text.isEmpty()){
            QSqlQuery addToDb;
            addToDb.prepare("INSERT INTO `b_genre` (`genreID`, `name`) VALUES (NULL, :name)");
            addToDb.bindValue(":name", text);
            if(addToDb.exec()){
                ui->genreList->clear();
                displayBookData();
                QMessageBox::information(this, "Genre added!", "New genre added! You can choose it now.");
            }
        }
        else{
            QMessageBox::warning(this, "Error!", "Please fill all the fields!");
        }
    }
}

void bookDialog::on_close_pushButton_clicked()
{
    this->close();
}
