#include "Model.h"
#include <Command.h>
#include <Card.h>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

void Model::newGame(int seed, bool players[])
{
    // It is safe to delete NULL
    delete currentGame;

    srand48(seed);
    currentGame = new Game(players);
    currentGame->play(events);
    while( !currentGame->humanTurnNext() )
    {
        currentGame->playTurn(Command(), events);
    }
    notify();
}



//quit(); // check with example.

void Model::ragequit()
{
    Command c;
    c.type = RAGEQUIT;
    currentGame->playTurn(c, events);
   
    while( !currentGame->humanTurnNext() )
    {
        currentGame->playTurn(Command(), events);
    }
    notify();
}

void select (Card c)
{
    Command com;
    com.card = c;

    if( currentGame->getNextAction() == String("play") )
    {
        com.type = PLAY;
    }
    else
    {
        com.type = DISCARD;
    }
    
    currentGame->playTurn(com, events);

    
    while ( !currentGame->humanTurnNext() && !currentGame->roundOver() )
    {
        currentGame->playTurn(command(), events);
    }

    if( currentGame->roundOver() )
    {
        score(events);
        if( currentGame->gameOver() )
        {
            delete currentGame;
        }
        else
        {
            currentGame->play(events);
        }
    }

    notify();
}

const vector<string> Model::dialogMessages() const
{
    string message;
    vector<string> messages;
    while( !events.eof() )
    {
        getline(message, events);
        messages.push_back(message);
    }

}

const Table *currentTable() const
{
    return currentGame->table();
}

const std::vector<Card *> &hand() const
{
    return currentGame->currentPlayer()->hand();
}

const std::string currentPlayer() const
{
    return "player 7";
}

const std::string currentAction() const
{
    return currentGame->getNextAction();
}
