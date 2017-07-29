#include "Blockchain.h"

Blockchain::Blockchain()
{

}

int Blockchain::getLastBlockIndex() const
{
    return m_chain.last().getIndex();
}

QByteArray Blockchain::getLastBlockHash() const
{
    return m_chain.last().getCurrHash();
}

QDateTime Blockchain::getLastBlockTimestamp() const
{
    return m_chain.last().getTimestamp();
}
