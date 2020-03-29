#include "glybook.h"
#include "ui_glybook.h"

Glybook::Glybook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Glybook)
{
    ui->setupUi(this);
}

Glybook::~Glybook()
{
    delete ui;
}
