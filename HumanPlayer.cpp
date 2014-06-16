#include "HumanPlayer.h"
#include "Card.h"
#include "Command.h"
#include <cassert>

using namespace std;

HumanPlayer::HumanPlayer() : Player() {}

void HumanPlayer::turn(std::vector<Card> legal, Deck &deck, Table &table)
{
   cout << table << endl;
   cout << "Your Hand:" << endl;
   for(unsigned int i = 0; i < hand().size(); i++)
   {
       cout << " " << *hand().at(i);
   }
   cout << endl;

   cout << "Legal Plays:" << endl;
   for(unsigned int i = 0; i < legal.size(); i++)
   {
       cout << " " << legal.at(i);
   }
   cout << endl;

   while(!cin.fail())
   {
       Command op;
       cout << ">";
       cin >> op;
       assert(op.type != BAD_COMMAND);
       switch(op.type)
       {
           case PLAY:
           {
                for(unsigned int i = 0; i < legal.size(); i++)
                {
                    if(op.card == legal.at(i))
                    {
                        cout << "Player " << id() << " plays " << op.card << "." << endl;
                        play(op.card);
                        return;
                    }
                }
                
                cout << "This is not a legal play." << endl;   
           }
           case DISCARD:
           {
               if(legal.empty())
               {
                   cout << "You have a legal play. You may not discard." << endl;
               }
               else
               {
                   cout << "Player " << id() << " discards " << op.card << "." << endl;
                   discard(op.card);
                   return;
               }
           }
           case DECK:
           {
               cout << deck << endl; 
           }
           case QUIT:
           {
               throw("Exiting to the main Function");
           }
           case RAGEQUIT:
           {
               //We throw an exception of the player number
               throw(id());
           }
           case BAD_COMMAND:
           {
               assert(false);
           }
       }
   }
}

