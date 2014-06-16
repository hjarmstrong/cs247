#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Deck.h"

#include <vector>

class Game
{
    public:
    Game();
    ~Game();
    const std::vector<Player *> &players() const;
    void play();
    void deck();
    void playRound();

    private:
    std::vector<Player *> players_;
    Deck *deck_;
};

#endif
