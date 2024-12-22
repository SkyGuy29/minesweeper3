#pragma once
#include <iostream>
#include <ctime>
#include <string.h>
#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "Tile.h"


class Game
{
public:
	Game();
	void run();
private:
    bool showTile[16][30], hideFlag[16][30], leftMouseHeld = false,
        rightMouseHeld = false, firstClick = true, showGame = false,
        gameOver = false, startSetup = false;
    int minefield[16][30], difficulty = 3, seed = time(nullptr);
    float fade = 0;
    const float SPACING_CONST = 505 / 16.0;
    sf::RenderWindow window;
    sf::RectangleShape button, menuButton[3];
    sf::Font heavitas;
    sf::Text mineNumber, endText, restartText, menuText, menuButtonText[3];
    sf::Texture flagImage, mineImage;
    sf::Sprite flag, mine;

    void textStringUpdate(sf::Text&, std::string);
    void textStringUpdate(sf::Text&, std::string, int);
    void resetGrid(int[][30]);
    void resetGrid(bool[][30]);
    void randGrid(int[][30], int);
    void labelGrid(int[][30], int);
    void revealTiles(int[][30], bool[][30], int, int);
    bool buttonPressed(sf::RectangleShape, sf::RenderWindow&);
    bool notOutOfBounds(int[][30], int, int, int, int);
    bool gameWin(int[][30], bool[][30], int);

};