#include "Game.h"
#include <vector>
#include <iostream>
#include <limits>
#include "Deck.h"

using namespace std;

Game::Game() : deck_(new Deck)
{
    string input;

    for(int i = 0; i < 4; i++)
    {
        cout << "Is player " << i << " a human(h) or a computer(c)?"
        cin >> input;
        if(input == h)
        {
            players_.push_back(new player(true));
        }
        else
        {
            players_.push_back(new player(false));
        }
    }
}

Game::~Game()
{
    for(vector<Player *>::iterator it = players_.begin(); it != players_.end(); it++)
    {
        delete *it;
    }
    
    delete deck_;
}

const std::vector<player *> &Game::players() const
{
    return players_;
}

void Game::play()
{
    int lowestScore = numeric_limits<int>::max(), lowestOwner = -1;
    bool gameOver = false;

    for(int i = 0; i < players_.size(); it++)
    {
        if(players_[i].score() < lowestScore)
        {
            lowestScore = players_[i].score();
            lowestOwner = i;
        }

        if(players_[i].score() >= 80)
        {
            gameOver = true;
        }
    }
    if(gameOver == true)
    {
        cout << "Player " << lowestOwner << " wins!"
        return;
    }

    deck_->shuffle();
    vector<Card *> hand;

    for(int k = 0; i < 4; i++)
    {
        for(int i = 0; i < 13; i++)
        {
            hand.push_back(deck_->deckList().at(i + 13*k));
        }
        players_.at(k).deal(hand);
        hand.clear();
    }

    if(!round_.play())
    {
        return;
    }

}

void Game::deck()
{
    cout << deck_;
}

void Game::printTable()
{

    cout << "Cards on the table:" << endl << "Clubs:";
    for(int i = 0; i < 13; i++)
    {
        if(clubs_[i])
            cout << " " << i;
    }
    cout << endl << "Diamonds:";
    for(int i = 0; i < 13; i++)
    {
        if(diamonds_[i])
            cout << " " << i;
    }
    cout << endl << "Hearts:";
    for(int i = 0; i < 13; i++)
    {
        if(hearts_[i])
            cout << " " << i;
    }
    cout << endl << "Spades:";
    for(int i = 0; i < 13; i++)
    {
        if(spades_[i])
            cout << " " << i;
    }
}

void Game::playRound()
{
    for(int i = 0; i < 13; i++)
    {
        spades_[i] = false;
        hearts_[i] = false;
        clubs_[i] = false;
        diamonds_[i] = false;
    }

    int playerTurn;

    
    for(int it = 0; it < players_.size(); it++)
    {
        for(vector<Card *>::iterator ti = players_.at(it).hand().begin(); ti != players_.at(it).hand().end(); ti++)
        {
            if(**ti.getRank() == SEVEN && **ti.getSuit() == SPADE)
            {
                playerTurn = it; 
                goto fail;
            }
        }
    }

fail:
    cout << "A new round begins. It's player " << playerTurn  << "'s turn to play."


    if(players_.at(playerTurn).isHuman())
    {
        printTable();
        cout << "Your Hand:";
        for(int i = 0; i < players_.at(playerTurn).hand().size(); i++)
        {
            cout << " " << *players_.at(playerTurn).hand().at(i);
        }
        cout << endl;
        for(int i = 0; i < 
    }

}
