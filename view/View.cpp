#include "View.h"
#include "MyDialogBox.h"
#include <Card.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <vector>
#include <iostream>

using namespace std;

// Sets the horizontal box to have homogeneous spacing (all elements are of the same size), and to put 10 pixels
// between each widget. Initializes the pixel buffer for the null place holder card, and the 10 of spades.
// Puts a frame in the window, and lays out the widgets horizontally. Four widgets are images, the fifth is a button
// with an image in it.
//
// Since widgets cannot be shared, must use pixel buffers to share images.
View::View() : commandButtons(true, 10), scores( true, 10 ), vbox( true, 10) 
{
    for(int i = 0; i <= 7; i++)
    {
        Gtk::HBox *h = new Gtk::HBox(true, 10);
        hbox.push_back(h);
    }
		
	const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();
	const Glib::RefPtr<Gdk::Pixbuf> cardPixbuf     = deck.getCardImage( Card(SPADE, SEVEN) );
	
	// Sets the border width of the window.
    set_title("Straights Card Game");
	set_border_width( 10 );
		
	// Set the look of the frame.
	frame.set_label("Game Actions:");
	frame.set_label_align( Gtk::ALIGN_CENTER, Gtk::ALIGN_TOP );
	frame.set_shadow_type( Gtk::SHADOW_ETCHED_OUT );
	
	// Add the frame to the window. Windows can only hold one widget, same for frames.
	add( vbox );
	
	// Add the vertical box for laying out the images to the frame.

    for (int i = 0; i <= 7; i++)
    {
        vbox.add(*hbox.at(i));
    }

    newGame.set_label("Start New Game");
    newGame.signal_clicked().connect( sigc::mem_fun( *this, &View::newGameAction ) );

    rageQuit.set_label("RageQuit");
    quitGame.set_label("End Current Game");
    quit.set_label("Quit");

    commandButtons.add(newGame);
    commandButtons.add(rageQuit);
    commandButtons.add(quitGame);

    frame.add(commandButtons);

    hbox.at(0)->add(frame);
	
    
    currentTurn.set_label("It is Player 1's Turn to Play");
    currentAction.set_label("You must discard");
    hbox.at(5)->add(currentTurn);
    hbox.at(5)->add(currentAction); 
	// Initialize 4 empty cards and place them in the box.

    scoreboard.set_label("Score Board");
	scoreboard.set_label_align( Gtk::ALIGN_CENTER, Gtk::ALIGN_TOP );
	scoreboard.set_shadow_type( Gtk::SHADOW_ETCHED_OUT );
    scoreboard.add(scores);
    
    player1.set_label("Player 1 \n Score:  \n Discards");
    player2.set_label("Player 2 \n Score:  \n Discards");  
    player3.set_label("Player 3 \n Score:  \n Discards");
    player4.set_label("Player 4 \n Score:  \n Discards");  
    
    scores.add(player1);
    scores.add(player2);
    scores.add(player3);
    scores.add(player4);

    hbox.at(7)->add(scoreboard);

    for (int i = 1; i <=4; i++) {
	for (int j = 0; j < 13; j++ ) {
        cards[i-1][j] = new Gtk::Image( nullCardPixbuf  );
		hbox.at(i)->add( *cards[i-1][j] );
	} 
    }
	
	for(int i = 0; i < 13; i++)
    {
	    hand[i] = new Gtk::Image( cardPixbuf );	
	    button[i].set_image( *hand[i] );
    }
			
	// Add the button to the box.
    for(int i = 0; i < 13; i++)
	    hbox.at(6)->add( button[i] );

    //Connecting signals
    for(int i = 0; i < 13; i++)
    {
       button[i].signal_clicked().connect( sigc::bind<int>( sigc::mem_fun(*this, &View::cardButtonClicked), i) );
	}


	// The final step is to display this newly created widget.
	show_all();

//	model->subscribe(this);

}

void View::update() 
{
    for (int i = 1; i <=4; i++) 
    {
        for (int j = 0; j < 13; j++ ) 
        {
        } 
    }
}

void View::cardButtonClicked(int i)
{
    cout << i << endl;
//  controller_->nextButtonClicked();
}

void View::quitButtonClicked() 
{
//  controller_->resetButtonClicked();
}

View::~View() 
{
	for (int i = 0; i < 4; i++ ) 
    for (int j = 0; j < 13; j++) 
        delete cards[i][j];

    for(vector<Gtk::HBox*>::iterator it = hbox.begin(); it != hbox.end(); it++)
    {
        delete *it;
    }
}

void View::newGameAction()
{
    MyDialogBox dialog( *this, "Set up Parameters:" );
}
