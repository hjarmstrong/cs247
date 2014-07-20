CXX = g++
CXXFLAGS = -Wall -g -fPIC -MMD
LDFLAGS = -shared
OBJECTS = Card.o Deck.o Command.o Player.o ComputerPlayer.o HumanPlayer.o Table.o Game.o
DEPENDS = ${OBJECTS:.o=.d}
#SO = ../liblogic.so
STATIC = ../liblogic.a

#all : ${SO}
all : ${STATIC}
${STATIC} : ${OBJECTS}
	ar rvs ${STATIC} ${OBJECTS} 

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${STATIC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
