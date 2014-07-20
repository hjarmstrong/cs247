#include "Player.h"
#include "ComputerPlayer.h"
#include "Card.h"
#include "Command.h"
#include <cassert>

using namespace std;

ComputerPlayer::ComputerPlayer() : Player() {} //A computer player is a player

ComputerPlayer::ComputerPlayer(int oldScore, int Score, std::vector<Card *> hand, std::vector<Card> discard, int id) //Constructor to change a player into a computer (used when ragequitting)
: Player(oldScore, Score, hand, discard, id) {}

bool ComputerPlayer::turn(std::vector<Card> legal, Deck *, Table *table, Command op) // Play or discard the first available, legal card
{
    if(legal.empty())
    {
        assert(! hand().empty() );
        cout << "Player " << id() << " discards " << *hand().at(0) << "." << endl;
        discardCard( *hand().at(0) );
    }
    else
    {
        cout << "Player " << id() << " plays " << legal.at(0) << "." << endl;
        play(legal.at(0));
        table->playCard(legal.at(0));
    }

    return true;
}

bool ComputerPlayer::isHuman() const //Computer players are not human.
{
    return false;
}
