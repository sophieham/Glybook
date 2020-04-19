#include "cryptohashclass.h"

cryptoHashClass::cryptoHashClass()
{

}

cryptoHashClass::~cryptoHashClass()
{

}

// hache le mot de passe pour pas qu'il soit en clair dans la base de donnée
// utilise le sha-256
QString cryptoHashClass::hashPass(QString text){
    QByteArray hash = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Sha256);
    QString pass=hash.toHex();
    return pass;
}
