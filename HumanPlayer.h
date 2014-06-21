#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include <vector>

class HumanPlayer : public Player
{
    public:
    HumanPlayer();
    void turn(std::vector<Card>, Deck *, Table &);
};

#endif
