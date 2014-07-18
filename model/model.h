#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"
#include <Card.h>
#include <Game.h>
#include <Player.h>
#include <Table.h>
#include <sstream>
#include <string>

class Model : public Subject
{
public:
    // Constructor
    Model();

    // GUI event handelers
    void newGame(int seed, bool*);
    void quit(); // check with example.
    void ragequit();
    void select(int card);

    // Data access for view
    
    const std::vector<std::string> dialogMessages() const;
    const Table *currentTable() const;
    const std::vector<Card *> &hand() const;
    const std::string currentPlayer() const;
    const std::string currentAction() const;
    
private:
    Game *currentGame;
    int round;
    std::stringstream events;
};


#endif
