#include "connection.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();
    //a.setQuitOnLastWindowClosed(true);
    return a.exec();

}
