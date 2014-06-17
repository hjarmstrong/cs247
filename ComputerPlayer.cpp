#include "Player.h"
#include "ComputerPlayer.h"
#include "Card.h"
#include <cassert>

using namespace std;

ComputerPlayer::ComputerPlayer() : Player() {}

void ComputerPlayer::turn(std::vector<Card> legal, Deck &, Table &table)
{
    if(legal.empty())
    {
        assert(! hand().empty() );
        cout << "Player " << id() << " discards " << *hand().at(0) << endl;
        discard( *hand().at(0) );
    }
    else
    {
        cout << "Player " << id() << " plays " << legal.at(0) << endl;
        play(legal.at(0));
        table.playCard(legal.at(0));
    }
}
