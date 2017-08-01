#include "Processor.h"
#include "Block.h"

Processor::Processor()
{
    setGenesisBlock();
}

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

int Processor::setGenesisBlock()
{
    if(m_blockchain.size() == 0){
        QDateTime timestamp = QDateTime::currentDateTime();
        QByteArray genesisHash = "816534932c2b7154836da6afc367695e6337db8a921823784c14378abed4f7d7";
        m_blockchain.addNextBlock(new Block(0, "0", genesisHash, "genesis block", timestamp));

        return 0;
    }
    return 1;
}
