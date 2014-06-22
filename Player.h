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

    // Clone constructor, called when a player switches types
    Player(int oldScore, int Score, std::vector<Card *> hand, std::vector<Card> discard, int id);

    // This method sets the hand of a player, this should be called before they play their turn
    void deal(std::vector<Card *> &);
    virtual ~Player();

    // Accessors for player data.
    int oldScore() const;
    int currentScore() const;
    int id() const;

    // Read only contains of pointers to relivant card lists
    // These pointers are cleand up by deck and should not be delted
    const std::vector<Card *> &hand() const;
    const std::vector<Card> &discard() const;

    // Used to set the previous score at the end of evry turn
    void setOldScore(int);
    
    // This method exicutes the turn of a player in a given card game
    virtual void turn(std::vector<Card>, Deck *, Table &) = 0;

    protected:
     // Functions for manipulating the hand of a player during their turn
    void play(Card);
    void discardCard(Card);

    private:
    int oldScore_;
    int currentScore_;
    std::vector<Card *> hand_;
    std::vector<Card> discard_;
    int id_;
    static int nextid;
};
#endif
