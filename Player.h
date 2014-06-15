#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player
{
    public:
    Player(std::vector<Card *> &);
    virtual ~Player();
    int score() const;
    const std::vector<Card *> &hand() const;
    void play(Card);
    void discard(Card);
    virtual void RageQuit() = 0;

    private:
//     int id_;
    int score_;
//    static int nextid = 1;
    std::vector<Card *> hand_;
};

#endif
