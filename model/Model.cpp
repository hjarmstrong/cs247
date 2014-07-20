#include "Model.h"
#include <Command.h>
#include <Card.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

Model::Model() : currentGame(NULL)  //Initializes the current game to NULL on construction
{
}

void Model::newGame(int seed, bool players[])  //Gets the random value and lets every computer play until it is a human's turn to move.  Then notify's the player of their options.
{
    // It is safe to delete NULL
    delete currentGame;
    cout << "SEED VALUE" << endl;
    cout << seed << endl;
    srand48(seed);

    currentGame = new Game(players);
    currentGame->play(events);
   
    nextHuman();
    
    notify();
}

void Model::ragequit()  // Converts the human player into a computer player
{
    if( currentGame == NULL)
        return;

    Command c;
    c.type = RAGEQUIT;
    currentGame->playTurn(c, events);
    
    nextHuman();

    notify();
}

void Model::select(Card c)  //Either plays or discards the card c, depending on available options
{
    Command com;
    com.card = c;

    if( currentGame->getNextAction() == string("play") )
    {
        com.type = PLAY;
    }
    else
    {
        com.type = DISCARD;
    }
    
    currentGame->playTurn(com, events);

    nextHuman();
        
    notify();
}

void Model::nextHuman() // Plays the computer players' turns until the next human player requires an action
{
    while ( !currentGame->humanTurnNext() || currentGame->roundOver() )
    {   
        if( currentGame->roundOver() )
        {
            currentGame->score(events);
            if( currentGame->gameOver() )
            {
                delete currentGame;
                currentGame = NULL;
                break;
            }          
        }
        if( !currentGame->humanTurnNext() )
        {
            currentGame->playTurn(Command(), events);
        }
    }
}

void Model::endGame()  //Deletes the old game and sets it to NULL
{
    delete currentGame;
    currentGame = NULL;
    notify();
}

const vector<string> Model::dialogMessages() //Create the vector of messages that need to be displayed in dialog boxes
{
    string message;
    vector<string> messages;
    while( !events.eof() )
    {
        getline(events, message);
        messages.push_back(message);
    }
    events.clear();
    return messages;
}

const Table *Model::currentTable() const //Returns the current table
{
    if(currentGame != NULL)
        return currentGame->table();
    
    
    return NULL;
    
}

const std::vector<Card *> &Model::hand() const //Returns the current player's hand
{
    if(currentGame != NULL)
        return currentGame->currentPlayer()->hand();

    throw("No Game in Progress");
}

const std::string Model::currentPlayer() const //Gets the current player in the turn order
{
    stringstream ss;
    ss << "Player " << currentGame->turn() + 1;
    string ret = ss.str();
    return ret;
}

const std::string Model::currentAction() const //Gets the next action to take, either play or discard
{
    return currentGame->getNextAction();
}

string *Model::currentScoreBoard() const // Creates the messages detailing the round's scores for each player
{
    string *ret = new string[4];
    for(int i = 0; i < 4; i++)
    {
        int discardInt = currentGame->players().at(i)->discard().size();
        int scoreInt = currentGame->players().at(i)->oldScore();

        stringstream ss;
        ss << "Player "<< i + 1 <<" \n Score: " << scoreInt << "\n Discards: " << discardInt;

        ret[i] = ss.str();

    } 
    return ret;
}

const vector<Card> Model::legalCards() const //Returns the vector of legal cards that can be played this turn
{
    return currentGame->legalMoves();
}
