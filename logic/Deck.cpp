#include <cstdlib>
#include <iostream>
#include <vector>
#include "Card.h"
#include "Deck.h"

using namespace std;

vector<Card *> cards_;

Deck::Deck() //Add 52 cards to our deck, 4*13.
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

Deck::~Deck() //Delete each card in our deck.
{
    for(vector<Card *>::iterator it = cards_.begin(); it != cards_.end(); it++)
    {
        delete *it;
    }
}

const vector<Card *> &Deck::deckList() const // Accessor
{
    return cards_;
}

void Deck::shuffle() // Randomly permute the set of cards in our deck
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

ostream &operator<<(ostream &sout, const Deck &d) //Print the set of cards
{
    int line = 0;
    for(vector<Card *>::const_iterator it = d.cards_.begin(); it != d.cards_.end(); it++)
    {
        sout << **it << " "; 
        if(line < 12)
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

