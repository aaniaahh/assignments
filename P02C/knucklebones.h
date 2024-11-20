#ifndef KNUCKLEBONES_H
#define KNUCKLEBONES_H

#include <vector>
#include <string>
using namespace std;

// Forward declarations
class Player;
class Dice;
class Game;
class Knucklebones;

// Dice Class
class Dice {
private:
    int sides;
    int current_value;

public:
    Dice(int sides = 6);  // Constructor with default sides = 6
    void roll();          // Rolls the dice
    int getValue() const; // Returns the current value of the dice
};

// Player Class
class Player {
private:
    string name;
    int score;
    vector<Dice> dice_Set;
    // Player statistics can be expanded as needed (e.g., wins, losses)
    struct PlayerStats {
        int wins;
        int losses;
        // Add other statistics as needed
    } player_stats;

public:
    Player(const string& name, int num_dice = 3); // Constructor with default 3 dice
    void rollDice();          // Rolls all the player's dice
    int getScore() const;     // Returns the player's score
    void updateScore(int points); // Updates the player's score
    void reset();             // Resets the player's score and dice
};

// Game Class
class Game {
protected:
    vector<Player> players;
    int current_round;

public:
    Game(const vector<Player>& players); // Constructor accepting players
    virtual void startGame();      // Starts the game
    virtual void endGame();        // Ends the game
    virtual Player* getWinner();   // Returns the winner of the game
    virtual void resetGame();      // Resets the game
};

// Knucklebones Class (inherits from Game)
class Knucklebones : public Game {
private:
    int board[3][3];  // 3x3 grid for Knucklebones board
    // Define any specific rules or scoring mechanics for Knucklebones

public:
    Knucklebones(const vector<Player>& players); // Constructor with players
    void startRound();        // Starts a new round
    void endRound();          // Ends the round and updates the board/scores
    Player* calculateWinner(); // Determines the winner based on Knucklebones rules
};

#endif // KNUCKLEBONES_H
