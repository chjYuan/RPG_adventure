#include <iostream>
#include <fstream>
#include <math.h>
#include "InGame.h"

int main()
{
    system("clear");
    InGame game;
    game.init_Game();
    while (1)
    {
        if (game.gameStatus())
            game.InGame_Menu();
        else
        {
            // system("clear");
            std::cout << "-----------------************************----------------------" << std::endl;
            std::cout << "Your charater is died, T_T" << std::endl;
            std::cout << "Game restart" << std::endl;
            std::cout << "-----------------************************----------------------" << std::endl;
            std::cin.ignore(5, '\n');
            game.init_Game();
        }
    }

    return 0;
}
