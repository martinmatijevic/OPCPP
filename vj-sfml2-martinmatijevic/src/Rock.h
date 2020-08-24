#pragma once
#include "Entity.h"
#include "ExplosionEffect.h"
#include "Animation.h"
#define BigRock 0
#define MediumRock 1
#define SmallRock 2

class Rock : public Entity
{
public:
	Rock(int type);
	void Update(sf::RenderWindow* window);
	Animation aniRock;
private:
	int rockType;
};
