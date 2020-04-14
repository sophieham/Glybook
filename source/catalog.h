#ifndef CATALOG_H
#define CATALOG_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QKeyEvent>

#include "user.h"
#include "bookinformation.h"

namespace Ui {
class Catalog;
}

class Catalog : public QWidget
{
    Q_OBJECT

public:
    explicit Catalog(const User &connected, QWidget *parent = nullptr);
    ~Catalog();

    void displayBookList();

    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_tableWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::Catalog *ui;

    User connected;
};

#endif // CATALOG_H
