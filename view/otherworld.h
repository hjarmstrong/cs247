#ifndef __OTHER_WORLD_H
#define __OTHER_WORLD_H
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/label.h>
#include <vector>

#include "DeckGUI.h"

class OtherWorld : public Gtk::Window {
public:
	OtherWorld();
	virtual ~OtherWorld();
	
private:
    //Signal Handelers
    virtual void newGameAction();

	DeckGUI                         deck;             // Knows all of the card pixel buffers.
	
	// Member widgets:
    Gtk::HBox                       commandButtons;
    Gtk::Button                     newGame;
    Gtk::Button                     rageQuit;
    Gtk::Button                     quit;
    Gtk::Button                     quitGame;
    Gtk::Label                      currentTurn;
    Gtk::Label                      currentAction;

    Gtk::HBox                       scores;
    Gtk::Frame                      scoreboard;

    Gtk::Label                      player1;
    Gtk::Label                      player2;
    Gtk::Label                      player3;
    Gtk::Label                      player4;


	Gtk::Image                    * cards[4][13];          // Images to display.
	Gtk::Image                    * hand[13];          // Images to display.
	Gtk::Button                     button[13];           // Button that will hold card images.
	std::vector<Gtk::HBox*>         hbox;             // Horizontal box for aligning widgets in the window.
    Gtk::VBox                       vbox;             // vertical box for all the controles
	Gtk::Frame                      frame;            // Create a nice framed border for the box.
}; // OtherWorld

#endif
