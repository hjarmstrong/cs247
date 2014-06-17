#include "Game.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Deck.h"
#include "Command.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <limits>

using namespace std;

Game::Game() : deck_(new Deck)
{
    string input;

    for(int i = 1; i <= 4; i++)
    {
        cout << "Is player " << i << " a human(h) or a computer(c)?" << endl << ">";
        cin >> input;

        assert(input == "h" || input == "H" || input == "c" || input == "C");

        if(input == "h" || input == "H")
        {
            players_.push_back(new HumanPlayer);
        }
        else
        {
            players_.push_back(new ComputerPlayer);
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

const std::vector<Player *> &Game::players() const
{
    return players_;
}

void Game::play()
{
    int lowestScore = numeric_limits<int>::max(), lowestOwner = -1;
    bool gameOver = false;

    while(gameOver == false)
    {
    for(int i = 0; i < players_.size(); i++)
    {
        if(players_.at(i)->currentScore() < lowestScore)
        {
            lowestScore = players_.at(i)->currentScore();
            lowestOwner = i + 1;
        }

        if(players_.at(i)->currentScore() >= 80)
        {
            gameOver = true;
        }
    }
    if(gameOver == true)
    {
        cout << "Player " << lowestOwner << " wins!" << endl;
        return;
    }

    deck_->shuffle();
    vector<Card *> hand;

    for(int k = 0; k < 4; k++)
    {
        for(int i = 0; i < 13; i++)
        {
            hand.push_back(deck_->deckList().at(i + 13*k));
        }
        players_.at(k)->deal(hand);
        hand.clear();
    }

    playRound();
    }
}

void Game::deck()
{
    cout << deck_;
}

void Game::playRound()
{
    int playerTurn;

    
    for(int it = 0; it < players_.size(); it++)
    {
        for(vector<Card *>::const_iterator ti = players_.at(it)->hand().begin(); ti != players_.at(it)->hand().end(); ti++)
        {
            if( (**ti).getRank() == SEVEN && (**ti).getSuit() == SPADE)
            {
                playerTurn = it; 
                goto escape;
            }
        }
    }

    escape:
    cout << "A new round begins. It's player " << playerTurn+1  << "'s turn to play." << endl;
    Table currentTable;
    for(int i = 0; i < 52; i++)
    {
        int turn = (i + playerTurn) % players_.size();

        set<Card> legal = currentTable.legalMoves();       
        vector<Card> currentLegal;

        for(int k = 0; k < players_.at(turn)->hand().size(); k++)
        {
            if(legal.count(*players_.at(turn)->hand().at(k)) != 0)
            {
                currentLegal.push_back(*players_.at(turn)->hand().at(k));
            }
        }
        try
        {
            players_.at(turn)->turn(currentLegal, *deck_, currentTable);
        }
        catch(int player)
        {
            int id = players_.at(player)->id();
        }
    }
    
    for(int i = 0; i < 4; i++)
    {
		cout << "Player " << i + 1 << "'s discards:";
		for(vector<Card *>::const_iterator it = players_.at(i)->discard().begin(); it != players_.at(i)->discard().end(); it++)
		{
			cout << " " << &it;
		}
		players_.at(i)->resetDiscard();
		cout << endl << "Player " << i + 1 << "'s score: " << players_.at(i)->oldScore() << " + " << players_.at(i)->currentScore() - players_.at(i)->oldScore() << " = " << players_.at(i)->currentScore() << endl;
		players_.at(i)->setOldScore(players_.at(i)->currentScore());
		
	}
    
}
