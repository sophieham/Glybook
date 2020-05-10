#ifndef GLYBOOK_H
#define GLYBOOK_H

#include <QMainWindow>

#include "dbconnection.h"
#include "user.h"
#include "manageaccounts.h"
#include "bookdialog.h"
#include "accounthistory.h"
#include "myaccount.h"
#include "bookinformation.h"
#include "catalog.h"
#include "settings.h"
#include "statistics.h"

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
    void setupLibrary();
    void checkBookings();
    void fillBookingWidget();
    void fillRecentWidget();
    void fillBookmarkWidget();

private slots:
    void on_actionAddBook_triggered();

    void on_actionManageAcc_triggered();

    void on_actionLogout_triggered();

    void on_actionMyAccount_triggered();

    void on_actionSettings_triggered();

    void on_actionStatistics_triggered();

    void on_action_bookReservationsHistory_triggered();

    void on_catalogButton_clicked();
    
    void on_bookingTable_doubleClicked(const QModelIndex &index);

    void on_recentTable_doubleClicked(const QModelIndex &index);

    void on_bookmarksList_doubleClicked(const QModelIndex &index);

    void refresh(bool);

private:
    Ui::Glybook *ui;
    dbconnection *connection;
    QSqlDatabase db;

    int id;
    QString username;
    User *connectedUser;

    Library *library;

};

#endif // GLYBOOK_H
