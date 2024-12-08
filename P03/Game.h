#pragma once

class Game 
{
public:
    Game(); // Constructor initializes game resources
    void start(); // Main game loop

private:
    sf::RenderWindow window;
    Dice* dice;             // Shared dice object
    Player* current_player; // Pointer to the current player
    Player players[2];      // Two players
    Grid* grids[2];         // Separate grids for each player

    void initialize();      // Setup game resources
    void take_turn();       // Handle a player's turn
    void display_game_state(); // Render game state on the window
    void switch_turn();     // Swap active player
    bool check_win();       // Check if the game has ended
};