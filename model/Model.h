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
    void select(Card);

    // Data access for view
    
    // Flushes the dialog messages and returns them
    const std::vector<std::string> dialogMessages();

    // Accessors
    const Table *currentTable() const;
    const std::vector<Card *> &hand() const;
    const std::string currentPlayer() const;
    const std::string currentAction() const;
    
private:
    Game *currentGame;
    std::stringstream events;
};


#endif
