#include "Card.h"
#include "Table.h"
#include <cassert>
#include <vector>

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

void Card::playCard(Card e)
{
    if(Card.getSuit() == SPADES)
    {
        assert(spades_[Card.getRank() + 1] == false); 
        spades_[Card.getRank() + 1] = true;
    }
    if(Card.getSuit() == HEARTS)
    {
        assert(hearts_[Card.getRank() + 1] == false); 
        spades_[Card.getRank() + 1] = true;
    }
    if(Card.getSuit() == CLUBS)
    {
        assert(clubs_[Card.getRank() + 1] == false); 
        clubs_[Card.getRank() + 1] = true;
    }
    if(Card.getSuit() == DIAMONDS)
    {
        assert(clubs_[diamonds.getRank() + 1] == false); 
        diamonds_[Card.getRank() + 1] = true;
    }

}

vector<Card> &Table::legalMoves()
{
    vector<Card> ret;
    if(spades[SEVEN] == false)
    {
        ret.push_back(Card(SEVEN, SPADE));
        return; 
    }
    //We start at 1 because we don't care about -1
    for(int i = 1; i < static_cast<int>(RANK_COUNT); i++)
    {
        if(spades_[i] == true)
        {
            if(i <= static_cast<int>(SEVEN))
            {
                ret.push_back(Card(static_cast<RANK>(i - 1), SPADE));
            }
            if(i >= static_cast<int>(SEVEN))
            {
                ret.push_back(Card(static_cast<Rank>(i + 1), SPADE));
            }
        }
    }
    for(int i = 1; i < static_cast<int>(RANK_COUNT); i++)
    {
        if(hearts_[i] == true)
        {
            if(i <= static_cast<int>(SEVEN))
            {
                ret.push_back(Card(static_cast<RANK>(i - 1), HEART));
            }
            if(i >= static_cast<int>(SEVEN))
            {
                ret.push_back(Card(static_cast<Rank>(i + 1), HEART));
            }
        }
    }
    for(int i = 1; i < static_cast<int>(RANK_COUNT); i++)
    {
        if(diamonds_[i] == true)
        {
            if(i <= static_cast<int>(SEVEN))
            {
                ret.push_back(Card(static_cast<RANK>(i - 1), DIAMOND));
            }
            if(i >= static_cast<int>(SEVEN))
            {
                ret.push_back(Card(static_cast<Rank>(i + 1), DUAMOND));
            }
        }
    }
    for(int i = 1; i < static_cast<int>(RANK_COUNT); i++)
    {
        if(clubs_[i] == true)
        {
            if(i <= static_cast<int>(SEVEN))
            {
                ret.push_back(Card(static_cast<RANK>(i - 1), CLUB));
            }
            if(i >= static_cast<int>(SEVEN))
            {
                ret.push_back(Card(static_cast<Rank>(i + 1), CLUB));
            }
        }
    }
    return ret;
}

std::ostream &operator<<(std::ostream &sout, const Table &t);
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

