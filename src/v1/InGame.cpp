#include "InGame.h"

InGame::InGame()
{
    std::cout << "Welcome! Warrior" << std::endl;
    fileName = "../saves/saving.txt";
    player = std::make_unique<Character>();
}

InGame::~InGame()
{
}

void InGame::init_Game()
{
    std::cout << "ENTER to continue..." << std::endl;
    std::cin.get();
    system("clear");
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Main Menu" << std::endl;
    std::cout << "0: New Game" << std::endl;
    std::cout << "1: Load Game" << std::endl;
    std::cout << "2: Exit" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Give your option: " << std::endl;

    int option_main;
    std::cin >> option_main;

    while (std::cin.fail() || option_main > 2)
    {
        std::cout << "False input" << std::endl;
        std::cout << "Give your option again" << std::endl;
        std::cin.clear();

        std::cin.ignore(5, '\n');

        std::cout << "Option in range [0,2]" << std::endl;
        std::cin >> option;
    }

    switch (option_main)
    {
    case 0:

        createGame();
        saveGame();
        break;
    case 1:
    {
        std::ifstream savingFile;
        savingFile.open(fileName);

        if (savingFile.is_open())
        {
            std::cout << "Saving File Found!" << std::endl;
            std::cout << "Loading" << std::endl;
            loadGame();
            savingFile.close();
        }

        else
        {
            system("clear");
            std::cout << "Error! No Saving File Found! " << std::endl;
            std::cout << "You need to create a new file!" << std::endl;
            createGame();
        }
        break;
    }

    case 2:
        Exit();
        break;
    }
}

void InGame::createGame()
{

    std::string name = "";
    std::cout << "Give your Character's name: " << std::endl;
    std::cin >> name;

    player.reset(new Character(name));

    system("clear");

    std::cout << "Character: " << name << " is created!" << std::endl;
}

void InGame::saveGame()
{

    std::ofstream outFile(fileName);
    //Older IMPLEMENTATION
    // if (outFile.is_open())
    // {
    //     outFile << character.AttributeToString() << "\n";
    // }
    if (outFile.is_open())
    {
        boost::archive::text_oarchive archive(outFile);
        archive << *player;
    }
    outFile.close();
}

void InGame::loadGame()
{

    std::ifstream savingFile(fileName);
    // this->character.clear();

    //Older IMPLEMENTATION
    // std::string name = "";
    // int DAY = 0;
    // int LV = 0;
    // int HP = 0;
    // int maxHP = 0;
    // int AP = 0;
    // int DP = 0;
    // std::string line = "";
    // std::stringstream strstr;
    // if (savingFile.is_open())
    // {
    //     while (getline(savingFile, line))
    //     {
    //         strstr.str(line);
    //         strstr >> name;
    //         strstr >> DAY;
    //         strstr >> LV;
    //         strstr >> HP;
    //         strstr >> maxHP;
    //         strstr >> AP;
    //         strstr >> DP;

    //         //Create character
    //         player = std::make_unique<Character>(name, DAY, LV, HP, maxHP, AP, DP);
    //         character.Character::CharacterLoading(name, DAY, LV, HP, maxHP, AP, DP);

    //         std::cout << "Character: " << name << " is loaded!" << std::endl;
    //         strstr.clear();
    //     }
    // }

    {
        boost::archive::text_iarchive archive(savingFile);
        archive >> *player;
    }
    savingFile.close();
}
void InGame::InGame_Menu()
{

    std::cout << "ENTER to continue..." << std::endl;
    std::cin.ignore(5, '\n');
    std::cin.get();

    std::cout << "-----------------************************----------------------" << std::endl;
    std::cout << "You have following options" << std::endl;
    std::cout << "0: Fight" << std::endl;
    std::cout << "1: showstats" << std::endl;
    std::cout << "2: Save" << std::endl;
    std::cout << "3: Rest" << std::endl;
    std::cout << "4: Exit" << std::endl;
    std::cout << "-----------------************************----------------------" << std::endl;
    std::cout << "Give your option: " << std::endl;
    std::cin >> option;

    while (std::cin.fail() || option > 4)
    {
        std::cout << "False input" << std::endl;
        std::cout << "Give your option again" << std::endl;
        std::cin.clear();

        // Extracts characters from the input sequence and discards them, until either n characters have been extracted, or one compares equal to delim.
        std::cin.ignore(5, '\n');

        std::cout << "Option in range [0,3]" << std::endl;
        std::cin >> option;
    }

    switch (option)
    {
    case 0:
        Fight();
        break;
    case 1:
        player->showStats();
        break;
    case 2:
        saveGame();
        break;
    case 3:
        std::cout << "take a rest " << std::endl;
        player->reset();
        player->passDay();
        break;
    case 4:
        Exit();
        break;
    }
}
void InGame::calculateDamage(Character enemy, std::unique_ptr<Character> &character, int &damage_to_charactor, int &damage_to_enemy)
{
    int enemyap = enemy.showAP();
    int enemydp = enemy.showDP();
    int characterap = character->showAP();
    int characterdp = character->showDP();
    damage_to_charactor = std::max(0, enemyap - characterdp);
    damage_to_enemy = std::max(0, characterap - enemydp);
}

void InGame::Fight()
{

    Character Gobelin("goblein", 0, 0, 30, 30, 10, 3);

    std::cout << "A Gobelin appears!!" << std::endl;
    int damage_to_charactor(0), damage_to_enemy(0);

    calculateDamage(Gobelin, player, damage_to_charactor, damage_to_enemy);

    while (Gobelin.isAlive() && player->isAlive())
    {
        std::cout << "You lost " << damage_to_charactor << " HP " << std::endl;
        std::cout << "Enemy lost " << damage_to_enemy << " HP " << std::endl;
        player->takeDamage(damage_to_charactor);
        Gobelin.takeDamage(damage_to_enemy);
    }
    if (!Gobelin.isAlive())
    {
        std::cout << " You won!!" << std::endl;
    }
    player->passDay();
}
void InGame::Exit()
{
    std::cout << "Exiting" << std::endl;
    exit(1);
}
bool InGame::gameStatus()
{
    return player->isAlive();
}