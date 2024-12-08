#pragma once

class Player 
{
public:
    Player();
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