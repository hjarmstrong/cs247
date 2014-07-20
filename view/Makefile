CXX= g++
#CXXFLAGS = -g `/opt/local/bin/pkg-config gtkmm-2.4 --cflags --libs`
CXXFLAGS = -Wall -I../model -I../logic -I../controller -O -g -fPIC -MMD `pkg-config gtkmm-2.4 --cflags --libs`
LDFLAGS = -shared
OBJS = DeckGUI.o View.o MyDialogBox.o
DEPENDS = ${OBJS:.o=.d}
#SO = ../libview.so
STATIC = ../libview.a

#all : ${SO}
all : ${STATIC}

#$(SO): $(OBJS)
#	$(CXX) $(OBJS) $(CXXFLAGS) -o $@ $(LDFLAGS)

$(STATIC): $(OBJS)
	 ar rvs ${STATIC} ${OBJS} 

clean:
	rm ${DEPENDS} ${STATIC} $(OBJS)

