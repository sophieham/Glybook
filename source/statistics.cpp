#include "statistics.h"
#include "ui_statistics.h"

Statistics::Statistics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Statistics)
{
    ui->setupUi(this);
    setFixedSize(630, 530);
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
}

Statistics::~Statistics()
{
    delete ui;
}

// affiche les données du tableau en fonction de ce qui a été sélectionné
void Statistics::displayList(const QString &selected){
    if(selected=="reservations"){
        ui->title->setText("The 10 most booked");
    }
    else if(selected=="b_bookmarks"){
        ui->title->setText("The 10 most bookmarked");
    }

    QSqlQuery query;
    ui->statisticsTable->setRowCount(10);
    query.exec("SELECT name, count(name) FROM books INNER JOIN "+selected+" ON ISBN = bookID GROUP BY name ORDER BY `count(name)` DESC ");
    int row = 0;
    for(query.first(); query.isValid(); query.next(), ++row){
        ui->statisticsTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // name
        ui->statisticsTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
    }
    ui->statisticsTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

}

// exporte les données du tableau sous forme de csv ou de txt
void Statistics::on_exportButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Export", "Statistics ("+QDate::currentDate().toString("dd-MM-yyyy")+")", "CSV files (.csv);;Text files (*.txt);;Any Files (*)", 0, 0); // getting the filename (full path)
    if(!filename.isNull()){
        QFile data(filename);
        if(data.open(QFile::WriteOnly |QFile::Truncate))
        {
            int row=0;
            QTextStream out(&data);
            QString columnName = ui->statisticsTable->horizontalHeaderItem(0)->text()+";"+ui->statisticsTable->horizontalHeaderItem(1)->text()+"\n";
            out << columnName;
            while (row < ui->statisticsTable->rowCount()) {
                QString information = ui->statisticsTable->item(row, 0)->text()+";"+ui->statisticsTable->item(row, 1)->text()+"\n";
                out << information;
                ++row;
            }
            QMessageBox::information(this, "Success!", "Statistics data has been exported!");
        }
    }

}

void Statistics::on_closeButton_clicked()
{
    this->close();
}

// prend en compte les changements de la barre de choix et définit les données a afficher dans le tableau
void Statistics::on_comboBox_currentIndexChanged(int index)
{
    ui->statisticsTable->clearContents();
    if(index==1){
        displayList("reservations");
    }
    if(index==2){
        displayList("b_bookmarks");
    }
}
