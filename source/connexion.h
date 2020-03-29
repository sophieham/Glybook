#ifndef CONNEXION_H
#define CONNEXION_H

#include <QMainWindow>
#include "emprunt.h"
#include "dialog.h"
#include "glybook.h"

QT_BEGIN_NAMESPACE
namespace Ui { class connexion; }
QT_END_NAMESPACE

class Connexion : public QMainWindow
{
    Q_OBJECT

public:
    Connexion(QWidget *parent = nullptr);
    ~Connexion();

    QString hashPass(QString);

private slots:
    void receiveFirstData(QStringList);

    void on_btnConnect_clicked();

private:
    Ui::connexion *ui;
    QSqlDatabase db;
};
#endif // connexion_H
