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

Game::Game(bool humanPlayers[]) : deck_(new Deck), currentTable(NULL), roundOver_(false), gameOver_(false) //Initialize a new game given inputs from the view
{
    legalPlays.push_back(Card(SPADE,SEVEN)); //Define the first only legal play to be the seven of spades

    string input;

    for(int i = 1; i <= kNumPlayers; i++) // Get whether each of our k players are human
    {
        cout << "Is player " << i << " a human(h) or a computer(c)?" << endl << ">";

        if(humanPlayers[i-1] == true)
        {
            cout << "ok, player " << i << "Is a human" << endl;
            players_.push_back(new HumanPlayer);
        }
        else
        {
            cout << "ok, player" << i << "Is a Computer" << endl;
            players_.push_back(new ComputerPlayer);
        }
    }
}

Game::~Game() //Delete all of the players, the deck and table
{
    for(vector<Player *>::iterator it = players_.begin(); it != players_.end(); it++)
    {
        delete *it;
    }
    
    delete deck_;
    delete currentTable;
}

void Game::play(stringstream &events) //Initialize a new round to be played, deal the deck, determine who starts and let them play first
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

void Game::score(stringstream &events) //Get the discarded cards and tally total points for the round.  Check if anyone has >=80 points, and if they do, return the winner(s) who have the lowest score
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

    for(int i = 0; i < players_.size(); i++) //Check each player's score, and if it is our current lowest store their id and score
    {
        if(players_.at(i)->currentScore() < lowestScore)
        {
            lowestOwner.clear();
            lowestScore = players_.at(i)->currentScore();
            lowestOwner.push_back(i + 1);
        }
        if(players_.at(i)->currentScore() == lowestScore) //If their score is the same as the current lowest, add their id to the pool
        {
            lowestOwner.push_back(i + 1);
        }

        if(players_.at(i)->currentScore() >= 80) //If anyone's score is 80 or higher, the game is over
        {
            gameOver_ = true;
        }
    }

    if(gameOver_ == true)
    {
        for(vector<int>::iterator it = lowestOwner.begin(); it != lowestOwner.end(); it++) //If the game is over, return the winner(s)
        {
            events << "Player " << *it << " wins!" << endl;
            return;
        }
    }
    else
    {
        play(events); //Otherwise, just play another round
    }
}


void Game::playTurn(Command op, stringstream &events) //Get the set of legal moves for the turn player and request them to take their turn
{
    computeLegal();

    try
    {
        if( players_.at(turn())->turn(legalPlays, deck_, currentTable, op) )
            totalTurn++;
    }
    catch(int player) //If there is an error, then turn them intoa computer and let them play instead
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

void Game::computeLegal() //Determine the legal set of cards that could be played from the current player's hand 
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

void Game::computeLegal(int playerNumber)  //Determine the legal set of cards the could be played from a specific player's hand
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

string Game::getNextAction() //If there are legal cards to be played, the next action is play, otherwise it must discard
{
    if(legalPlays.size() > 0)
    {
        return "play";
    }
    
    return "discard";
}

bool Game::humanTurnNext() const //Return whether or not the next player is human
{
    return players_.at(turn())->isHuman();
}

const Player * const Game::currentPlayer() const //Get the current player
{
     return players_.at(turn());
}

bool Game::gameOver() //Accessor
{
    return gameOver_;
}

bool Game::roundOver() //Accessor
{
    return roundOver_;
}

Table *Game::table() //Accessor
{
    return currentTable;
}

int Game::turn() const //The total number of turns that have passed, plus the player who went first, mod the number of players return the player who's turn it is
{
    return (totalTurn + playerTurn) % players_.size();
}

const vector<Player *> &Game::players() const //Accessor
{
    return players_;
}

const vector<Card> Game::legalMoves() const //Accessor
{
    return legalPlays;
}
