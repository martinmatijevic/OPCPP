#pragma once
#include "Entity.h"
#include "Animation.h"
class Bullet : public Entity
{
public:
	Bullet();
	void Update(sf::RenderWindow* window);
	Animation aniBullet;
};
