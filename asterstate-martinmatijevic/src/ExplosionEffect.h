#pragma once
#include "Entity.h"
#include "Animation.h"

#define ShipExplode 0
#define RockExplode 1

class ExplosionEffect : public Entity
{
public:
	ExplosionEffect(int type, Texture* t1, Texture* t2);
	void Update(sf::RenderWindow* window) {};
	Animation aniExplosion;
};
