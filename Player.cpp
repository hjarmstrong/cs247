#include "Player.h"
#include "Card.h"
#include <vector>
#include <cassert>

using namespace std;

int Player::nextid = 1;

Player::Player() : oldScore_(0), currentScore_(0), id_(nextid++) {}

Player::Player(int oldScore, int Score, std::vector<Card *> hand, std::vector<Card> discard, int id)
: oldScore_(oldScore), currentScore_(Score), hand_(hand), discard_(discard), id_(id) {}

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

void Player::resetDiscard()
{
	discard_.clear();
}

void Player::setOldScore(int score)
{
	oldScore_ = score;
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

void Player::discardCard(Card c)
{
	discard_.push_back(c);
    play(c);
    currentScore_ += static_cast<int>( c.getRank() ) + 1;
}

int Player::oldScore() const
{
    return oldScore_;
}

int Player::currentScore() const
{
    return currentScore_;
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

const vector<Card> &Player::discard() const
{
    return discard_;
}

