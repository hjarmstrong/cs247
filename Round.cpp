#include "Round.h"

Round::Round()
{
    for(int i = 0; i < 13; i++)
    {
        spades_[i] = false;
        hearts_[i] = false;
        clubs_[i] = false;
        diamonds_[i] = false;
    }
}

Round::Play()
{
    cout << "A new round begins. It's player " << s turn to play.
}
