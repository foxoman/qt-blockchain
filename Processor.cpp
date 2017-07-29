#include "Processor.h"
#include "Block.h"

Processor::Processor()
{}

QByteArray Processor::calculateHash(const int index, const QByteArray prevHash, const QByteArray data, const QDateTime timestamp)
{
    return QCryptographicHash::hash(index + prevHash + data + timestamp, QCryptographicHash::Sha256).toHex();
}

bool Processor::validateNextBlock(const int index, const QByteArray prevHash, const QByteArray nextHash, const QDateTime timestamp)
{
    bool isValid = true;
    if(index != m_blockchain.getLastBlockIndex() + 1){
        isValid = false;
    }
    if(prevHash != m_blockchain.getLastBlockHash()){
        isValid = false;
    }
    if(nextHash != calculateHash(index, prevHash, data, timestamp)){
        isValid = false;
    }
    if(m_blockchain.getLastBlockTimestamp() >= timestamp || timestamp >= QDateTime::currentDateTime()){
        isValid = false;
    }
    return isValid;
}

void Processor::generateNextBlock()
{
    int index = m_blockchain.getLastBlockIndex() + 1;
    QDateTime timestamp = QDateTime::currentDateTime();
    QByteArray data = ".";
    QByteArray prevHash = m_blockchain.getLastBlockHash();
    QByteArray nextHash = calculateHash(index, prevHash, data, timestamp);

    m_blockchain.addNextBlock(new Block(index, prevHash, nextHash, data, timestamp));
}
