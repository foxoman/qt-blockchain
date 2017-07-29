#pragma once

#include <QCryptographicHash>
#include <QByteArray>
#include <QDateTime>

class Processor
{
public:
    explicit Processor();
    void generateNextBlock();

private:
    QByteArray calculateHash(const int index, const QByteArray prevHash, const QByteArray data, const QDateTime timestamp);
    bool validateBlockData(const int index, const QByteArray prevHash, const QByteArray data, const QDateTime timestamp);
};
