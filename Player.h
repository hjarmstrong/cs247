#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player
{
    public:
    Player(bool);
    void deal(std::vector<Card *> &);
    virtual ~Player();
    int score() const;
    const std::vector<Card *> &hand() const;
    void play(Card);
    void discard(Card);
    void rageQuit();

    private:
//     int id_;
    int score_;
    bool isHuman_;
//    static int nextid = 1;
    std::vector<Card *> hand_;
};

#endif
