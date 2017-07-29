#pragma once

#include <QVector>
#include <QByteArray>
#include <QDateTime>
#include "Block.h"

class Chain
{
public:
    explicit Chain();

private:
    QVector<Block> chain;

    int getPreviousBlockIndex() const;
    QByteArray getPreviousBlockHash() const;
    QDateTime getPreviousBlockDate() const;
};
