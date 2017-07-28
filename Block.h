#pragma once

#include <QByteArray>
#include <QDateTime>

class Block
{

public:
    explicit Block(const int index, const QByteArray prevHash, const QByteArray currHash, const QByteArray data, const QDateTime timestamp);

private:
    int m_index;
    QByteArray m_prevHash;
    QByteArray m_currHash;
    QByteArray m_data;
    QDateTime m_timestamp;
};
