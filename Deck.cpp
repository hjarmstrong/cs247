#include <cstdlib>
#include <iostream>
#include <vector>
#include "Card.h"
#include "Deck.h"

using namespace std;

int kCardCount = 52;
vector<Card *> cards_;

Deck::Deck()
{
    for(int i = 0; i < SUIT_COUNT; i++)
    {
        for(int j = 0; j < RANK_COUNT; j++)
        {
            Card *newCard = new Card(static_cast<Suit>(i),static_cast<Rank>(j));
            cards_.push_back(newCard);
        }
    }
}

Deck::~Deck()
{
    for(vector<Card *>::iterator it = cards_.begin(); it != cards_.end(); it++)
    {
        delete *it;
    }
}

void Deck::shuffle()
{
	int n = kCardCount;

	while ( n > 1 )
    {
		int k = (int) (lrand48() % n);
		--n;
		Card *c = cards_.at(n);
		cards_.at(n) = cards_.at(k);
		cards_.at(k) = c;
	}
}

ostream &operator<<(ostream &sout, const Deck &d)
{
    int line = 0;
    for(vector<Card *>::const_iterator it = d.cards_.begin(); it != d.cards_.end(); it++)
    {
        sout << **it;
        if(line < 13)
        {
            line++;
        }
        else
        {
            sout << endl;
            line = 0;
        }
    }
    return sout;
}

const std::vector<Card *> &deckList()
{
    return cards_; 
}
