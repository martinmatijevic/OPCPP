#pragma once
#include <SFML/Audio.hpp>
#include "Animation.h"

#define LaserSound 0
#define DestroySound 1
#define LoseLifeSound 2
using namespace sf;
class SoundEffectManager
{
public:
	void InitializeSoundEffect();
	void PlaySoundEffect(int index);
	bool CheckPlayStatus(int index);

	~SoundEffectManager();

	SoundBuffer* bufferLaser;
	Sound* soundLaser;

	SoundBuffer* bufferDestroyBrick;
	Sound* soundDestroyBrick;

	SoundBuffer* bufferLoseLife;
	Sound* soundLoseLife;
};
