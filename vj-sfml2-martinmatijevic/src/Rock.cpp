#include "Rock.h"
#include "Animation.h"
Rock::Rock(int type)
{
	int rockSize;
	this->rockType = type;
	if (rockType == BigRock)
	{
		name = "BigRock";
		LoadTexture("meteorBrown_big4.png");
		Animation sRock(*texture, 0, 0, 98, 96, 1, 0);
		rockSize = 48;
		aniRock = sRock;
	}
	else if (rockType == MediumRock)
	{
		name = "MediumRock";
		LoadTexture("meteorBrown_med1.png");
		Animation sRock(*texture, 0, 0, 43, 43, 1, 0);
		rockSize = 26;
		aniRock = sRock;
	}
	else if(rockType == SmallRock)
	{
		name = "SmallRock";
		LoadTexture("meteorBrown_small1.png");
		Animation sRock(*texture, 0, 0, 28, 28, 1, 0);
		rockSize = 14;
		aniRock = sRock;
	}
	entityType = "Rock";
	Settings(aniRock, rand() % 1280, rand() % 1024, rand() % 360, rockSize);
	dx = (float)(rand() % 20)/80;
	dy = (float)(rand() % 20)/80;

}

void Rock::Update(sf::RenderWindow* window)
{
	x += dx;
	y += dy;
	angle += .5f;
	if (x>1280)		x = 0;
	else if (x<0)		x = 1280;
	if (y>1024)		y = 0;
	else if (y<0)		y = 1024;
}
