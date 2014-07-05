#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include "Card.h"
#include <vector>

class ComputerPlayer : public Player
{
   public:
   
   // Constructor, allocates a new computerplayer with a unique id
   ComputerPlayer();

   // Clone constructor, this is used when a player switches type
   ComputerPlayer(int oldScore, int Score, std::vector<Card *> hand, std::vector<Card> discard, int id);

   // Defines the pure virtuial method from player
   void turn(std::vector<Card>, Deck *, Table &); 
};

#endif
