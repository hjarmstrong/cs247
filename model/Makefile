CXX = g++
CXXFLAGS = -Wall -g -fPIC -I../logic -MMD
LDFLAGS = -shared
OBJECTS = Subject.o Model.o 
DEPENDS = ${OBJECTS:.o=.d}
#SO = ../libmodel.so
STATIC = ../libmodel.a

all : ${STATIC}
${STATIC} : ${OBJECTS}
	 ar rvs ${STATIC} ${OBJECTS}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${STATIC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
