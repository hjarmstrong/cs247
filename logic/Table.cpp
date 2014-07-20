#include "Card.h"
#include "Table.h"
#include <cassert>
#include <vector>
#include <set>
#include <functional>

using namespace std;

Table::Table() //Set every card as not having yet been played
{
    for(int i = 0; i < 13; i++)
    {
        spades_[i] = false;
        hearts_[i] = false;
        clubs_[i] = false;
        diamonds_[i] = false;
    }
}

void Table::playCard(Card e) //Take a card and set its value to true in the "played" array
{
    if(e.getSuit() == SPADE)
    {
        assert(spades_[e.getRank()] == false);
        spades_[e.getRank()] = true;
    }
    if(e.getSuit() == HEART)
    {
        assert(hearts_[e.getRank()] == false);
        hearts_[e.getRank()] = true;
    }
    if(e.getSuit() == CLUB)
    {
        assert(clubs_[e.getRank()] == false);
        clubs_[e.getRank()] = true;
    }
    if(e.getSuit() == DIAMOND)
    {
        assert(diamonds_[e.getRank()] == false);
        diamonds_[e.getRank()] = true;
    }

}

set<Card> Table::legalMoves() //From the cards already played on the tables, determine which new cards can be legally played for each suit.  Then return the total set.
{
    set<Card> ret;
    if(spades_[SEVEN] == false)
    {
        ret.insert(Card(SPADE, SEVEN));
        return ret;
    }

    for(int i = 0; i < static_cast<int>(SUIT_COUNT); i++)
    {
        ret.insert(Card(static_cast<Suit>(i), SEVEN));
    }

    //We start at 1 because we don't care about 0
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

std::vector<std::vector<Card *> > Table::playedCards() const //For each suit, push back a pointer to every card that has been played this round
{
    std::vector<std::vector<Card *> > returnVector;
    std::vector<Card *> suitVector;

    for(int i = 0; i < 13; i++)
    {
        if(clubs_[i])
        {
            suitVector.push_back(new Card(CLUB, static_cast<Rank>(i)));
        }
        else
        {
            suitVector.push_back(NULL);
        }

    }

    returnVector.push_back(suitVector);
    suitVector.clear();

    for(int i = 0; i < 13; i++)
    {
        if(diamonds_[i])
        {
            suitVector.push_back(new Card(DIAMOND, static_cast<Rank>(i)));
        }
        else
        {
            suitVector.push_back(NULL);
        }

    }

    returnVector.push_back(suitVector);
    suitVector.clear();

    for(int i = 0; i < 13; i++)
    {
        if(hearts_[i])
        {
            suitVector.push_back(new Card(HEART, static_cast<Rank>(i)));
        }
        else
        {
            suitVector.push_back(NULL);
        }

    }

    returnVector.push_back(suitVector);
    suitVector.clear();

    for(int i = 0; i < 13; i++)
    {
        if(spades_[i])
        {
            suitVector.push_back(new Card(SPADE, static_cast<Rank>(i)));
        }
        else
        {
            suitVector.push_back(NULL);
        }

    }

    returnVector.push_back(suitVector);

    return returnVector;
}

std::ostream &operator<<(std::ostream &sout, const Table &t) //Print the cards on the table, done by looping through each suit
{
string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};


    sout << "Cards on the table:" << endl;
    sout << "Clubs:";
    for(int i = 0; i < 13; i++)
    {
        if(t.clubs_[i])
            sout << " " << ranks[i];
    }
    sout << endl << "Diamonds:";
    for(int i = 0; i < 13; i++)
    {
        if(t.diamonds_[i])
            sout << " " << ranks[i];
    }
    sout << endl << "Hearts:";
    for(int i = 0; i < 13; i++)
    {
        if(t.hearts_[i])
            sout << " " << ranks[i];
    }
    sout << endl << "Spades:";
    for(int i = 0; i < 13; i++)
    {
        if(t.spades_[i])
            sout << " " << ranks[i];
    }

    return sout;
}
