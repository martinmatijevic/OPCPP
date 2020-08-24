#pragma once
#include "Entity.h"
#include "SoundEffectManager.h"
#include "Animation.h"
class Spaceship : public Entity
{
public:
	Animation ani;
	Spaceship(SoundEffectManager* SEManager);
	void Update(sf::RenderWindow* window);
private:
	SoundEffectManager* SEManager;
};
