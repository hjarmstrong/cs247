CXX= g++
CXXFLAGS = -Wall -I../model -I../logic -O -g -fPIC -MMD `pkg-config gtkmm-2.4 --cflags --libs`
LDFLAGS = -shared
OBJS = Controller.o
DEPENDS = ${OBJS:.o=.d}
SO = ../libcontroller.so

all : ${SO}

$(SO): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $@ $(LDFLAGS)

clean:
	rm ${DEPENDS} ${SO} $(OBJS)

