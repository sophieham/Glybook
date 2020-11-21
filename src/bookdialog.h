#ifndef BOOKDIALOG_H
#define BOOKDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <QInputDialog>

namespace Ui {
class bookDialog;
}

class bookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit bookDialog(const QString &isbn, QDialog *parent = nullptr);
    ~bookDialog();

    void displayBookData();

signals:
    void refresh(bool);

private slots:
    void on_send_pushButton_clicked();

    void on_close_pushButton_clicked();

    void on_authorList_activated(int index);

    void on_publisherList_activated(int index);

    void on_genreList_activated(int index);

private:
    Ui::bookDialog *ui;

    QString id;
};

#endif // BOOKDIALOG_H
