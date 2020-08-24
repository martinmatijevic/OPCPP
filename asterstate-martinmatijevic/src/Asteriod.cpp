#include "GameState.h"
#include "MainMenu.h"
#include "Asteriod.h"
CurrentState _currentState;
bool quitGame = false;
int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 1024), "Asteriod");
	_currentState.SetWindow(&window);
	_currentState.SetState(new MainMenu());
	sf::Texture texture;
	if (!texture.loadFromFile("bg5.jpg"))
	{
		return -1;
	}
	sf::Sprite background(texture);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.draw(background);
		_currentState.Update();
		_currentState.Render();
		window.display();
		if (quitGame)
		{
			window.close();
		}
	}
	return 0;
}
