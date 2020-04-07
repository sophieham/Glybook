#include "glybook.h"
#include "ui_glybook.h"
#include "connection.h"
#include <QPushButton>
#include <QWidget>
#include <QKeyEvent>

Glybook::Glybook(const QString &name, QWidget *parent) : QMainWindow(parent), ui(new Ui::Glybook), username(name)
{
    ui->setupUi(this);
    setFixedSize(1400, 800);
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    setupAccount();
    ui->lbl_connected->setText("Connected: "+connectedUser->getUser());

    displayBookList();

    if(connectedUser->getType()==0)
      ui->menuAdmin->menuAction()->setVisible(false); // cache le menu admin

}

// récupère le nom d'utilisateur entré et prépare un objet utilisateur avec les données de son compte
void Glybook::setupAccount(){
    QSqlQuery dbSession;
    dbSession.prepare("SELECT * FROM `users` LEFT JOIN u_subscriber ON users.username = u_subscriber.subscriber_username WHERE username = :user ");
    dbSession.bindValue(":user", username);
    dbSession.exec();

    connectedUser = new User();

    if(dbSession.next()){
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

//affiche la liste des livres disponibles
void Glybook::displayBookList(){
    // amélioration: barre de recherche par nom/auteur et tri par catégorie
    // mettre a jour le tableau une fois les actions faites
    QSqlQuery q(db);
    q.exec("SELECT count(ISBN) FROM books WHERE free=1");
    q.first();
    ui->tableWidget->setRowCount(q.value(0).toInt());
    q.exec("SELECT ISBN, books.name, b_author.name, b_genre.name, b_publisher.name, year_publication, summary FROM books INNER JOIN b_author ON b_author.authorID = books.authorID INNER JOIN b_publisher ON b_publisher.publisherID = books.publisherID INNER JOIN b_genre ON b_genre.genreID = books.genreID WHERE free=1");
    int row = 0;

    for(q.first(); q.isValid(); q.next(), ++row){
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(q.value(0).toString())); // isbn
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(q.value(1).toString())); // name
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(q.value(2).toString())); // author
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(q.value(3).toString())); // genre
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(q.value(4).toString())); // publisher
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(q.value(5).toString())); // year
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(q.value(6).toString())); // summary
    }
    ui->tableWidget->hideColumn(6); // cache la colonne summary (contenu trop gros)
}

Glybook::~Glybook()
{
    db.close();
    delete connection;
    delete connectedUser;

    delete ui;
}

// gestion de l'appui sur delete pour supprimer un livre du tableau (uniquement pour les admins)
void Glybook::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete && connectedUser->getType()==1){ // si on appuie sur delete et qu'on est admin
        int row = ui->tableWidget->currentRow();
        int answer = QMessageBox::warning(this, "Delete a book", "Are you sure to delete "+ui->tableWidget->item(row, 1)->text()+"?", QMessageBox::Yes | QMessageBox::No);
        if(answer == QMessageBox::Yes){
            QSqlQuery deleteBook("DELETE FROM books WHERE isbn = '"+ui->tableWidget->item(row, 0)->text()+"'");
            if(deleteBook.exec()){
                QMessageBox::information(this, "Success!", "The book "+ui->tableWidget->item(row, 1)->text()+" has been successfully deleted!");
                ui->tableWidget->clearContents();
                displayBookList();
            }
        }
    }
}

// actions lorsqu'on double clic sur un element du tableau
void Glybook::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    book.setIsbn(ui->tableWidget->item(row, 0)->text());
    book.setName(ui->tableWidget->item(row, 1)->text());
    book.setAuthor(ui->tableWidget->item(row, 2)->text());
    book.setGenre(ui->tableWidget->item(row, 3)->text());
    book.setPublisher(ui->tableWidget->item(row, 4)->text());
    book.setYear(ui->tableWidget->item(row, 5)->text().toInt());
    book.setSummary(ui->tableWidget->item(row, 6)->text());

    // affiche une page pour modifier le livre
    if(connectedUser->getType()==1){
        bookDialog dialog(book.getIsbn());
        dialog.setModal(true);
        dialog.show();
    }
    // affiche un resumé et la possiblité de emprunter si abonné
    else{
        // amélioration: ajouter une photo de la couverture?
        int answer = QMessageBox::question(this, "Emprunter "+book.getName(), "Summary:\n"+book.getSummary()+ "\n\nVoulez-vous réserver ce livre?", QMessageBox::Yes | QMessageBox::No);
        if(answer == QMessageBox::Yes){
            if (book.getFree() && (connectedUser->getLimit() > 0)) {
                //resv = new Reservation();
                resv.setLentBook(book);
                resv.setSubscriber(*connectedUser);
                resv.setEndDate(resv.getDatePlusDays(14));
                resv.setStartDate(resv.getDateNow());
                resv.addReservation();

                // mise à jour du tableau
                ui->tableWidget->clearContents();
                displayBookList();

                QMessageBox::information(this, "Success!", "Book reserved!");
            }
            else {
                QMessageBox::critical(this, "Erreur!", "Vous ne pouvez pas emprunter ce livre, il n'est plus disponible ou alors vous assez trop emprunté");
            }
        }
    }
}

// ouvre un formulaire pour ajouter un nouveau livre
void Glybook::on_actionAddBook_triggered()
{
    bookDialog bookDialog("");
    bookDialog.setModal(true);
    bookDialog.show();
}

// ouvre une page de gestion d'utilisateurs
void Glybook::on_actionManageAcc_triggered()
{
    ma.show();
}

void Glybook::on_actionMyAccount_triggered()
{
    qDebug() << "Ajout prochain! ";
}

void Glybook::on_actionStatistiques_triggered()
{
    qDebug() << "Ajout prochain! ";
}

void Glybook::on_actionSettings_triggered()
{
    qDebug() << "Ajout prochain! ";
}

void Glybook::on_actionLogout_triggered()
{
    Login *logout = new Login();
    logout->show();
    this->close();
}

