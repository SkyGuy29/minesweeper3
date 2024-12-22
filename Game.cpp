#include "Game.h"


Game::Game()
{
    window.create(sf::VideoMode(1280, 720), "Minesweeper");
    srand(seed);

    window.setFramerateLimit(FRAMERATE);

    if (!heavitas.loadFromFile("Heavitas.ttf")) {}

    unsigned rows = stdGridSize[BEGINNER].x;
    unsigned cols = stdGridSize[BEGINNER].y;

    //create a 2D heap array
    grid = new Tile * [rows]; //outer array is Tile**
    for (int i = 0; i < rows; ++i)
    {
        grid[i] = new Tile[cols]; //each row is a Tile*
        for (int j = 0; j < cols; ++j)
        {
            grid[i][j] = Tile(heavitas); //initialize each Tile
        }
    }

    for (int i = 0; i < rows * cols; i++)
    {
        grid[i % rows][i % cols].setSize(stdTileSize[BEGINNER]);
    }
}


void Game::run()
{
    //game loop begins
    while (window.isOpen())
    {
        //closing the window
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();       
        }

        if(!isButtonPressed(sf::Mouse::Left))
            leftMouseHeld = false;

        if (!isButtonPressed(sf::Mouse::Right))
            rightMouseHeld = false;

		//position tiles AAAAAAAAAAAAAAAAAAAAAAAAAAA

		window.clear();
		for (int i = 0; i < stdGridSize[BEGINNER].x * stdGridSize[BEGINNER].y; i++)
		{
            grid[i % stdGridSize[BEGINNER].x][i % stdGridSize[BEGINNER].y].drawTo(window);
		}
		window.display();
    }
}
