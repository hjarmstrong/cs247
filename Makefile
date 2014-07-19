CXX = g++
CXXFLAGS = -Wall -g -MMD -I./model -I./logic -I./view -I./controller `pkg-config gtkmm-2.4 --cflags --libs`
LDFLAGS = -L. -lcontroller -lmodel -lview -llogic `pkg-config gtkmm-2.4 --cflags --libs`
OBJECTS = main.o
DEPENDS = ${OBJECTS:.o=.d}
EXE = straights_ui

all : ${EXE}
	
liblogic.so :
	make -C ./logic/
libmodel.so :
	make -C ./model/
libview.so :
	make -C ./view/
libcontroller.so :
	make -C ./controller/


${EXE} : ${OBJECTS} liblogic.so libmodel.so libview.so libcontroller.so
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXE} ${LDFLAGS}

clean :
	make -C ./logic/ clean
	make -C ./model/ clean
	make -C ./view/ clean
	make -C ./controller/ clean
	rm -rf ${DEPENDS} ${OBJECTS} ${EXE}

-include ${DEPENDS} # reads the .d files and reruns dependencies
