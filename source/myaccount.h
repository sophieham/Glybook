#ifndef MYACCOUNT_H
#define MYACCOUNT_H

#include <QWidget>
#include <QtSql>

#include "user.h"
#include "accountdialog.h"
#include "accounthistory.h"

namespace Ui {
class myAccount;
}

class myAccount : public QWidget
{
    Q_OBJECT

public:
    explicit myAccount(const User &connected, const QString &user = NULL, QWidget *parent = nullptr);
    ~myAccount();

signals:
    void refresh(bool);

private slots:
    void on_modifyButton_clicked();

    void on_closeButton_clicked();

    void on_historyButton_clicked();

    void prepareAccount();

    void displayAccount();

    void refreshSlot(bool);

private:
    Ui::myAccount *ui;

    User connected;
    QString user;
    User account;

    int id;
};

#endif // MYACCOUNT_H
