#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"
#include "Table.h"
#include "Deck.h"

class Player
{
    public:
    Player();
    void deal(std::vector<Card *> &);
    virtual ~Player();
    int score() const;
    int id() const;
    const std::vector<Card *> &hand() const;
    void play(Card);
    void discard(Card);
    virtual void turn(std::vector<Card>, Deck &, Table &) = 0;

    private:
    int score_;
    std::vector<Card *> hand_;
    int id_;
    static int nextid;
};

#endif
