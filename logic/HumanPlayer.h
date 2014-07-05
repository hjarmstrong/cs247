#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include <vector>

class HumanPlayer : public Player
{
    public:
    
    // Constructor, creates a new HumanPlayer with a unique id
    HumanPlayer();

    // Defines pure virtuial method from player
    void turn(std::vector<Card>, Deck *, Table &);
};

#endif
