CXX = g++
CXXFLAGS = -Wall -g -fPIC -I../logic -MMD
LDFLAGS = -shared
OBJECTS = Subject.o Model.o 
DEPENDS = ${OBJECTS:.o=.d}
SO = model.so

all : ${SO}
${SO} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o $@ $(LDFLAGS)

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${SO}

-include ${DEPENDS} # reads the .d files and reruns dependencies
