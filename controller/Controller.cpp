#include "Controller.h"
#include <Model.h>
#include <Card.h>


Controller::Controller(Model *m) : model(m)
{
}
  
void Controller::cardButtonClicked(Card c) const
{
    model->select(c);
}

void Controller::endGameAction() const 
{
    model->endGame();
}

void Controller::rageQuitAction() const 
{
    model->ragequit();
}

void Controller::newGameAction(int seed, bool *playerAI) const
{
    model->newGame(seed, playerAI);
}
