CXX= g++
#CXXFLAGS = -g `/opt/local/bin/pkg-config gtkmm-2.4 --cflags --libs`
CXXFLAGS = -Wall -I../model -I../logic -O -g -fPIC -MMD `pkg-config gtkmm-2.4 --cflags --libs`
LDFLAGS = -shared
OBJS = DeckGUI.o View.o MyDialogBox.o
DEPENDS = ${OBJS:.o=.d}
SO = libview.so

all : ${SO}

$(SO): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $@ $(LDFLAGS)

clean:
	rm ${DEPENDS} ${SO} $(OBJS)

