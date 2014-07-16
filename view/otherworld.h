#ifndef __OTHER_WORLD_H
#define __OTHER_WORLD_H
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <vector>

#include "DeckGUI.h"

class OtherWorld : public Gtk::Window {
public:
	OtherWorld();
	virtual ~OtherWorld();
	
private:
	DeckGUI                         deck;             // Knows all of the card pixel buffers.
	
	// Member widgets:
	Gtk::Image                    * cards[4][13];          // Images to display.
	Gtk::Image                    * hand[13];          // Images to display.
	Gtk::Button                     button[13];           // Button that will hold card images.
	std::vector<Gtk::HBox*>          hbox;             // Horizontal box for aligning widgets in the window.
    Gtk::VBox                       vbox;             // vertical box for all the controles
	Gtk::Frame                      frame;            // Create a nice framed border for the box.
}; // OtherWorld

#endif
