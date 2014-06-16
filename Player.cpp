#include "Player.h"
#include "Card.h"
#include <vector>
#include <cassert>

using namespace std;

int Player::nextid = 1;

Player::Player() : score_(0), id_(nextid++) {}

void Player::deal(vector<Card *> &cards)
{
    for(vector<Card *>::iterator it = hand_.begin(); it != hand_.end(); it++)
    {
        //delete *it;
    }

    hand_.clear();

    for(vector<Card *>::iterator it = cards.begin(); it != cards.end(); it++)
    {
        hand_.push_back(*it);
    }
}

void Player::play(Card c)
{
    for(vector<Card *>::iterator it = hand_.begin(); it != hand_.end(); it++)
    {
        if(c == **it)
        {
            //delete *it;
            hand_.erase(it);
            return;
        }
    }
    assert(false);
}

void Player::discard(Card c)
{
    play(c);
    score_ += static_cast<int>( c.getRank() ) + 1;
}

int Player::score() const
{
    return score_;
}

int Player::id() const
{
    return id_;
}

Player::~Player()
{
    for(vector<Card *>::iterator it = hand_.begin(); it != hand_.end(); it++)
    {
        //delete *it;
    }
}

const vector<Card *> &Player::hand() const
{
    return hand_;
}

