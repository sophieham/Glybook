#ifndef MANAGEACCOUNTS_H
#define MANAGEACCOUNTS_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>
#include <QKeyEvent>

#include "myaccount.h"

namespace Ui {
class manageAccounts;
}

class manageAccounts : public QWidget
{
    Q_OBJECT

public:
    explicit manageAccounts(const User &connected, QWidget *parent = nullptr);
    ~manageAccounts();

    void displayAccountList();
    QString hashPass(QString);

    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_accList_doubleClicked(const QModelIndex &index);

    void on_addAccBtn_clicked();

    void on_subBtn_2_clicked();

    void on_admBtn_2_clicked();

    void refreshSlot(bool);

private:
    Ui::manageAccounts *ui;

    User connected;
};

#endif // MANAGEACCOUNTS_H
