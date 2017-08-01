#pragma once

#include <QVector>
#include <QByteArray>
#include <QDateTime>
#include "Block.h"

class Blockchain
{
public:
    explicit Blockchain();

private:
    QVector<Block> m_chain;

public:
    int size() const;
    int getLastBlockIndex() const;
    QByteArray getLastBlockHash() const;
    QDateTime getLastBlockTimestamp() const;
    void addNextBlock(Block* block);
};
