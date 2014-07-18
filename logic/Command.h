#ifndef _COMMAND_
#define _COMMAND_

#include "Card.h"
#include <istream>

enum Type { PLAY, DISCARD, DECK, QUIT, RAGEQUIT, BAD_COMMAND };

struct Command{
	Type type;
	int index;

	Card card;
	
	Command() : type(BAD_COMMAND), index(-1), card(SPADE,SEVEN) {}
};

std::istream &operator>>(std::istream &, Command &);

#endif
