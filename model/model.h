#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"
#include <Card.h>
#include <Game.h>
#include <Player.h>
#include <Table.h>
#include <sstream>

class Model : public Subject
{
public:
    // Constructor
    Model();

    // GUI event handelers
    newgame(int seed);
    quit(); // check with example.
    ragequit();
    select(int card);

    // Data access for view
    
    const std::vector<string> dialogMessages() const;
    const Table *currentTable() const;
    const std::vector<Card *> &hand() const;
    const std::string currentPlayer() const;
    const std::string currentAction() const;
    
private:
    Game *currentGame;
    int round;
    stringstream events;
};


#endif
