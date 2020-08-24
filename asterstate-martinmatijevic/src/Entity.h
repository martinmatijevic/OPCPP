#pragma once
#include "Animation.h"
class Entity : public Sprite
{
public:
	float x, y, dx, dy, R, angle;
	int life;
	std::string name;
	std::string entityType;
	Animation anim;
	Texture* texture;
	float DEGTORAD = 0.017453f;
	Entity();
	void LoadTexture(std::string filename);
	void Settings(Animation &a, int X, int Y, float Angle, int radius);
	virtual void Update(sf::RenderWindow* window) {};
	void Draw(RenderWindow &window);
	virtual ~Entity();
};
