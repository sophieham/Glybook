#ifndef CONNEXION_H
#define CONNEXION_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QCryptographicHash>

#include "borrow.h"
#include "initialization.h"
#include "glybook.h"

QT_BEGIN_NAMESPACE
namespace Ui { class connexion; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

    QString hashPass(QString);

private slots:
    void receiveFirstData(QStringList);

    void on_btnConnect_clicked();

private:
    dbconnection connection;
    QSqlDatabase db;
    Ui::connexion *ui;

    //QString user;
};
#endif // connexion_H
