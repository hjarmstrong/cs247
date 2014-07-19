#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H


#include <gtkmm.h>
#include <Card.h>

class Model;

class Controller 
{
public:
   Controller( Model* );

   void cardButtonClicked(Card) const;
   void newGameAction(int, bool*) const;
   void rageQuitAction() const;
   void endGameAction() const; 

private:
   Model *model;
};

#endif

