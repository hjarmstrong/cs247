CXX= g++
#CXXFLAGS = -g `/opt/local/bin/pkg-config gtkmm-2.4 --cflags --libs`
CXXFLAGS = -Wall -I../logic -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = DeckGUI.o View.o driver.o MyDialogBox.o
EXEC = other

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) ../logic/Card.o $(CXXFLAGS) -o $(EXEC)

DeckGUI.o: DeckGUI.h DeckGUI.cc
View.o: View.h View.cpp
driver.o: View.h driver.cc

clean:
	rm $(EXEC) $(OBJS)
