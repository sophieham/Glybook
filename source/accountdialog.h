#ifndef ACCOUNTDIAL_H
#define ACCOUNTDIAL_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

#include "user.h"

namespace Ui {
class accountDialog;
}

class accountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit accountDialog(const int &id, const User &connected, QWidget *parent = nullptr);
    ~accountDialog();


    QString hashPass(QString text);
    QString getUsername() const;
    void setUsername(const QString &);
    short getRank() const;
    void setRank(const short &);

signals:
    void refresh(bool);

private slots:
    void on_dialogButton_accepted();

    void on_dialogButton_rejected();

private:
    Ui::accountDialog *ui;
    int id;

    QString username;
    short rank;

    User connected;
};

#endif // ACCOUNTDIAL_H
