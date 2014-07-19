CXX = g++
CXXFLAGS = -Wall -g -MMD
OBJECTS = main.o
DEPENDS = ${OBJECTS:.o=.d}
EXE = straights_ui

${EXE} : ${OBJECTS}; \
    make ./logic/Makefile; \
    make ./model/Makefile; \
    make ./view/Makefile; \
    ${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXE}

clean : ; \
    make clean ./logic/Makefile; \
    make clean ./model/Makefile; \
    make clean ./view/Makefile; \
	rm -rf ${DEPENDS} ${OBJECTS} ${EXE}

-include ${DEPENDS} # reads the .d files and reruns dependencies
