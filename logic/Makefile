CXX = g++
CXXFLAGS = -Wall -g -fPIC -MMD
LDFLAGS = -shared
OBJECTS = main.o Card.o Deck.o Command.o Player.o ComputerPlayer.o HumanPlayer.o Table.o Game.o
DEPENDS = ${OBJECTS:.o=.d}
SO = logic.so

all : ${SO}
${SO} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o $@ $(LDFLAGS)

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${SO}

-include ${DEPENDS} # reads the .d files and reruns dependencies
