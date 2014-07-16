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
#include <sstream>

using namespace std;

Game::Game(bool humanPlayers[]) : deck_(new Deck), currentTable(NULL), gameOver(false)
{
    string input;

    for(int i = 1; i <= kNumPlayers; i++)
    {
        cout << "Is player " << i << " a human(h) or a computer(c)?" << endl << ">";
        //cin >> input;

        //assert(input == "h" || input == "H" || input == "c" || input == "C");

        if(humanPlayers[i] == true)
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
    delete currentTable;
}

void Game::play()
{
    deck_->shuffle();
    vector<Card *> hand;

    for(int k = 0; k < kNumPlayers; k++)
    {
        for(int i = 0; i < 13; i++)
        {
            hand.push_back(deck_->deckList().at(i + 13*k));
        }

        players_.at(k)->deal(hand);
        hand.clear();
    }

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
    events << "A new round begins. It's player " << playerTurn + 1  << "'s turn to play." << endl;
    currentTable = new Table;
    totalTurn = 0;

}

void Game::score(stringstream events)
{
    for(int i = 0; i < kNumPlayers; i++)
    {
		cout << "Player " << i + 1 << "'s discards:";
		for(vector<Card>::const_iterator it = players_.at(i)->discard().begin(); it != players_.at(i)->discard().end(); it++)
		{
			cout << " " << *it;
		}
		cout << endl << "Player " << i + 1 << "'s score: " << players_.at(i)->oldScore() << " + " << players_.at(i)->currentScore() - players_.at(i)->oldScore() << " = " << players_.at(i)->currentScore() << endl;
		players_.at(i)->setOldScore(players_.at(i)->currentScore());
	}
    

    int lowestScore = numeric_limits<int>::max();
    vector<int> lowestOwner;
    lowestOwner.push_back(-1);

    for(int i = 0; i < players_.size(); i++)
    {
        if(players_.at(i)->currentScore() < lowestScore)
        {
            lowestScore = players_.at(i)->currentScore();
            lowestOwner.at(0) = i + 1;
        }
        if(players_.at(i)->currentScore() == lowestScore)
        {
            lowestOwner.push_back(i + 1);
        }

        if(players_.at(i)->currentScore() >= 80)
        {
            gameOver = true;
        }
    }

    if(gameOver == true)
    {
        for(vector<int>::iterator it = lowestOwner.begin(); it != lowestOwner.end(); it++)
        {
            cout << "Player " << *it << " wins!" << endl;
            return;
        }
    }
}

vector<Card> *Game::playRound()
{   
    int turn = (totalTurn + playerTurn) % players_.size();

    set<Card> legal = currentTable.legalMoves();       
    vector<Card> *currentLegal = new vector<Card>;

    for(int k = 0; k < players_.at(turn)->hand().size(); k++)
    {
        if(legal.count(*players_.at(turn)->hand().at(k)) != 0)
        {
            currentLegal->push_back(*players_.at(turn)->hand().at(k));
        }
    }
    return currentLegal;
}

void Game::playTurn(Command op, stringstream &events)
{
    try
    {
        vector<Card> *currentLegal = playRound();

        if( players_.at(turn)->turn(*currentLegal, deck_, currentTable, op) )
            totalTurn++;

        delete currentLegal;
    }
    catch(int player)
    {
        totalTurn++;
        int id = players_.at(player - 1)->id();
        int Score = players_.at(player - 1)->currentScore();
        int oldScore = players_.at(player - 1)->oldScore();
        
        Player *computer = new ComputerPlayer(oldScore, Score, players_.at(player - 1)->hand(), players_.at(player - 1)->discard(), id);
        delete players_.at(player - 1);
        players_.at(player - 1) = computer;
        computer->turn(currentLegal, deck_, currentTable, Command());
    }
}    

bool Game::humanTurnNext() const
{
    int turn = (totalTurn + playerTurn) % players_.size();
    return players_.at(turn)->isHuman();
}

string Game::currentPlayer() const
{
}

