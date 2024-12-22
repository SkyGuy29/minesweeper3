#include "Tile.h"


Tile::Tile()
{
	//heavitas.loadFromFile("heavitas.ttf");
	//text.setFont(heavitas);
}


void Tile::setNum(const char newNum)
{
	mineNum = newNum;
	switch (mineNum)
	{
	case 0:
		text.setFillColor(sf::Color(1, 0, 0, 255));
		break;
	case 1:
		text.setFillColor(sf::Color(2, 0, 0, 255));
		break;
	case 2: 
		text.setFillColor(sf::Color(3, 0, 0, 255));
		break;
	case 3: 
		text.setFillColor(sf::Color(4, 0, 0, 255));
		break;
	case 4: 
		text.setFillColor(sf::Color(5, 0, 0, 255));
		break;
	case 5: 
		text.setFillColor(sf::Color(6, 0, 0, 255));
		break;
	case 6: 
		text.setFillColor(sf::Color(7, 0, 0, 255));
		break;
	case 7: 
		text.setFillColor(sf::Color(8, 0, 0, 255));
		break;
	case 8: 
		text.setFillColor(sf::Color(9, 0, 0, 255));
		break;
	case MINE:
		text.setFillColor(sf::Color(0, 0, 0, 255));
		break;
	default:
		break;
	}
}


void Tile::drawTo(sf::RenderWindow& window) const
{
	if (mineNum != 0 && mineNum != MINE)
	{
		window.draw(text);
	}
	if (drawTile)
	{
		window.draw(rect);
		if (flagged)
			window.draw(flag);
	}
}