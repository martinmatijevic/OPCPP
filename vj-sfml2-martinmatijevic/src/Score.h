#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Score : public sf::Text
{
public:
	Score(sf::Font &font, unsigned int size);
	void AddScore(int points);
	void Update();
	int value;
};
