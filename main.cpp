#include "Game.h"


/*
TODO:
    - make tile class
    - replicate this version
        - difficulties don't need switch statement
        - heap tile grid
    - add menus
        - settings
            - click keybind
            - force 0 on click
    - add chording
    - add timer
    - add seeding
    - add custom difficulty (size and mines)
		- could be an absolute pain to size spaces btw maybe save this one for a while
    - add save files
    - add saved stats
        - flag vs flag-less
        - top 10(?) times for each difficulty
            - date/time achieved
            - seed
        - time averages
            - all time / month / week / day
        - total wins, losses, tiles cleared, flags placed, clicks in game
        - win rate
    - get better sprites for everything
		- number colors PLEASE
    - add sfx!
*/


int main()
{
    Game minesweeper;
    minesweeper.run();
    return 0;
}
