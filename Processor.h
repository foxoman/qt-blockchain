#pragma once

#include <QCryptographicHash>
#include <QByteArray>
#include <QDateTime>

#include "Blockchain.h"

class Processor
{
public:
    explicit Processor();

private:
    QByteArray calculateHash(const int index, const QByteArray prevHash, const QByteArray data, const QDateTime timestamp);
    bool validateNextBlock(const int index, const QByteArray prevHash, const QByteArray nextHash, const QDateTime timestamp);
    void generateNextBlock();
    int setGenesisBlock();

private:
    Blockchain m_blockchain;
};
