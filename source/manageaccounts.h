#ifndef MANAGEACCOUNTS_H
#define MANAGEACCOUNTS_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>


#include <QMessageBox>

#include "myaccount.h"


namespace Ui {
class manageAccounts;
}

class manageAccounts : public QWidget
{
    Q_OBJECT

public:
    explicit manageAccounts(QWidget *parent = nullptr);
    ~manageAccounts();

    void displayAccountList();
    QString hashPass(QString);

private slots:
    void on_accList_doubleClicked(const QModelIndex &index);

    void on_addAccBtn_clicked();

    void on_subBtn_2_clicked();

    void on_admBtn_2_clicked();


private:
    Ui::manageAccounts *ui;
};

#endif // MANAGEACCOUNTS_H
