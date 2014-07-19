CXX = g++
CXXFLAGS = -Wall -g -MMD -I./model -I./logic -I./view  `pkg-config gtkmm-2.4 --cflags --libs`
LDFLAGS = -L./model/ -L./view/ -L./logic -lmodel -lview -llogic `pkg-config gtkmm-2.4 --cflags --libs`
OBJECTS = main.o
DEPENDS = ${OBJECTS:.o=.d}
EXE = straights_ui

${EXE} : ${OBJECTS}
	make -C ./logic/
	make -C ./model/
	make -C ./view/
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXE} ${LDFLAGS}

clean :
	make -C ./logic/ clean
	make -C ./model/ clean
	make -C ./view/ clean
	rm -rf ${DEPENDS} ${OBJECTS} ${EXE}

-include ${DEPENDS} # reads the .d files and reruns dependencies
