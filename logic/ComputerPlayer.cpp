#include "Player.h"
#include "ComputerPlayer.h"
#include "Card.h"
#include "Command.h"
#include <cassert>

using namespace std;

ComputerPlayer::ComputerPlayer() : Player() {}

ComputerPlayer::ComputerPlayer(int oldScore, int Score, std::vector<Card *> hand, std::vector<Card> discard, int id)
: Player(oldScore, Score, hand, discard, id) {}

void ComputerPlayer::turn(std::vector<Card> legal, Deck *, Table &table, Command op)
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
        table.playCard(legal.at(0));
    }
}

bool ComputerPlayer::isHuman() const
{
    return false;
}
