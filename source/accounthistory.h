#ifndef ACCOUNTHISTORY_H
#define ACCOUNTHISTORY_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

#include <QFile>
#include <QFileDialog>
#include <QDesktopServices>

#include "bookdialog.h"
#include "myaccount.h"
#include "bookinformation.h"

namespace Ui {
class accountHistory;
}

class accountHistory : public QWidget
{
    Q_OBJECT

public:
    explicit accountHistory(const User &connected, const QString &user=NULL, QWidget *parent = nullptr);
    ~accountHistory();

    void displayHistory();

signals:
    void refresh(bool);

private slots:
    void on_reservationView_cellDoubleClicked(int row, int column);

    void on_exportButton_clicked();

    void on_closeButton_clicked();

    void refreshSlot(bool);

private:
    Ui::accountHistory *ui;

    User connected;
    QString user;
};

#endif // ACCOUNTHISTORY_H
