#include "ExplosionEffect.h"
#include "Animation.h"

ExplosionEffect::ExplosionEffect(int type, Texture* t1, Texture* t2)
{
	name = "Explosion";
	life = 1;
	if (type == ShipExplode)
	{
		Animation sExplosion(*t1, 0, 0, 192, 192, 64, 0.5);
		aniExplosion = sExplosion;
	}
	else if (type == RockExplode)
	{

		Animation sExplosion(*t2, 0, 0, 256, 256, 48, 0.5);
		aniExplosion = sExplosion;
	}
}
