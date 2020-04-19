#include "catalog.h"
#include "ui_catalog.h"

Catalog::Catalog(const User &connected, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Catalog), connected(connected)
{
    ui->setupUi(this);

    setFixedSize(800, 750);
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    displayBookList(0);

}

Catalog::~Catalog()
{
    delete ui;
}

//affiche la liste des livres disponibles
void Catalog::displayBookList(int checked){
    // amélioration: ajouter la recherche par auteur ou par genre
    QSqlQuery q;
    if(checked==0){
        q.exec("SELECT count(ISBN) FROM books WHERE booked=0 "+search);
        q.first();
        ui->tableWidget->setRowCount(q.value(0).toInt());
        q.exec("SELECT ISBN, books.name, b_author.name, b_genre.name, b_publisher.name, year_publication, summary FROM books INNER JOIN b_author ON b_author.authorID = books.authorID INNER JOIN b_publisher ON b_publisher.publisherID = books.publisherID INNER JOIN b_genre ON b_genre.genreID = books.genreID WHERE booked=0 "+search);
    }
    else{
        search.replace("AND", "WHERE");
        q.exec("SELECT count(ISBN) FROM books "+search);
        q.first();
        ui->tableWidget->setRowCount(q.value(0).toInt());
        q.exec("SELECT ISBN, books.name, b_author.name, b_genre.name, b_publisher.name, year_publication, summary FROM books INNER JOIN b_author ON b_author.authorID = books.authorID INNER JOIN b_publisher ON b_publisher.publisherID = books.publisherID INNER JOIN b_genre ON b_genre.genreID = books.genreID "+search);

    }
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
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // aggrandit la colonne nom pour prendre toute la place restante
}

// gestion de l'appui sur delete pour supprimer la cellule selectionnée (uniquement pour les admins)
void Catalog::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Delete && connected.getType()==1){
        int row = ui->tableWidget->currentRow();
        int answer = QMessageBox::warning(this, "Delete a book", "Are you sure to delete "+ui->tableWidget->item(row, 1)->text()+"?", QMessageBox::Yes | QMessageBox::No);
        if(answer == QMessageBox::Yes){
            QSqlQuery deleteBook("DELETE FROM books WHERE isbn = '"+ui->tableWidget->item(row, 0)->text()+"'");
            if(deleteBook.exec()){
                QMessageBox::information(this, "Success!", "The book "+ui->tableWidget->item(row, 1)->text()+" has been successfully deleted!");
                ui->tableWidget->clearContents();
                displayBookList(0);
                emit refresh(true);
            }
        }
    }
}

// actions lorsqu'on double clic sur un element du tableau
void Catalog::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    bookInformation *info = new bookInformation(connected, ui->tableWidget->item(row, 0)->text());
    info->show();
    connect(info, SIGNAL(refresh(bool)), this, SLOT(refreshSlot(bool)));
}

// actions quand la checkbox change d'etat
// remet a zero la liste des livres et la barre de recherche
void Catalog::on_checkBox_stateChanged(int state)
{
    displayBookList(state);
    ui->searchBar->clear();
}

// actions quand quelquechose est entré dans la barre de recherche
// recherche dynamiquement dans tous les titres si ils correspondent a la recherche
// si la barre de recherche est vide le tableau est remis à son etat normal
void Catalog::on_searchBar_textChanged(const QString &text)
{
    if(!(text=="")){
        search="AND books.name LIKE '%"+text+"%'";
        ui->tableWidget->clearContents();
        displayBookList(ui->checkBox->isChecked());
    }
    else{
        search=text;
        ui->tableWidget->clearContents();
        displayBookList(ui->checkBox->isChecked());
    }
}

// actions quand on recoit un signal refresh
void Catalog::refreshSlot(bool b){
    if(b){
        // on signale qu'il y a une modification et que la page principale doit etre raffraichie
        emit refresh(true);
    }
}
