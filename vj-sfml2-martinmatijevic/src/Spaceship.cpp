#include "Spaceship.h"
#include "Animation.h"
#include <cmath>

Spaceship::Spaceship(SoundEffectManager* SEManager)
{
	LoadTexture("playerShip3_blue.png");
	setScale(.2f, .2f);
	Animation sPlayer(*texture, 0, 0, 98, 75, 1, 0);
	ani = sPlayer;
	Settings(sPlayer, 1280/2, 1024/2, 0, 37);
	name = "Spaceship";
	this->SEManager = SEManager;
}

void Spaceship::Update(sf::RenderWindow* window)
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
		angle += 0.1;
	if (Keyboard::isKeyPressed(Keyboard::Left))
		angle -= 0.1;
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		dx += cos(angle*DEGTORAD)*0.0001;
		dy += sin(angle*DEGTORAD)*0.0001;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		dx *= 0.7;
		dy *= 0.7;
	}
	x += dx;
	y += dy;
	if (x>1280)		x = 0;
	else if (x<0)		x = 1280;
	if (y>1024)		y = 0;
	else if (y<0)		y = 1024;
}
