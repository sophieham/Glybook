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

    void displayBookList(int checked);

    void keyPressEvent(QKeyEvent *event);

signals:
    void refresh(bool);

private slots:
    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_checkBox_stateChanged(int arg1);

    void on_searchBar_textChanged(const QString &arg1);

    void refreshSlot(bool);

private:
    Ui::Catalog *ui;

    User connected;

    QString search;
};

#endif // CATALOG_H
