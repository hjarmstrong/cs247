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

Game::Game(bool humanPlayers[]) : deck_(new Deck), currentTable(NULL), roundOver_(false), gameOver_(false)  //This somehow needs to be passed a bool humanPlayers[] from main.
{
    legalPlays.push_back(Card(SPADE,SEVEN));

    string input;

    for(int i = 1; i <= kNumPlayers; i++)
    {
        cout << "Is player " << i << " a human(h) or a computer(c)?" << endl << ">";
        //cin >> input;

        //assert(input == "h" || input == "H" || input == "c" || input == "C");

        if(humanPlayers[i-1] == true)
        {
            cout << "ok, player " << i << "Is a human" << endl;
            players_.push_back(new HumanPlayer);
        }
        else
        {
            cout << "ok, plyaer" << i << "Is a Computer" << endl;
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

void Game::play(stringstream &events)
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
    cout << "A new round begins. It's player " << playerTurn + 1  << "'s turn to play." << endl;
    currentTable = new Table;
    totalTurn = 0;
    roundOver_ = false;

}

void Game::score(stringstream &events)
{
    for(int i = 0; i < kNumPlayers; i++)
    {
		events << "Player " << i + 1 << "'s discards:";
		for(vector<Card>::const_iterator it = players_.at(i)->discard().begin(); it != players_.at(i)->discard().end(); it++)
		{
			events << " " << *it;
		}

		events << endl << "Player " << i + 1 << "'s score: " << players_.at(i)->oldScore() << " + " << players_.at(i)->currentScore() - players_.at(i)->oldScore() << " = " << players_.at(i)->currentScore() << endl;
		players_.at(i)->setOldScore(players_.at(i)->currentScore());
	}
    

    int lowestScore = numeric_limits<int>::max();
    vector<int> lowestOwner;
    lowestOwner.push_back(-1);

    for(int i = 0; i < players_.size(); i++)
    {
        if(players_.at(i)->currentScore() < lowestScore)
        {
            lowestOwner.clear();
            lowestScore = players_.at(i)->currentScore();
            lowestOwner.push_back(i + 1);
        }
        if(players_.at(i)->currentScore() == lowestScore)
        {
            lowestOwner.push_back(i + 1);
        }

        if(players_.at(i)->currentScore() >= 80)
        {
            gameOver_ = true;
        }
    }

    if(gameOver_ == true)
    {
        for(vector<int>::iterator it = lowestOwner.begin(); it != lowestOwner.end(); it++)
        {
            events << "Player " << *it << " wins!" << endl;
            return;
        }
    }
    else
    {
        play(events);
    }
}


void Game::playTurn(Command op, stringstream &events)
{
    computeLegal();

    try
    {
        if( players_.at(turn())->turn(legalPlays, deck_, currentTable, op) )
            totalTurn++;
    }
    catch(int player)
    {
        int id = players_.at(turn())->id();
        int Score = players_.at(turn())->currentScore();
        int oldScore = players_.at(turn())->oldScore();
        Player *computer = new ComputerPlayer(oldScore, Score, players_.at(turn())->hand(), players_.at(turn())->discard(), id);
        delete players_.at(turn());
        players_.at(turn()) = computer;
        computer->turn(legalPlays, deck_, currentTable, Command());
        totalTurn++;
    }

	computeLegal();
}    

void Game::computeLegal()
{   
    int oldTurn = turn();
    if(totalTurn == 52)
    {
        roundOver_ = true;
        return;
    }

    legalPlays.clear();

    set<Card> legal = currentTable->legalMoves();       

    for(int k = 0; k < players_.at(oldTurn)->hand().size(); k++)
    {
        if(legal.count(*players_.at(oldTurn)->hand().at(k)) != 0)
        {
            legalPlays.push_back(*players_.at(oldTurn)->hand().at(k));
        }
    }
}

void Game::computeLegal(int playerNumber)
{
    legalPlays.clear();

    set<Card> legal = currentTable->legalMoves();       

    for(int k = 0; k < players_.at(playerNumber)->hand().size(); k++)
    {
        if(legal.count(*players_.at(playerNumber)->hand().at(k)) != 0)
        {
            legalPlays.push_back(*players_.at(playerNumber)->hand().at(k));
        }
    }
}

string Game::getNextAction()
{
    if(legalPlays.size() > 0)
    {
        return "play";
    }
    
    return "discard";
}

bool Game::humanTurnNext() const
{
    return players_.at(turn())->isHuman();
}

const Player * const Game::currentPlayer() const
{
     return players_.at(turn());
}

bool Game::gameOver()
{
    return gameOver_;
}

bool Game::roundOver()
{
    return roundOver_;
}

Table *Game::table()
{
    return currentTable;
}

int Game::turn() const
{
    return (totalTurn + playerTurn) % players_.size();
}

const vector<Player *> &Game::players() const
{
    return players_;
}

const vector<Card> Game::legalMoves() const
{
    return legalPlays;
}
