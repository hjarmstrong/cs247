#include "Player.h"
#include "ComputerPlayer.h"
#include "Card.h"
#include <cassert>

using namespace std;

ComputerPlayer::ComputerPlayer() : Player() {}

void ComputerPlayer::turn(std::vector<Card> legal, Deck &, Table &)
{
    if(legal.empty())
    {
        assert(! hand().empty() );
        discard( *hand().at(0) );
    }
    else
    {
        play(legal.at(0));
    }
}
