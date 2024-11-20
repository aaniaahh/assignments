
1. Dice Class
Data:
sides: Number of sides on the dice (default is 6 for standard dice).
current_value: The result of the last roll.

Actions:
roll(): Randomly generate a value based on the number of sides.
getValue(): Return the current value of the dice.
Relationships:

The Player HAS-A set of Dice. Players roll the dice during their turn (composition).
2. Player Class
Data:
name: The player’s name.
score: The player's current score.
diceSet: A collection of Dice objects (e.g., 3 Dice for Knucklebones).
playerStats: Tracks statistics such as total wins, losses, and any other performance indicators.

Actions:
rollDice(): Rolls the player's dice.
getScore(): Retrieve the player's current score.
updateScore(points): Updates the player’s score based on the dice rolls.
reset(): Resets the player's score and dice for a new game.

Relationships:
A Player HAS-A set of Dice (composition).
A Player IS-A participant in the game (part of the Game class).

3. Game Class
Data:
players: A list of Player objects (2 players in Knucklebones).
rules: General rules for the game.
currentRound: Tracks the current round number.

Actions:
startGame(): Initializes a new game, sets up players and the game board.
endGame(): Ends the game and determines the winner.
getWinner(): Compares players' scores and returns the winner.
resetGame(): Resets the game state for a new session.

Relationships:
The Game class controls Players and their actions (composition).
Knucklebones IS-A Game, as it has specific rules (inheritance).

4. Knucklebones Class (inherits from Game)
Data:
board: A 3x3 grid that keeps track of where players place their dice.
knucklebones_specific_rules: Any rules specific to Knucklebones, such as scoring based on columns or other special interactions.

Actions:
startRound(): Starts a new round of Knucklebones.
endRound(): Ends the current round and updates the board and scores.
calculate_Winner(): Determines the winner based on the specific rules of Knucklebones.

Relationships:
Knucklebones IS-A Game (inheritance). It inherits general game functionality but adds its own specific rules and board layout.

5. Inheritance vs. Composition:
- Inheritance:
The Knucklebones class inherits from the Game class since Knucklebones IS-A type of game with its own set of rules.
- Composition:
A Player HAS-A set of Dice (the player uses dice for rolling).
The Game HAS-A set of Players (players participate in the game).

6. Keyword Categorization:
- Necessary:
score: Tracks the points each player accumulates.
first name: To identify the player.
winner: To determine the victor at the end of the game.
player stats: Tracks performance data (e.g., wins/losses).
userid: Identifies players in multiplayer or online contexts.
diceSet: Required for rolling dice.

- Possible:
leaderboard: Shows rankings of players across games.
high score: Tracks the highest score in a single game session.
streak: Tracks the player's winning or losing streak.
coins: Could be used as a reward system or currency in the game.

- Wishful:
chat: Allows players to communicate during gameplay.
messaging: Sends messages between players or from the system.
teams: Players can form teams.
team stats: Track statistics for teams instead of individual players.
levels: Introduce different difficulty levels for more complexity.