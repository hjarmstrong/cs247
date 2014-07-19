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
    void endGame(); 
    void ragequit();
    void select(Card);
    void nextHuman();

    // Data access for view
    
    // Flushes the dialog messages and returns them
    const std::vector<std::string> dialogMessages();

    // Accessors
    const Table *currentTable() const;
    const std::vector<Card *> &hand() const;
    const std::vector<Card> legalCards() const;
    const std::string currentPlayer() const;
    const std::string currentAction() const;
    std::string *currentScoreBoard() const;
    
private:
    Game *currentGame;
    std::stringstream events;
};


#endif
