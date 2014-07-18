#include <cstdlib>
#include <sstream>
#include <string>
#include "Game.h"

using namespace std;

int main (int argc, char *argv[])
{

    bool cxr[4] = {false, false, false, false};
    Game theGame(cxr);  //Need to get human players here.
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
