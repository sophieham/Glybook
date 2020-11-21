#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);

    setFixedSize(830, 430);
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    fillForm();
}

settings::~settings()
{
    delete ui;
}

// rempli le formulaire avec les paramètres enrengistrés sur la base de données
void settings::fillForm(){
    QSqlQuery query;
    query.exec("SELECT * FROM settings");
    query.last(); // ne prend que la dernière modification
    ui->libraryNameLineEdit->setText(query.value(1).toString());
    ui->addressLineEdit->setText(query.value(2).toString());
    ui->typeComboBox->setLineEdit(new QLineEdit(query.value(3).toString()));
    ui->changeNewsTextEdit->setPlainText(query.value(4).toString());
}

// actions lors du clic sur le bouton "save"
// sauvegarde de nouveaux parametres dans la base de donnée
// envoie un signal pour rafraichir le tableau de bord
void settings::on_saveButton_clicked()
{
    if(!((ui->libraryNameLineEdit->text().isEmpty() && ui->addressLineEdit->text().isEmpty()) || ui->typeComboBox->currentIndex()==0)){
        QSqlQuery update;
        update.prepare("INSERT INTO settings VALUES(current_timestamp(), :name, :address, :type, :message)");
        update.bindValue(":name", ui->libraryNameLineEdit->text());
        update.bindValue(":address", ui->addressLineEdit->text());
        update.bindValue(":type", ui->typeComboBox->currentText());
        update.bindValue(":message", ui->changeNewsTextEdit->toPlainText());
        if(update.exec()){
            QMessageBox::information(this, "Success!", "Settings have been saved!");
            emit refresh(true);
        }
        else {
            QMessageBox::critical(this, "Error...", "Data couldn't be saved. Retry later.");
        }
    }
    else QMessageBox::critical(this, "Error!", "Please fill all the fields");
}

// actions quand un élément de la liste deroulante a été séléctionné
void settings::on_comboBox_currentIndexChanged(const QString &selected)
{
    fillTable(selected);
}

// rempli le tableau en fonction du type de données qui a été séléctionné
void settings::fillTable(const QString &selected){
    QString type=selected;
    if(selection.indexOf("_")==-1){
        type.prepend("b_");
    }
    selection = selected;

    QSqlQuery query;
    query.exec("SELECT COUNT(name) FROM "+type);
    query.first();
    ui->tableWidget->setRowCount(query.value(0).toInt());

    int row=0;
    query.exec("SELECT name FROM "+type);
    while(query.next()){
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ++row;
    }
}

// supprime la cellule séléctionnée en appuyant sur la touche "Delete"
// ne peut supprimer uniquement une donnée qui n'a pas été utilisée
void settings::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Delete){
        int row = ui->tableWidget->currentRow();
        QString name = ui->tableWidget->item(row, 0)->text();
        int answer = QMessageBox::warning(this, "Delete?", "Are you sure to delete "+name+"?\nNote that you can only delete a name who isn't used.", QMessageBox::Yes | QMessageBox::No);
        if(answer == QMessageBox::Yes){
            QString table = selection;
            table.prepend("b_");
            QSqlQuery deleteBook("DELETE FROM "+table+" WHERE name = '"+name+"'");
            if(deleteBook.exec()){
                QMessageBox::information(this, "Success!", name+" has been successfully deleted!");
                ui->tableWidget->clearContents();
                fillTable(selection);
            }
            else{
                QMessageBox::critical(this, "Error", "Cannot delete "+name+", delete the related books and try again.");
            }
        }
    }
}
