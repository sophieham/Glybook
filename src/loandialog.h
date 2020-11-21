#ifndef LoanDialog_H
#define LoanDialog_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>

#include "book.h"
#include "user.h"
#include "reservation.h"

namespace Ui {
class LoanDialog;
}

class LoanDialog : public QWidget
{
    Q_OBJECT

public:
    explicit LoanDialog(QWidget *parent = nullptr);
    ~LoanDialog();

    void displayBookList();
    void displayUserList();

private slots:
    void on_searchUser_textChanged(const QString &text);

    void on_searchBook_textChanged(const QString &text);

    void on_confirmBttn_clicked();

private:
    Ui::LoanDialog *ui;
    QString searchBook;
    QString searchUser;
};

#endif // LoanDialog_H
