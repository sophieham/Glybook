#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <iostream>
#include <QString>
using namespace std;

    class Bibliotheque {
    private:
        QString nomBiblio;
        QString typeBiblio;
        QString adresseBiblio;

    public:
        Bibliotheque();
        Bibliotheque(QString, QString, QString);
        ~Bibliotheque();
        QString printBiblio() const;
        QString getNomBiblio() const;
        QString getAdresseBiblio() const;
        QString getTypeBiblio() const;
        void setAdresseBiblio(const QString);
    };

#endif // BIBLIOTHEQUE_H
