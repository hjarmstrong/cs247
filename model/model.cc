#include "model.h"
#include <Command.h>
#include <Card.h>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

void Model::newgame(int seed, bool players[])
{
    // It is safe to delete NULL
    delete currentGame;

    srand48(rand);
    currentGame = new Game(players);
    currentGame->play();
    while( !currentGame->humanTurnNext() )
    {
        currentGame->playTurn(Command(), events);
    }
    notify();
}



quit(); // check with example.

Model::ragequit()
{
    Command c;
    c.type = RAGEQUIT;
    currentGame->playRound(c, events);
   
    while( !currentGame->humanTurnNext() )
    {
        currentGame->playRound(Command(), events)
    }
    notify();
}

select (Card c)
{
    Command com;
    com.type = //implement next action method in game class
    com.card = c;

    currentGame->playRound(com, events);

    while ( !currentGame->humanTurnNext() )
    {
        currentGame->playRound(command(), events);
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

const std::vector<Card *> &hand() const;

const std::string currentPlayer() const;

const std::string currentAction() const;
 
