#include "Block.h"

Block::Block(const int index, const QByteArray prevHash, const QByteArray currHash, const QByteArray data, const QDateTime timestamp) :
    m_index(index),
    m_prevHash(prevHash),
    m_currHash(currHash),
    m_data(data),
    m_timestamp(timestamp)
{}

int Block::getIndex() const { return m_index; }

QByteArray Block::getPrevHash() const { return m_prevHash; }

QByteArray Block::getCurrHash() const { return m_currHash; }

QByteArray Block::getData() const { return m_data; }

QDateTime Block::getTimestamp() const { return m_timestamp; }
