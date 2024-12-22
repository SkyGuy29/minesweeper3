#pragma once
#include <ctime>
#include <string.h>
#include <SFML/Graphics.hpp>
#include "Tile.h"

enum Difficulty
{
    BEGINNER,
    INTERMEDIATE,
    EXPERT
};


class Game
{
public:
	Game();
    ~Game()
	{
        for (int i = 0; i < stdGridSize[Difficulty::BEGINNER].x; ++i) 
        {
            delete[] grid[i]; // Delete each row
        }
        delete[] grid; // Delete the outer array
	}
	void run();
private:
    int difficulty = 3, seed = time(nullptr);
    const float SPACING_CONST = 505 / 16.0;
    sf::RenderWindow window;
    sf::Font heavitas;

    Tile** grid;
    //default grid size (in terms of tiles) for each standard difficulty
    const sf::Vector2u stdGridSize[3] { sf::Vector2u(9, 9), sf::Vector2u(16, 316), sf::Vector2u(16, 30) };
    //default tile size (height and length for each tile) for each standard difficulty
    const sf::Vector2f stdTileSize[3] { sf::Vector2f(60, 60),
    	sf::Vector2f(SPACING_CONST, SPACING_CONST), sf::Vector2f(SPACING_CONST, SPACING_CONST) }; //yes these are duplicates no I don't care

};