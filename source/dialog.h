#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "utilisateur.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QAbstractButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void sendFirstData(QStringList);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
