#ifndef BOOKINFORMATION_H
#define BOOKINFORMATION_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

#include "bookdialog.h"
#include "book.h"
#include "reservation.h"

namespace Ui {
class bookInformation;
}

class bookInformation : public QWidget
{
    Q_OBJECT

public:
    explicit bookInformation(const User &connected, const QString &isbn, QWidget *parent = nullptr);
    ~bookInformation();

    void displayBook();
    void setButton();
private slots:
    void on_reserveButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::bookInformation *ui;

    User connected;

    QString isbn;

    Reservation resv;
    Book book;
};

#endif // BOOKINFORMATION_H
