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
#include <observer.h>

class Model;
class Controller;

class View : public Gtk::Window , public Observer
{
public:
	View(Model *);
	virtual ~View();
    virtual void update();	// Observer Pattern: concrete update() method

private:

	// Observer Pattern: to access Model accessors without having to downcast subject
	Model *model;
	
	// Strategy Pattern member (plus signal handlers)
	Controller *controller;

	// Signal handlers:
    void newGameAction();
    void cardButtonClicked(int);
    void quitButtonClicked();
	
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


	Gtk::Image                    * cardsIMG[4][13];          // Images to display.
    Card                          * cardReferences[13];  
	Gtk::Image                    * hand[13];          // Images to display.
	Gtk::Button                     button[13];           // Button that will hold card images.
	std::vector<Gtk::HBox*>         hbox;             // Horizontal box for aligning widgets in the window.
    Gtk::VBox                       vbox;             // vertical box for all the controles
	Gtk::Frame                      frame;            // Create a nice framed border for the box.
};

#endif
