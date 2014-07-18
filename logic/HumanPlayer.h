#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include "Command.h"
#include <vector>

class HumanPlayer : public Player
{
    public:
    
    // Constructor, creates a new HumanPlayer with a unique id
    HumanPlayer();

    // Defines pure virtuial method from player
    bool turn(std::vector<Card>, Deck *, Table &, Command op);

    bool isHuman() const;
};

#endif
