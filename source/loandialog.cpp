#include "loandialog.h"
#include "ui_loandialog.h"

LoanDialog::LoanDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoanDialog)
{
    ui->setupUi(this);

    setFixedSize(680, 650);
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    displayBookList();
    displayUserList();

    // définit la cellule séléctionnée par défaut
    ui->tableUser->setCurrentCell(-1, 0);
    ui->tableBook->setCurrentCell(-1, 0);
}

LoanDialog::~LoanDialog()
{
    delete ui;
}

// Affiche le nom des livres dans un tableau
void LoanDialog::displayBookList(){
    QSqlQuery q;
    q.exec("SELECT count(*) FROM `books` "+searchBook);
    q.first();
    ui->tableBook->setRowCount(q.value(0).toInt());
    q.exec("SELECT name, isbn FROM `books` "+searchBook);
    int row = 0;
    for(q.first(); q.isValid(); q.next(), ++row){
        ui->tableBook->setItem(row, 0, new QTableWidgetItem(q.value(0).toString()));
        ui->tableBook->setItem(row, 1, new QTableWidgetItem(q.value(1).toString()));
    }
    ui->tableBook->hideColumn(1);
}

// Affiche les noms des utilisateurs dans un tableau
void LoanDialog::displayUserList(){
    QSqlQuery q;
    q.exec("SELECT count(*) FROM `users` "+searchUser);
    q.first();
    ui->tableUser->setRowCount(q.value(0).toInt());
    q.exec("SELECT concat(lastName, ' ', firstName) FROM `users` "+searchUser);
    int row = 0;
    for(q.first(); q.isValid(); q.next(), ++row){
        ui->tableUser->setItem(row, 0, new QTableWidgetItem(q.value(0).toString())); // isbn
    }
}

// barre de recherche des livres
// recherche le nom des livres en fonction de leur ISBN
void LoanDialog::on_searchBook_textChanged(const QString &text)
{
    if(!(text == "")){
        searchBook = "WHERE ISBN LIKE '%"+text+"%'";
        ui->tableBook->clearContents();
        displayBookList();
    }
    else{
        searchBook = text;
        ui->tableBook->clearContents();
        displayBookList();
    }
}
// barre de recherche d'utilisateur
// fonctionne avec un nom, un prenom ou les deux
void LoanDialog::on_searchUser_textChanged(const QString &text)
{
    if(!(text.isEmpty())){
        searchUser = "WHERE concat(lastName, ' ', firstName) LIKE '%"+text+"%'";
        ui->tableUser->clearContents();
        displayUserList();
    }
    else{
        searchUser = text;
        ui->tableUser->clearContents();
        displayUserList();
    }
}

/*
 * Clic sur le bouton confirm
 * Tente d'enregistrer le prêt dans la base de donnée
 * Affiche une boite de dialogue sinon
*/
void LoanDialog::on_confirmBttn_clicked()
{
    if(ui->tableBook->currentRow()>-1 && ui->tableUser->currentRow()>-1 ){
        QStringList name = ui->tableUser->currentItem()->text().split(" ");
        QSqlQuery qry("SELECT username FROM users WHERE lastName = '"+name[0]+"' AND firstName = '"+name[1]+"'");
        if(qry.exec()){
            qry.first();
            Book book;
            User user;

            // on précise l'identifiant du livre
            book.setIsbn(ui->tableBook->item(ui->tableBook->currentRow(), 1)->text());

            // on définit les informations nécessaires pour l'emprunteur
            user.setLastName(name[0]);
            user.setFirstName(name[1]);
            user.setUser(qry.value(0).toString());

            // on effectue le prêt
            Loan loan(user, book);
            qDebug() << ui->termSpinBox->value();
            loan.setEndDate(loan.getDatePlusDays(ui->termSpinBox->value()));
            loan.saveDb();
            QMessageBox::information(this, "Sucess!", "This loan has been added to the database!");
        }
        else {
            QMessageBox::critical(this, "Error!", "An error occured in the database");
        }
    }
    else {
        QMessageBox::critical(this, "Error!", "You must select both a book AND a name");
    }

}
