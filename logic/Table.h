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

    // Constructos a new table with no cards on it
    Table();

    // Adds a card to the table, played cards can not be unplayed
    void playCard(Card c);

    // Based on the cards on the table return a set of all the possible leagal moves
    std::set<Card> legalMoves();

    private:
    bool spades_[13];
    bool hearts_[13];
    bool clubs_[13];
    bool diamonds_[13];
};

// Prints out the cards on the table
std::ostream &operator<<(std::ostream &, const Table &);

#endif
