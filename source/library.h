#ifndef LIBRARY_H
#define LIBRARY_H

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
        QString getName() const;
        QString getAddress() const;
        QString getType() const;
        void setName(const QString);
        void setType(const QString);
        void setAddress(const QString);
    };

#endif // LIBRARY_H
