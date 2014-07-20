#include "Command.h"
#include <cassert>
#include <sstream>
using namespace std;

istream &operator>>(istream &in, Command &c){ //Assume default command is bad_command, then either play the next input's card, discard the next input's card, print the deck, quit or ragequit
	c.type = BAD_COMMAND;
	
	string cmd;
	in >> cmd;
	
	if (cmd == "play") {
		c.type = PLAY;
		in >> c.card;
	} else if (cmd == "discard") {
		c.type = DISCARD;
		in >> c.card;
	} else if (cmd == "deck") {
		c.type = DECK;
	} else if (cmd == "quit") {
		c.type = QUIT;
	} else if (cmd == "ragequit") {
		c.type = RAGEQUIT;
	}
	
	assert(!in.fail() && c.type != BAD_COMMAND);
	
	return in;
}
