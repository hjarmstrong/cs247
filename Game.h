#ifndef GAME_H
#define GAME_H

#include "Player.h"
//#include "Round.h"
#include "Deck.h"
#include <vector>


class Game
{
    public:
    Game();
    ~Game();
    const std::vector<player *> players() const;
    void play();
    void deck();
    bool playRound();

    private:
    std::vector<player *> players_;
    Deck *deck_;
};

#endif
