#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <set>
#include <functional>
#include "Card.h"

class Table
{
    friend std::ostream &operator<<(std::ostream &, const Table &);
    public:
    Table();
    void playCard(Card c);
    std::set<Card> legalMoves();
    private:
    bool spades_[13];
    bool hearts_[13];
    bool clubs_[13];
    bool diamonds_[13];
};

std::ostream &operator<<(std::ostream &, const Table &);

#endif
