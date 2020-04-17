#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class settings;
}

class settings : public QWidget
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();

    void fillForm();
    void fillTable(const QString &selected);

    void keyPressEvent(QKeyEvent *event);

signals:
    void refresh(bool);

private slots:
    void on_saveButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::settings *ui;

    QString selection;
};

#endif // SETTINGS_H
