CXX = g++
CXXFLAGS = -Wall -g -I../logic -MMD
OBJECTS = Subject.o Model.o 
DEPENDS = ${OBJECTS:.o=.d}
EXEC = model

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
