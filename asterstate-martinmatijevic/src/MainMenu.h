#pragma once
#include "GameState.h"
#include "Asteriod.h"
#include "Animation.h"
class MainMenu : public State
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	sf::Font* font;
	sf::Text* title;
	sf::Text* usingKeyboard;
	sf::Text* quit;

	int selected;

	bool upKey, downKey;
};
