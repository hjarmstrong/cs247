#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "Card.h"

class Deck
{
    friend std::ostream &operator<<(std::ostream &sout, const Deck &d);
    public:

    // Constructs a new deck with 52 cards allocated on the heap
    Deck();

    // Destructor, cleans up cards
    ~Deck();
    
    // Accessor
    const std::vector<Card *> &deckList() const;

    void shuffle();

    private:
    std::vector<Card *> cards_;
    static const int kCardCount = 52;

};

// Prints out a list of all cards in the deck
std::ostream &operator<<(std::ostream &sout, const Deck &d);

#endif
