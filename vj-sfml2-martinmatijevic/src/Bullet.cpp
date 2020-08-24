#include "Bullet.h"
#include "Animation.h"
#include <cmath>
Bullet::Bullet()
{
	name = "Bullet";
	LoadTexture("fire_blue.png");
	Animation sBullet(*texture, 0, 0, 32, 64, 16, 0.8);
	aniBullet = sBullet;
}

void Bullet::Update(sf::RenderWindow* window)
{
	dx = cos(angle*DEGTORAD) * 2;
	dy = sin(angle*DEGTORAD) * 2;
	x += dx;
	y += dy;
	if (x>1280 || x<0 || y>1024 || y<0)	life = 0;
}
