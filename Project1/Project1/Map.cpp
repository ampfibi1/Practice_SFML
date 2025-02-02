#include "Map.h"

Map::Map() :
	tileWeight(16) , tileHeight(16) ,
	totalTileX(0) , totalTileY(0) 
{
}

Map::~Map()
{
	delete[] tiles;
}

void Map::Initialize()
{
}

void Map::Load()
{
	if (map_texture.loadFromFile("Asset/Dungeon_tileset.png")) {
		totalTileX = map_texture.getSize().x / tileWeight;
		totalTileY = map_texture.getSize().y / tileHeight;

		totalTiles = totalTileX * totalTileY; 
		tiles = new Tile[totalTiles];

		for (int y = 0; y < totalTileY; y++) {
			for (int x = 0; x < totalTileX; x++) {
				int i = x + y * totalTileX; 
				tiles[i].id = i;
				tiles[i].texture = &map_texture;
				tiles[i].position = sf::Vector2i(x * tileWeight, y * tileHeight); 
					
				//sf::IntRect(x * tileWeight, y * tileHeight, tileWeight, tileHeight);
				/*tiles[i].sprite.setTexture(map_texture);
				tiles[i].sprite.setScale(sf::Vector2f(3, 3));
				tiles[i].sprite.setTextureRect(sf::IntRect(x * tileWeight, y * tileHeight, tileWeight, tileHeight));
				tiles[i].sprite.setPosition(x * tileWeight * 3, 50*y*tileHeight*3);*/
			}
		}

		for (size_t y = 0; y < 2; ++y) {
			for (size_t x = 0; x < 3; ++x) {
				int i = x + y * 3; 
				int index = mapNumber[i]; 

				mapSprite[i].setTexture(*tiles[index].texture); 
				mapSprite[i].setTextureRect(sf::IntRect(tiles[index].position.x,
					tiles[index].position.y , 
					tileWeight,tileHeight
					));
				mapSprite[i].setPosition(sf::Vector2f(x*16*3,100+y*16*3));
				mapSprite[i].setScale(sf::Vector2f(3, 3));
			}
		}


		cout << "Map laod \n"; 
		
		cout << "Weight : " << totalTileX << "\nHeight : " << totalTileY << endl; 
		
	}
	else
		std::cout << "map not load" << endl;
}

void Map::Update()
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for(int i=0; i< 6; ++i)
		window.draw(mapSprite[i]);
}
