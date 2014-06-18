#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include "Card.h"
#include <vector>

class ComputerPlayer : public Player
{
   public:
   ComputerPlayer();
   ComputerPlayer(int oldScore, int Score, std::vector<Card *> hand, std::vector<Card> discard, int id);
   void turn(std::vector<Card>, Deck &, Table &); 
};

#endif
