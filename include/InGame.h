#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include <Character.h>
#include <iomanip>

class InGame
{
private:
    int option;
    // Character character;
    std::unique_ptr<Character> player;
    std::string fileName;

public:
    InGame();
    ~InGame();

    // Initialize the game (loading or create a new one)
    void init_Game();
    // create a new game
    void createGame();
    // Show the main menu
    void InGame_Menu();
    // Fight with Enemy
    void Fight();

    // Save the game
    void saveGame();
    // Load the game
    void loadGame();

    void calculateDamage(Character enemy, std::unique_ptr<Character> &character, int &damage_to_charactor, int &damage_to_enemy);

    // Exit the game
    void Exit();
    // Show the game status
    bool gameStatus();
};