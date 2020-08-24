#include "Entity.h"
#include <SFML/Graphics.hpp>
Entity::Entity()
{
	life = 1;
	this->texture = new Texture();
}

void Entity::LoadTexture(std::string filename)
{
	texture->loadFromFile(filename);
	setTexture(*this->texture);
}

void Entity::Settings(Animation &a, int X, int Y, float Angle = 0, int radius = 1)
{
	anim = a;
	x = X;
	y = Y;
	angle = Angle;
	R = radius;
}

void Entity::Draw(RenderWindow &window)
{
	anim.sprite.setPosition(x, y);
	anim.sprite.setRotation(angle + 90);
	window.draw(anim.sprite);

	CircleShape circle(R);
	circle.setFillColor(Color(255, 0, 0, 170));
	circle.setPosition(x, y);
	circle.setOrigin(R, R);
	//window.draw(circle);
}

Entity::~Entity()
{
	delete texture;
}
