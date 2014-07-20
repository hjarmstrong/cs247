CXX= g++
CXXFLAGS = -Wall -I../model -I../logic -O -g -fPIC -MMD `pkg-config gtkmm-2.4 --cflags --libs`
LDFLAGS = -shared
OBJS = Controller.o
DEPENDS = ${OBJS:.o=.d}
#SO = ../libcontroller.so
STATIC = ../libcontroller.a
#all : ${SO}
all : ${STATIC}

${STATIC} : ${OBJS}
	ar rvs ${STATIC} ${OBJS}

#$(SO): $(OBJS)
#	$(CXX) $(OBJS) $(CXXFLAGS) -o $@ $(LDFLAGS)

clean:
	rm ${DEPENDS} ${STATIC} $(OBJS)

