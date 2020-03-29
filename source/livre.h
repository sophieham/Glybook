#pragma once
#include <iostream>
#include "categorie.h"
#include <QVector>
#include <sstream>
using namespace std;

    class Livre {
    private:
        QString nomLivre, auteurLivre, editeurLivre, resumeLivre, isbnLivre;
        bool libre;
        Categorie catLivre;
        size_t compteur;
        QVector<QString> liste;


    public:
        Livre();
        ~Livre();
        Livre(QString, QString, QString, QString, QString, Categorie);
        void printLivre();
        QString getNomLivre() const;
        void setNomLivre(QString const);
        QString getAuteurLivre() const;
        void setAuteurLivre(QString const);
        QString getEditeurLivre() const;
        void setEditeurLivre(QString const);
        QString getResumeLivre() const;
        void setResumeLivre(QString const);
        QString getIsbnLivre() const;
        void setIsbnLivre(QString const);
        bool getLibre() const;
        void setLibre(bool const);
        Categorie getCatLivre();
        void setCatLivre(Categorie const);
        size_t getOccurence();
        void afficherListe() const;
        /*
        friend std::ostream& operator<<(std::ostream& out, Livre l);
        static QString to_string(Livre const);
        */
    };
