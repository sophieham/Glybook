#ifndef STATISTICS_H
#define STATISTICS_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class Statistics;
}

class Statistics : public QWidget
{
    Q_OBJECT

public:
    explicit Statistics(QWidget *parent = nullptr);
    ~Statistics();

    void displayList(const QString &);
private slots:
    void on_exportButton_clicked();

    void on_closeButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Statistics *ui;
};

#endif // STATISTICS_H
