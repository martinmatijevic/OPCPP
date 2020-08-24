#include "Animation.h"

Animation::Animation(Texture &t, int x, int y, int w, int h, int count, float Speed)
{
	Frame = 0;
	speed = Speed;
	for (int i = 0; i<count; i++)	frames.push_back(IntRect(x + i*w, y, w, h));
	sprite.setTexture(t);
	sprite.setOrigin(w / 2, h / 2);
	sprite.setTextureRect(frames[0]);
}

void Animation::Update(sf::RenderWindow* window)
{
	Frame += speed;
	int n = frames.size();
	if (Frame >= n) Frame -= n;
	if (n>0) sprite.setTextureRect(frames[int(Frame)]);
}

bool Animation::IsEnd()
{
	return Frame + speed >= frames.size();
}
