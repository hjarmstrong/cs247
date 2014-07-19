#include "Model.h"
#include <Command.h>
#include <Card.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

Model::Model() : currentGame(NULL)
{
}

void Model::newGame(int seed, bool players[])
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

void Model::ragequit()
{
    if( currentGame == NULL)
        return;

    Command c;
    c.type = RAGEQUIT;
    currentGame->playTurn(c, events);
    
    nextHuman();

    notify();
}

void Model::select(Card c)
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

void Model::nextHuman()
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
            else
            {
                currentGame->play(events);
            }
        }
        if( !currentGame->humanTurnNext() )
        {
            currentGame->playTurn(Command(), events);
        }
    }
}

void Model::endGame()
{
    delete currentGame;
    currentGame = NULL;
    notify();
}

const vector<string> Model::dialogMessages()
{
    string message;
    vector<string> messages;
    while( !events.eof() )
    {
        getline(events, message);
        messages.push_back(message);
    }
    return messages;
}

const Table *Model::currentTable() const
{
    if(currentGame != NULL)
        return currentGame->table();
    
    
    return NULL;
    
}

const std::vector<Card *> &Model::hand() const
{
    if(currentGame != NULL)
        return currentGame->currentPlayer()->hand();

    throw("No Game in Progress");
}

const std::string Model::currentPlayer() const
{
    stringstream ss;
    ss << "Player " << currentGame->turn() + 1;
    string ret = ss.str();
    return ret;
}

const std::string Model::currentAction() const
{
    return currentGame->getNextAction();
}

int *Model::currentScore() const
{
    int *ret = new int[4];
    for(int i = 0; i < 4; i++)
    {
        ret[i] = currentGame->players().at(i)->currentScore();
    } 
}

int *Model::currentDiscards() const 
{
    int *ret = new int[4];
    for(int i = 0; i < 4; i++)
    {
        ret[i] = currentGame->players().at(i)->discard().size();
    }
}

