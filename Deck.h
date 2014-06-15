#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "Card.h"

class Deck
{
    friend std::ostream &operator<<(std::ostream &sout, const Deck &d);
    public:
    Deck();
    ~Deck();

    void shuffle();

    private:
    std::vector<Card *> cards_;
    int kCardCount;

};

std::ostream &operator<<(std::ostream &sout, const Deck &d);

#endif