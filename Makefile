CXX = g++
CXXFLAGS = -Wall -g -MMD
OBJECTS = main.o Card.o Deck.o Command.o Player.o ComputerPlayer.o HumanPlayer.o Table.o Game.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = Straights

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
