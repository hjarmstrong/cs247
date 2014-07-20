#include "HumanPlayer.h"
#include "Card.h"
#include "Command.h"
#include <cassert>

using namespace std;

HumanPlayer::HumanPlayer() : Player() {} //Human players are players

bool HumanPlayer::turn(std::vector<Card> legal, Deck *deck, Table *table, Command op) //Get the current table and hand, if at least one card can be played, play one of them otherwise discard.  
                                                                                      //If they choose to view the deck, quit or ragequit, call their respective functions 
{
   cout << *table << endl;  //Print the table and hand
   cout << "Your Hand:";
   for(unsigned int i = 0; i < hand().size(); i++)
   {
       cout << " " << *hand().at(i);
   }
   cout << endl;

   cout << "Legal Plays:"; //Alert the player of their legal plays
   for(unsigned int i = 0; i < legal.size(); i++)
   {
       cout << " " << legal.at(i);
   }
   cout << endl;

//   while(!cin.eof())
//   {
       //Command op;
       cout << ">";
       //cin >> op;
       assert(op.type != BAD_COMMAND);
       switch(op.type)  
       {
           case PLAY: //Play the selected card
           {
                for(unsigned int i = 0; i < legal.size(); i++)
                {
                    if(op.card == legal.at(i))
                    {
                        cout << "Player " << id() << " plays " << op.card << "." << endl;
                        play(op.card);
                        table->playCard(op.card);
                        return true;
                    }
                }
                
                cout << "This is not a legal play." << endl;
                return false;
           }
           case DISCARD: //Discard the selected card if no cards can be played, otherwise froce a card to be played
           {
               if(!legal.empty())
               {
                   cout << "You have a legal play. You may not discard." << endl;
                   return false;
               }
               else
               {
                   cout << "Player " << id() << " discards " << op.card << "." << endl;
                   discardCard(op.card);
                   return true;
               }
               break;
           }
           case DECK: //Print the deck
           {
               cout << *deck << endl; 
               break;
           }
           case QUIT: //Exit the game and window
           {
               throw("Exiting to the main Function");
               break;
           }
           case RAGEQUIT: //Change the human to a computer
           {
               cout << "Player " << id() << " ragequits. A computer will now take over." << endl;
               //We throw an exception of the player number
               throw(id());
               break;
           }
           case BAD_COMMAND:
           {
               assert(false);
               break;
           }
       }
  // }
  return true;
}

bool HumanPlayer::isHuman() const //Human players are human
{
    return true;
}
