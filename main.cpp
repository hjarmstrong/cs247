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
        printf(" ARG IS %d\n", rand);
    }
    
    Game theGame(rand);
    theGame.play();
    return 0;
}
