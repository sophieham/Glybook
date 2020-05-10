#ifndef BOOKINFORMATION_H
#define BOOKINFORMATION_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>

#include "bookdialog.h"
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

signals:
    void refresh(bool);

private slots:
    void on_reserveButton_clicked();

    void on_closeButton_clicked();

    void on_bookmark_clicked();

    void refreshSlot(bool);

private:
    Ui::bookInformation *ui;

    User connected;

    QString isbn;

    Reservation resv;
    Book book;
};

#endif // BOOKINFORMATION_H
