#include "Controller.h"
#include <Model.h>
#include <Card.h>


Controller::Controller(Model *m) : model(m)
{
}
  
void Controller::cardButtonClicked(Card c) const  //Calls either the play or discard method depending on card c and whether a card can be played
{
    model->select(c);
}

void Controller::endGameAction() const //Ends the current game, resetting the board back to its empty state
{
    model->endGame();
}

void Controller::rageQuitAction() const //Changes the human player who clicks it into a human
{
    model->ragequit();
}

void Controller::newGameAction(int seed, bool *playerAI) const //Begins a new game, opens the dialog box requesting whether each player is human and the random seed value
{
    model->newGame(seed, playerAI);
}
