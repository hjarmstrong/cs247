#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include "Card.h"
#include <vector>

class ComputerPlayer : public Player
{
   public:
   ComputerPlayer();
   void turn(std::vector<Card>, Deck &, Table &); 
};

#endif
