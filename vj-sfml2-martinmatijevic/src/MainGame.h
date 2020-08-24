#pragma once
#include "GameState.h"
#include "Animation.h"
#include "Lives.h"
#include "Score.h"
#include "SoundEffectManager.h"
#include "Spaceship.h"
#include "Bullet.h"
#include "Rock.h"
#include "ExplosionEffect.h"
#include <list>
using namespace sf;
extern bool gameOver;
class MainGame : public State
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	SoundEffectManager *SEManager;
	Lives* lives;
	Score* score;
	Font* font;
	Text* level;
	std::list<Entity*> entities;
	Spaceship* spaceship;
	bool CheckCollide(Entity *a, Entity *b);
	Texture* shipExplodeTexture;
	Texture* rockExplodeTexture;
	int rockNum;
};

extern int finalScore;
