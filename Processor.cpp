#include "Processor.h"

Processor::Processor()
{}

bool Processor::validateBlockData(const int index, const QByteArray prevHash, const QByteArray data, const QDateTime timestamp)
{
    return true;
}

QByteArray Processor::calculateHash(const int index, const QByteArray prevHash, const QByteArray data, const QDateTime timestamp)
{
    return (validateBlockData(index, prevHash, data, timestamp)) ? QCryptographicHash::hash(index + prevHash + data + timestamp, QCryptographicHash::Sha256).toHex() : 0;
}
