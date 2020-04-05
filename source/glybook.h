#ifndef GLYBOOK_H
#define GLYBOOK_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>

#include "dbconnection.h"
#include "user.h"
#include "book.h"
#include "reservation.h"
#include "manageaccounts.h"

namespace Ui {
class Glybook;
}

class Glybook : public QMainWindow
{
    Q_OBJECT

public:
    explicit Glybook(const QString &name, QWidget *parent = nullptr);
    ~Glybook();

    void setupAccount();
    void displayBookList();

private slots:
    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_actionAddBook_triggered();

    void on_actionManageAcc_triggered();

    void on_actionStatistiques_triggered();

    void on_actionLogout_triggered();

    void on_actionMyAccount_triggered();

    void on_actionSettings_triggered();

private:
    Ui::Glybook *ui;
    dbconnection *connection;
    QSqlDatabase db;
    QSqlTableModel *bookList;

    QString username;
    User *connectedUser;
    Book *book;
    Reservation *resv;

    manageAccounts *ma;
};

#endif // GLYBOOK_H
