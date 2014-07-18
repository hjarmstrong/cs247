#include <cstdlib>
#include <sstream>
#include <string>
#include "Game.h"

using namespace std;

int main (int argc, char *argv[])
{
    int rand = 0;
    if(argc > 1)
    {
        string argsrand = argv[1];
        istringstream args(argsrand);
        args >> rand;
    }
    
   srand48(rand);


    Game theGame;  //Need to get human players here.
    std::stringstream events;
    try
    {
    theGame.play(events);
    }
    catch(const char *)
    {
        // Recieved quit command
        return 0;
    }
    return 0;
}
