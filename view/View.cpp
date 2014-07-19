#include "View.h"
#include "MyDialogBox.h"
#include <Card.h>
#include <Model.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/main.h>
#include <vector>
#include <iostream>

using namespace std;

View::View(Model *m) : model(m), commandButtons(true, 10), scores( true, 10 ), vbox( true, 10) 
{
    for(int i = 0; i <= 7; i++)
    {
        Gtk::HBox *h = new Gtk::HBox(true, 10);
        hbox.push_back(h);
    }
			
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
    rageQuit.signal_clicked().connect( sigc::mem_fun( *this, &View::rageQuitAction ) );

    quitGame.set_label("End Current Game");
    quitGame.signal_clicked().connect( sigc::mem_fun( *this, &View::endGameAction ) );

    quit.set_label("Quit");
    quit.signal_clicked().connect( sigc::mem_fun( *this, &View::quitGameAction ) );

    commandButtons.add(newGame);
    commandButtons.add(rageQuit);
    commandButtons.add(quitGame);
    commandButtons.add(quit);

    frame.add(commandButtons);

    hbox.at(0)->add(frame);
	
    
    currentTurn.set_label("There is no Game in Progress");
    currentAction.set_label("Press New Game to start a new Game");
    hbox.at(5)->add(currentTurn);
    hbox.at(5)->add(currentAction); 
	// Initialize 4 empty cards and place them in the box.

    scoreboard.set_label("Score Board");
	scoreboard.set_label_align( Gtk::ALIGN_CENTER, Gtk::ALIGN_TOP );
	scoreboard.set_shadow_type( Gtk::SHADOW_ETCHED_OUT );
    scoreboard.add(scores);
    
    player1.set_label("Player 1 \n Score:  \n Discards:");
    player2.set_label("Player 2 \n Score:  \n Discards:");  
    player3.set_label("Player 3 \n Score:  \n Discards:");
    player4.set_label("Player 4 \n Score:  \n Discards:");  
    
    scores.add(player1);
    scores.add(player2);
    scores.add(player3);
    scores.add(player4);

    hbox.at(7)->add(scoreboard);

    // The board starts with no cards on it.
    const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();

    for (int i = 1; i <=4; i++) 
    {
	    for (int j = 0; j < 13; j++ ) 
        {
		    cardsIMG[i-1][j] = new Gtk::Image( nullCardPixbuf );
		    hbox.at(i)->add( *cardsIMG[i-1][j] );
	    } 
    }

    // We start with a theoretical hand of all 7s because it indicates that the player should start a new game.

	for(int i = 0; i < 13; i++)
    {
	    hand[i] = new Gtk::Image( nullCardPixbuf );	
	    button[i].set_image( *hand[i] );
        button[i].set_sensitive(false);
    }
			
	// Add the button to the box.
    for(int i = 0; i < 13; i++)
	    hbox.at(6)->add( button[i] );

    //Connecting signals
    for(int i = 0; i < 13; i++)
    {
       button[i].signal_clicked().connect( sigc::bind<int>( sigc::mem_fun(*this, &View::cardButtonClicked), i) );
	}

	show_all();

	model->subscribe(this);

}

void View::update() 
{
   //Update Hand
   if(model->currentTable() == NULL)
   { 
       // The game is over
       currentTurn.set_label("There is no Game in Progress");
       currentAction.set_label("Press New Game to start a new Game");

       for(int i = 0; i < 13; i++)
       {
           Glib::RefPtr<Gdk::Pixbuf> cardPixbuf = deck.getNullCardImage();

           //Deck is responsible for deleting pointers
           cardReferences[i] = NULL;
           button[i].set_sensitive(false);
           hand[i]->set( cardPixbuf );
           button[i].set_image(*hand[i]);
           
       }

       for(int i = 0; i < 4; i++)
       {
           for(int j = 0; j < 13; j++)
           {
               Glib::RefPtr<Gdk::Pixbuf> cardPixbuf = deck.getNullCardImage();
               cardsIMG[i][j]->set(cardPixbuf);
           }
       }
   }
   else
   {
       vector<Card *> newHand = model->hand();
  
   for(int i = 0; i < 13; i++)
   {
       if( i < newHand.size())
            cardReferences[i] = newHand.at(i);
       else
           cardReferences[i] = NULL;
       
        Glib::RefPtr<Gdk::Pixbuf> cardPixbuf = deck.getNullCardImage();
        button[i].set_sensitive(false);
        if(cardReferences[i] != NULL)
        {
            cardPixbuf = deck.getCardImage( *cardReferences[i] );
            button[i].set_sensitive(true);
        }
        hand[i]->set( cardPixbuf );
        button[i].set_image ( *hand[i] );
   }

    //Update Table
    vector<vector<Card *> > newCards = model->currentTable()->playedCards(); 
    for(int i = 0;i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            if(newCards.at(i).at(j) != NULL)
            {
   	            const Glib::RefPtr<Gdk::Pixbuf> cardPixbuf = deck.getCardImage( *newCards.at(i).at(j) );
                cardsIMG[i][j]->set(cardPixbuf);
            }
            else
            {
                const Glib::RefPtr<Gdk::Pixbuf> cardPixbuf = deck.getNullCardImage();
                cardsIMG[i][j]->set(cardPixbuf);
            }
        }
    }
    //Extra, get legal moves grey out buttons

    currentTurn.set_label(string("It is Player ") + model->currentPlayer() + string("'s Turn to Play"));
    currentAction.set_label(string("You must ") + model->currentAction() + string(" a card."));


    }


    // Display Dialog boxes.
}

void View::cardButtonClicked(int i)
{
    model->select(*cardReferences[i]);
}

void View::quitGameAction() 
{
    hide_all();
}

void View::endGameAction()
{
    model->endGame();
}

void View::rageQuitAction()
{
    model->ragequit();
}

View::~View() 
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 13; j++)
            delete cardsIMG[i][j];

    for(vector<Gtk::HBox*>::iterator it = hbox.begin(); it != hbox.end(); it++)
    {
        delete *it;
    }
}

void View::newGameAction()
{
    bool *playerAI = NULL;
    int seed;
    MyDialogBox dialog( *this, "Set up Parameters:", playerAI, seed  );
    
    model->newGame(seed, playerAI);
    delete []playerAI;
}
