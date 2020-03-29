#ifndef GLYBOOK_H
#define GLYBOOK_H

#include <QMainWindow>

namespace Ui {
class Glybook;
}

class Glybook : public QMainWindow
{
    Q_OBJECT

public:
    explicit Glybook(QWidget *parent = nullptr);
    ~Glybook();

private:
    Ui::Glybook *ui;
};

#endif // GLYBOOK_H
