#include "Game.h"
#include <vector>
#include <iostream>
#include <cassert>
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

        assert(input == "h" || input == "H" || input == "c" || input == "C");

        if(input == "h" || input == "H")
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

        if(players_.at(i).score() >= 80)
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

    if(!playRound())
    {
        return;
    }

}

void Game::deck()
{
    cout << deck_;
}

void Game::playRound()
{
   Table curent(); 

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
