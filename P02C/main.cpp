/*****************************************************************************
*
*  Names:           Aniah Myles and Prof. Terry Griffin
*  Email:           aamyles1222@my.msutexas.edu
*  Label:           08-P02
*  Title:           Knucklebones
*  Course:          CMPS 2143
*  Semester:        Fall 2024
*
*  Description:
*       This program will perform basic game logic for Knucklebones,
*       where players roll dice and score points based on the game rules.
        (Not finished!)
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "knucklebones.h"
using namespace std;  

int main() {
    // Welcome message
    cout << "Welcome to Knucklebones!" << endl;

    // Create players
    Player player1();
    Player player2();
    vector<Player> players = {player1, player2};

    // Initialize Knucklebones game
    Knucklebones game(players);

    // Start the game
    game.startGame();

    // Simulate a few rounds
    for (int round = 1; round <= 3; ++round) {  // Play 3 rounds
        cout << "\n--- Round " << round << " ---" << endl;
        game.startRound();

        // Each player rolls dice
        for (Player& player : players) {
            cout << player.getName() << "'s turn:" << endl;
            player.rollDice();
            cout << "Score: " << player.getScore() << endl;
        }

        game.endRound();
    }

    // End the game and determine the winner
    game.endGame();
    Player* winner = game.getWinner();

    if (winner) {
        cout << "\nThe winner is " << winner->getName() << " with a score of " 
             << winner->getScore() << "!" << endl;
    } else {
        cout << "\nIt's a tie!" << endl;
    }

    // Thank you message
    cout << "Thank you for playing Knucklebones!" << endl;

    return 0;
}
