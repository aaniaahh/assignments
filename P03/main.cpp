#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Game 
{
public:
    Game :: Game(); // Constructor initializes game resources
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

class Player 
{
public:
    Player(const std::string& name, int player_id);

    // Player actions
    void add_to_score(int points);
    std::string get_name() const;
    int get_score() const;
    int get_player_id() const;

private:
    std::string name;
    int score;
    int player_id; // ID to differentiate between players
};

Player::Player(const std::string& name, int player_id) : name(name), score(0), player_id(player_id) {}

void Player::add_to_score(int points) 
{
    score += points;
}

std::string Player::get_name() const 
{
    return name;
}

int Player::get_score() const 
{
    return score;
}

int Player::get_player_id() const 
{
    return player_id;
}

class Dice 
{
public:
    Dice() { std::srand(std::time(nullptr)); }
    int roll() { return (std::rand() % 6) + 1; } // Roll a number between 1 and 6
};

class Grid 
{
public:
    Grid();
    bool place_dice(int column, int value, int player_id);
    int calculate_score() const;
    void render(sf::RenderWindow& window, int x_offset, int y_offset);

private:
    int cells[3][3]; // 3x3 grid, 0 = empty, positive integers represent dice values
};

Grid::Grid() 
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cells[i][j] = 0; // Initialize grid with zeros
}

bool Grid::place_dice(int column, int value, int player_id) 
{
    for (int i = 2; i >= 0; --i) { // Place dice from bottom to top
        if (cells[i][column] == 0) {
            cells[i][column] = value;
            return true;
        }
    }
    return false; // Column is full
}

int Grid::calculate_score() const 
{
    int score = 0;
    for (int i = 0; i < 3; ++i) {
        int multiplier = 1;
        for (int j = 0; j < 3; ++j) {
            if (cells[j][i] != 0) {
                score += cells[j][i] * multiplier;
                multiplier *= 2; // Apply multiplication bonus for matching dice
            }
        }
    }
    return score;
}

void Grid::render(sf::RenderWindow& window, int x_offset, int y_offset)
{
    sf::RectangleShape cell(sf::Vector2f(100, 100));
    cell.setOutlineThickness(2);
    cell.setOutlineColor(sf::Color::White);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cell.setPosition(x_offset + j * 100, y_offset + i * 100);
            if (cells[i][j] != 0) {
                cell.setFillColor(sf::Color::Green); // Filled cell
            } else {
                cell.setFillColor(sf::Color::Black); // Empty cell
            }
            window.draw(cell);
        }
    }
}

int main() 
{
    Game game;
    game.start();
    return 0;
    
}
