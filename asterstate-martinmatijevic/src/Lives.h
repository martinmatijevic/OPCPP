#pragma once
#include "Animation.h"

#include <SFML/Graphics.hpp>

class Lives : public sf::Text
{
public:
	Lives(sf::Font &font, unsigned int size);
	void RemoveLife();
	void Update();
	int Value();
private:
	int value;
};
