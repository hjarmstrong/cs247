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
    
    const std::vector<Card *> &deckList();
    void shuffle();

    private:
    std::vector<Card *> cards_;
    static const int kCardCount = 52;

};

std::ostream &operator<<(std::ostream &sout, const Deck &d);

#endif
