#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QCryptographicHash>

#include "reservation.h"
#include "initialization.h"
#include "glybook.h"
#include "cryptohashclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class connexion; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void receiveFirstData(QStringList);

    void on_btnConnect_clicked();

private:
    dbconnection connection;
    QSqlDatabase db;
    Ui::connexion *ui;

    Dialog *initialization;
    Glybook *page;
};
#endif // CONNECTION_H
