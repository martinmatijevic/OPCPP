#include "MainGame.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "WinScreen.h"
#include "Asteriod.h"
#include "Animation.h"
#include <iostream>

#include <time.h>

bool gameOver = false;
void MainGame::Initialize(sf::RenderWindow* window)
{
	SEManager = new SoundEffectManager;
	SEManager->InitializeSoundEffect();

	this->font = new sf::Font();
	this->font->loadFromFile("starcruiser.ttf");
	this->score = new Score(*font, 64U);
	this->lives = new Lives(*font, 64U);
	this->lives->setPosition(window->getSize().x - this->lives->getGlobalBounds().width, 0);

	this->level = new sf::Text("Current Level: " + std::to_string(levelIndex), *font, 32U);
	this->level->setFillColor(sf::Color::White);
	this->level->setPosition((window->getSize().x - this->lives->getGlobalBounds().width) / 2, 32);

	shipExplodeTexture = new Texture;
	rockExplodeTexture = new Texture;
	shipExplodeTexture->loadFromFile("type_B.png");
	rockExplodeTexture->loadFromFile("type_C.png");

	this->spaceship = new Spaceship(SEManager);
	entities.push_back(spaceship);

	rockNum = 0;
	for (int i = 0; i<2; i++)
	{
		Rock *rock = new Rock(BigRock);
		entities.push_back(rock);
		rockNum++;
	}
	for (int i = 0; i<2; i++)
	{
		Rock *rock = new Rock(MediumRock);
		entities.push_back(rock);
		rockNum++;
	}
	for (int i = 0; i<2; i++)
	{
		Rock *rock = new Rock(SmallRock);
		entities.push_back(rock);
		rockNum++;
	}
}
void MainGame::Update(sf::RenderWindow* window)
{
	lives->Update();
	score->Update();
	if (live == 0)
	{
		SEManager->PlaySoundEffect(LoseLifeSound);
		finalScore = score->value;
		_currentState.SetState(new GameOver);
	}
	if (rockNum == 0)
	{
		levelIndex += 1;
		_currentState.SetState(new WinScreen());
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
		_currentState.SetState(new MainMenu);

	if (Keyboard::isKeyPressed(Keyboard::Space) && SEManager->CheckPlayStatus(LaserSound) == true)
	{
		Bullet* bullet = new Bullet();
		SEManager->PlaySoundEffect(LaserSound);
		bullet->Settings(bullet->aniBullet, spaceship->x, spaceship->y, spaceship->angle, 10);
		entities.push_back(bullet);
	}
	for (auto a : entities)
	{
		for (auto b : entities)
		{
			if ((a->name == "BigRock" || a->name == "MediumRock" || a->name == "SmallRock") && b->name == "Bullet")
				if (CheckCollide(a, b))
				{
					b->life = 0;
					if (a->name == "BigRock")	score->AddScore(10);
					if (a->name == "MediumRock")	score->AddScore(20);
					if (a->name == "SmallRock")	score->AddScore(40);

					SEManager->PlaySoundEffect(DestroySound);

					ExplosionEffect *explosionEffect_Rock = new ExplosionEffect(RockExplode, shipExplodeTexture, rockExplodeTexture);
					explosionEffect_Rock->Settings(explosionEffect_Rock->aniExplosion, b->x, b->y, 0, 0);
					entities.push_back(explosionEffect_Rock);

					if (a->name == "BigRock")
						{
							Rock* newRock = new Rock(SmallRock);
							newRock->Settings(newRock->aniRock, a->x, a->y, rand() % 360, 14);
							newRock->dx=a->dx;
							newRock->dy=a->dy;
							entities.push_back(newRock);
							rockNum++;
						}
					if (a->name == "BigRock")
						{
							Rock* newRock = new Rock(SmallRock);
							newRock->Settings(newRock->aniRock, a->x, a->y, rand() % 360, 14);
							newRock->dx=(-1.0f)*a->dx;
							newRock->dy=(-1.0f)*a->dy;
							entities.push_back(newRock);
							rockNum++;
						}
					a->life = 0;
					rockNum -= 1;
				}
			if ((a->name == "BigRock" || a->name == "MediumRock" || a->name == "SmallRock") && b->name == "Spaceship")
				if (CheckCollide(a, b))
				{
					lives->RemoveLife();
					SEManager->PlaySoundEffect(DestroySound);
					ExplosionEffect *explosionEffect_ship = new ExplosionEffect(ShipExplode, shipExplodeTexture, rockExplodeTexture);
					explosionEffect_ship->Settings(explosionEffect_ship->aniExplosion, a->x, a->y, 0, 0);
					entities.push_back(explosionEffect_ship);
					spaceship->Settings(spaceship->ani, 1280 / 2, 1024 / 2, 0, 37);
					spaceship->dx = 0;
					spaceship->dy = 0;
				}
		}
	}
	int bulletCount = 0;
	for (auto e : entities)
	{
		if (e->name == "Explosion")
			if (e->anim.IsEnd())
				e->life = 0;
		if (e->name == "Bullet")
		{
			if (bulletCount < 10)
				bulletCount++;
			else
			{
				e->life = 0;
			}
		}
	}
	for (auto i = entities.begin(); i != entities.end();)
	{
		Entity *e = *i;
		e->Update(window);
		e->anim.Update(window);
		if (e->life == 0)
		{
			i = entities.erase(i);
			delete e;
		}
		else
			i++;
	}
}
void MainGame::Render(sf::RenderWindow* window)
{
	window->draw(*this->lives);
	window->draw(*this->score);
	window->draw(*this->level);
	for (auto i : entities)
		i->Draw(*window);
}
void MainGame::Destroy(sf::RenderWindow* window)
{
	delete this->score;
	delete this->lives;
	delete this->font;
	delete this->level;
	delete this->rockExplodeTexture;
	delete this->shipExplodeTexture;
}

bool MainGame::CheckCollide(Entity *a, Entity *b)
{
	return (b->x - a->x)*(b->x - a->x) +
		(b->y - a->y)*(b->y - a->y)<
		(a->R + b->R)*(a->R + b->R);
}
