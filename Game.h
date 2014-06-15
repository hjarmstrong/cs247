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
    void printTable();

    private:
    std::vector<player *> players_;
    Deck *deck_;
    bool spades_[13];
    bool hearts_[13];
    bool clubs_[13];
    bool diamonds_[13];
};

#endif
