#include "Player.h"
#include "Card.h"
#include <vector>
#include <cassert>

using namespace std;

int Player::nextid = 1; //Assign each player an id, beginning with one and incrementing

Player::Player() : oldScore_(0), currentScore_(0), id_(nextid++) {} //Construct a player with an old and current score of 0 and the next available id

Player::Player(int oldScore, int Score, std::vector<Card *> hand, std::vector<Card> discard, int id) //Construct a player, specifying its scores, hand and discard piles
: oldScore_(oldScore), currentScore_(Score), hand_(hand), discard_(discard), id_(id) {}

void Player::deal(vector<Card *> &cards) //Delete all old cards and accept the new ones being dealt
{
    hand_.clear();
    discard_.clear();

    for(vector<Card *>::iterator it = cards.begin(); it != cards.end(); it++)
    {
        hand_.push_back(*it);
    }
}

void Player::setOldScore(int score) //Mutator
{
	oldScore_ = score;
}

void Player::play(Card c) //Play the chosen card
{
    for(vector<Card *>::iterator it = hand_.begin(); it != hand_.end(); it++)
    {
        if(c == **it)
        {
            hand_.erase(it);
            return;
        }
    }
    assert(false);
}

void Player::discardCard(Card c) //Discard the chosen card
{
	discard_.push_back(c);
    play(c);
    currentScore_ += static_cast<int>( c.getRank() ) + 1;
}

int Player::oldScore() const //Accessor
{
    return oldScore_;
}

int Player::currentScore() const //Accessor
{
    return currentScore_;
}

int Player::id() const //Accessor
{
    return id_;
}

Player::~Player() //Nothing special to be done
{
}

const vector<Card *> &Player::hand() const //Accessor
{
    return hand_;
}

const vector<Card> &Player::discard() const //Accessor
{
    return discard_;
}

