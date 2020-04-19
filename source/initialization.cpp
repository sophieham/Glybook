#include "initialization.h"
#include "ui_initialization.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setFixedSize(400, 300);
}

Dialog::~Dialog()
{
    delete ui;
}

// action quand le bouton "save" est cliqué
// envoie les données a la page de connexion pour etablir la premiere connexion
void Dialog::on_pushButton_clicked()
{
    QStringList data;
    data.append(ui->txtF_NameA->text());
    data.append(ui->txtL_NameA->text());
    data.append(ui->txtUserA->text());
    data.append(ui->txtPassA->text());
    emit sendFirstData(data);

}

