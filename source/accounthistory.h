#ifndef ACCOUNTHISTORY_H
#define ACCOUNTHISTORY_H

#include <QWidget>

namespace Ui {
class accountHistory;
}

class accountHistory : public QWidget
{
    Q_OBJECT

public:
    explicit accountHistory(const int &id, QWidget *parent = nullptr);
    ~accountHistory();

private:
    Ui::accountHistory *ui;

    int id;
};

#endif // ACCOUNTHISTORY_H
