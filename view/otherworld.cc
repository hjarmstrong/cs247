#include "otherworld.h"
#include <Card.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>

// Sets the horizontal box to have homogeneous spacing (all elements are of the same size), and to put 10 pixels
// between each widget. Initializes the pixel buffer for the null place holder card, and the 10 of spades.
// Puts a frame in the window, and lays out the widgets horizontally. Four widgets are images, the fifth is a button
// with an image in it.
//
// Since widgets cannot be shared, must use pixel buffers to share images.
OtherWorld::OtherWorld() : vbox( true, 10 ) 
{
    for(int i = 0; i <= 8; i++)
    {
        Gtk::HBox *h = new Gtk::HBox(true, 10);
        hbox.push_back(h);
    }
		
	const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();
	const Glib::RefPtr<Gdk::Pixbuf> cardPixbuf     = deck.getCardImage( Card(SPADE, SEVEN) );
	
	// Sets the border width of the window.
	set_border_width( 10 );
		
	// Set the look of the frame.
	frame.set_label( "Cards:" );
	frame.set_label_align( Gtk::ALIGN_CENTER, Gtk::ALIGN_TOP );
	frame.set_shadow_type( Gtk::SHADOW_ETCHED_OUT );
	
	// Add the frame to the window. Windows can only hold one widget, same for frames.
	add( frame );
	
	// Add the horizontal box for laying out the images to the frame.
	frame.add( vbox );

    for (int i = 0; i <=8; i++)
    {
        vbox.add(*hbox.at(i));
    }
	
	// Initialize 4 empty cards and place them in the box.

    for (int i = 1; i <=4; i++) {
	for (int j = 0; j < 13; j++ ) {
		cards[i-1][j] = new Gtk::Image( nullCardPixbuf );
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
	
	// The final step is to display this newly created widget.
	show_all();
} // OtherWorld::OtherWorld

OtherWorld::~OtherWorld() {
	for (int i = 0; i < 4; i++ ) 
    for (int j = 0; j < 13; j++) 
        delete cards[i][j];
} // OtherWorld::~OtherWorld()
