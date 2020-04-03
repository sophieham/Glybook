#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <QString>
using namespace std;

    class Library {
    private:
        QString name;
        QString type;
        QString address;

    public:
        Library();
        Library(QString, QString, QString);
        ~Library();
        QString print() const;
        QString getName() const;
        QString getAddress() const;
        QString getType() const;
        void setAddress(const QString);
    };

#endif // LIBRARY_H
