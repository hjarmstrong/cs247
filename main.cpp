#include <cstdio>
#include <sstream>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{

    int rand = 0;
    if(argc > 1)
    {
        string argsrand = argv[1];
        istringstream args(argsrand);
        args >> rand;
        srand48(rand);
    }
    
    Game theGame();
    theGame.play();
    return 0;
}
