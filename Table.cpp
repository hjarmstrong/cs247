#include "Card.h"
#include "Table.h"
#include <cassert>
#include <vector>
#include <set>
#include <functional>

using namespace std;

Table::Table()
{
    for(int i = 0; i < 13; i++)
    {
        spades_[i] = false;
        hearts_[i] = false;
        clubs_[i] = false;
        diamonds_[i] = false;
    }
}

void Table::playCard(Card e)
{
    if(e.getSuit() == SPADE)
    {
        assert(spades_[e.getRank() + 1] == false); 
        spades_[e.getRank() + 1] = true;
    }
    if(e.getSuit() == HEART)
    {
        assert(hearts_[e.getRank() + 1] == false); 
        spades_[e.getRank() + 1] = true;
    }
    if(e.getSuit() == CLUB)
    {
        assert(clubs_[e.getRank() + 1] == false); 
        clubs_[e.getRank() + 1] = true;
    }
    if(e.getSuit() == DIAMOND)
    {
        assert(clubs_[e.getRank() + 1] == false); 
        diamonds_[e.getRank() + 1] = true;
    }

}

set<Card> Table::legalMoves()
{
    set<Card> ret;
    if(spades_[SEVEN] == false)
    {
        ret.insert(Card(SPADE, SEVEN));
        return ret; 
    }
    //We start at 1 because we don't care about -1
    for(int i = 1; i < static_cast<int>(RANK_COUNT - 1); i++)
    {
        if(spades_[i] == true)
        {
            if(i <= static_cast<int>(SEVEN))
            {
                ret.insert(Card(SPADE, static_cast<Rank>(i - 1)));
            }
            if(i >= static_cast<int>(SEVEN))
            {
                ret.insert(Card(SPADE, static_cast<Rank>(i + 1)));
            }
        }
    }
    for(int i = 1; i < static_cast<int>(RANK_COUNT - 1); i++)
    {
        if(hearts_[i] == true)
        {
            if(i <= static_cast<int>(SEVEN))
            {
                ret.insert(Card(HEART, static_cast<Rank>(i - 1)));
            }
            if(i >= static_cast<int>(SEVEN))
            {
                ret.insert(Card(HEART, static_cast<Rank>(i + 1)));
            }
        }
    }
    for(int i = 1; i < static_cast<int>(RANK_COUNT - 1); i++)
    {
        if(diamonds_[i] == true)
        {
            if(i <= static_cast<int>(SEVEN))
            {
                ret.insert(Card(DIAMOND, static_cast<Rank>(i - 1)));
            }
            if(i >= static_cast<int>(SEVEN))
            {
                ret.insert(Card(DIAMOND, static_cast<Rank>(i + 1)));
            }
        }
    }
    for(int i = 1; i < static_cast<int>(RANK_COUNT - 1); i++)
    {
        if(clubs_[i] == true)
        {
            if(i <= static_cast<int>(SEVEN))
            {
                ret.insert(Card(CLUB, static_cast<Rank>(i - 1)));
            }
            if(i >= static_cast<int>(SEVEN))
            {
                ret.insert(Card(CLUB, static_cast<Rank>(i + 1)));
            }
        }
    }
    return ret;
}

std::ostream &operator<<(std::ostream &sout, const Table &t)
{
    sout << "Cards on the table:" << endl;
    sout << "Clubs:";
    for(int i = 0; i < 13; i++)
    {
        if(t.clubs_[i])
            sout << " " << i;
    }
    sout << endl << "Diamonds:";
    for(int i = 0; i < 13; i++)
    {
        if(t.diamonds_[i])
            sout << " " << i;
    }
    sout << endl << "Hearts:";
    for(int i = 0; i < 13; i++)
    {
        if(t.hearts_[i])
            sout << " " << i;
    }
    sout << endl << "Spades:";
    for(int i = 0; i < 13; i++)
    {
        if(t.spades_[i])
            sout << " " << i;
    }

    return sout;
}

