#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Deck.h"

#include <vector>

class Game
{
    public:

    // Constructor, builds a new game with 4 players asking if they are human or computer
    Game();

    // Cleans up deck and players on the heap
    ~Game();

   // Plays the game
   void play();

    private:

    //Helper function for a round of the game
    void playRound();

    std::vector<Player *> players_;
    Deck *deck_;
    static const int kNumPlayers = 4;
};

#endif
