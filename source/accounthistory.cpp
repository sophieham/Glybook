#include "accounthistory.h"
#include "ui_accounthistory.h"

accountHistory::accountHistory(const int &id, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::accountHistory), id(id)
{
    ui->setupUi(this);
}

accountHistory::~accountHistory()
{
    delete ui;
}
