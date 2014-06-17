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
    int oldScore() const;
    int currentScore() const;
    int id() const;
    const std::vector<Card *> &hand() const;
    const std::vector<Card *> &discard() const;
    void resetDiscard();
    void setOldScore(int);
    void play(Card);
    void discardCard(Card);
    virtual void turn(std::vector<Card>, Deck &, Table &) = 0;

    private:
    int oldScore_;
    int currentScore_;
    std::vector<Card *> hand_;
    std::vector<Card *> discard_;
    int id_;
    static int nextid;
};

#endif
