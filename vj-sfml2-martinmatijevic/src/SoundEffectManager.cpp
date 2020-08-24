#include "SoundEffectManager.h"

void SoundEffectManager::InitializeSoundEffect()
{
	this->bufferLaser = new SoundBuffer;
	this->bufferLaser->loadFromFile("Laser.wav");
	this->soundLaser = new Sound(*this->bufferLaser);

	this->bufferDestroyBrick = new SoundBuffer;
	this->bufferDestroyBrick->loadFromFile("Explosion.wav");
	this->soundDestroyBrick = new Sound(*this->bufferDestroyBrick);

	this->bufferLoseLife = new SoundBuffer;
	this->bufferLoseLife->loadFromFile("LoseLife.wav");
	this->soundLoseLife = new Sound(*this->bufferLoseLife);
}

void SoundEffectManager::PlaySoundEffect(int index)
{
	switch (index)
	{
	case LaserSound:
		this->soundLaser->play();
		index = -1;
		break;
	case DestroySound:
		this->soundDestroyBrick->play();
		index = -1;
		break;
	case LoseLifeSound:
		this->soundLoseLife->play();
		index = -1;
		break;
	}
}

bool SoundEffectManager::CheckPlayStatus(int index)
{
	bool isPlaying;
	switch (index)
	{
	case LaserSound:
		if (this->soundLaser->getStatus() != SoundSource::Playing)
			return true;
		break;
	}
	return false;
}

SoundEffectManager::~SoundEffectManager()
{
	delete this->soundLaser;
	delete this->bufferLaser;
	delete this->bufferDestroyBrick;
	delete this->soundDestroyBrick;
	delete this->bufferLoseLife;
	delete this->soundLoseLife;
}
