#include "Block.h"

Block::Block(const int index, const QByteArray prevHash, const QByteArray currHash, const QByteArray data, const QDateTime timestamp) :
    m_index(index),
    m_prevHash(prevHash),
    m_currHash(currHash),
    m_data(data),
    m_timestamp(timestamp)
{

}
