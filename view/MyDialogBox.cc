/*
 *  MyDialogBox.cc
 *
 *  Created by Caroline Kierstead on 28/05/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */
#include "MyDialogBox.h"
#include <gtkmm/stock.h>
#include <gtkmm/entry.h>
#include <iostream>
#include <string>

using namespace std;

// Specifies the parent window of the dialog box and the title of the dialog box.
MyDialogBox::MyDialogBox( Gtk::Window & parentWindow, string title) : Dialog( title, parentWindow, true, true ) {
	vector<string> messages;
	messages.push_back( "Player 1 is a Human" );
	messages.push_back( "Player 2 is a Human" );
	messages.push_back( "Player 3 is a Human" );
	messages.push_back( "Player 4 is a Human" );
	
	// Obtain the dialog box's vertical alignment box.
	Gtk::VBox* contentArea = this->get_vbox();
	
	// Set up a group of radio buttons, one per card in human player's hand plus the top card of the kitty.
	for ( int i = 0; i < messages.size(); i++ ) {
		buttons.push_back(  new Gtk::CheckButton( messages[i] )  );
		contentArea->add( *buttons[i] );
	}
    
    seedInfo.set_text("Random Seed Value:");
    contentArea->add(seedInfo);
    contentArea->add(seedTextBox);
	
	// Add a standard "ok" buttons with the appropriate responses when clicked.
    Gtk::Button * okButton = add_button( Gtk::Stock::OK, Gtk::RESPONSE_OK);
	show_all_children();
	
    // Wait for a response from the dialog box.
    bool *playerAI = new bool[4];
	int result = run();
    switch (result) {
        case Gtk::RESPONSE_OK:
            for ( int i = 0; i < messages.size(); i++ ) {
				playerAI[i] = buttons[i]->get_active(); 
					break;
			} // for
            break;
    } // switch    
    
    string seed = seedTextBox.get_text();

    cout << "VALUES BITCHES" << endl << playerAI[0] << endl << playerAI[1] << endl << playerAI[2]<< endl << playerAI[3] << endl;
    
    delete []playerAI;

} // MyDialogBox::MyDialogBox

MyDialogBox::~MyDialogBox() {
	for ( int i = 0; i < buttons.size(); i++ ) delete buttons[i];
	buttons.clear();
} // MyDialogBox::~MyDialogBox
