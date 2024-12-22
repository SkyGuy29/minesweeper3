#pragma once
#include "globals.hpp"


class Tile
{
public:
	Tile();
	~Tile() = default;

	void setSize(const sf::Vector2f size) {	rect.setSize(size);	/* flag.setScale(some wack multiplier idk); */}

	bool isFlagged() const { return flagged; }
	//for initialization? how will we set it relative to the others
	char getNum() const { return mineNum; }
	void setNum(char newNum);

	//used to determine if the mouse is over it, for revealing.
	sf::FloatRect getBounds() const { return rect.getGlobalBounds(); }

	//reveals the tile. returns the value of the tile to indicate what should happen next.
	char reveal() { drawTile = false; return mineNum; }
	void drawTo(sf::RenderWindow& window) const;
private:
	bool drawTile = true, flagged = false;
	char mineNum = 0; //the physical number you see, 9 indicates that this is a mine. mine = nine.
	//I don't think I'm doing versions where the number goes above 8, or below 0 for that matter.
	//this is likely just going to use only regular minesweeper rules. 

	static sf::Font heavitas;
	sf::Text text;
	sf::RectangleShape rect;
	static sf::Texture flagImage, mineImage;
	sf::Sprite flag, mineSprite;
};