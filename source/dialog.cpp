#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QStringList data;
    data.append(ui->txtF_NameA->text());
    data.append(ui->txtL_NameA->text());
    data.append(ui->txtUserA->text());
    data.append(ui->txtPassA->text());
    emit sendFirstData(data);

}

