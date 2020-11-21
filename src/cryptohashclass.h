#ifndef CRYPTOHASHCLASS_H
#define CRYPTOHASHCLASS_H

#include <QString>
#include <QCryptographicHash>

class cryptoHashClass
{
public:
    cryptoHashClass();
    ~cryptoHashClass();
    static QString hashPass(QString);
};

#endif // CRYPTOHASHCLASS_H
