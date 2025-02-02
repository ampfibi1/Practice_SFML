#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Tile.h"
using namespace std; 

class Map
{
private:
	sf::Texture map_texture;

	Tile* tiles; 
	//sf::Sprite sprites[10];

	int tileWeight; 
	int tileHeight; 
	
	int totalTiles; 
	
	int totalTileX; 
	int totalTileY; 
	
	int mapNumber[6] = {
		0 , 2 , 3 ,
		4, 0, 7
	};
	sf::Sprite mapSprite[6];

public:
	Map();
	~Map();

	void Initialize();
	void Load();
	void Update();
	void Draw(sf::RenderWindow& window);
	
};

