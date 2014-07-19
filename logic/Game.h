#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Deck.h"
#include "Table.h"
#include "Card.h"

#include <vector>
#include <string>
#include <sstream>

class Game
{
    public:

    // Constructor, builds a new game with 4 players asking if they are human or computer
    Game(bool *);

    // Cleans up deck and players on the heap
    ~Game();

    // Plays the game
    void play(std::stringstream &);

    void score(std::stringstream &); 

    void playTurn(Command op, std::stringstream &events);

    void computeLegal();
    void computeLegal(int);

    const std::vector<Card> legalMoves() const;

    std::string getNextAction();

    bool humanTurnNext() const;

    const Player * const currentPlayer() const;

    const std::vector<Player *> &players() const;

    bool roundOver();
    bool gameOver();

    int turn() const;

    Table *table();


    private:

    //Helper function for a round of the game

    std::vector<Player *> players_;
    std::vector<Card> legalPlays;
    Deck *deck_;
    Table *currentTable;
    bool roundOver_;
    bool gameOver_;
    int playerTurn;
    int totalTurn;
    static const int kNumPlayers = 4;
};

#endif
