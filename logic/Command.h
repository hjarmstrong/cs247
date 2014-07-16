#ifndef _COMMAND_
#define _COMMAND_

#include "Card.h"
#include <istream>

enum Type { PLAY, DISCARD, DECK, QUIT, RAGEQUIT, BAD_COMMAND };

struct Command{
	Type type;
	int index;
	
	Command() : type(BAD_COMMAND), index(-1) {}
};

std::istream &operator>>(std::istream &, Command &);

#endif
