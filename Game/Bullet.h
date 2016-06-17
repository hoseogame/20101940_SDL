#pragma once
#include "AnimatedGraphic.h"
#include "BaseCreator.h"
#include <vector>

struct tagBullet
{
	float angle;
	float x, y;
	float fireX, fireY;
	float speed;
	bool fire;
};

class Bullet : public AnimatedGraphic
{
public:
	Bullet();
	~Bullet() {}
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParam);

	void fire(float x, float y, float angle, float speed);

	tagBullet setBulletX(float x) { _bullet.x = x; }
	float getBulletX(void) { return _bullet.x; }
	tagBullet setBulletY(float x) { _bullet.y = x; }
	float getBulletY(void) { return _bullet.y; }

private:
	void handleInput();
	tagBullet _bullet;

	std::vector<tagBullet> _vBullet;
	std::vector<tagBullet>::iterator _viBullet;
};


class BulletCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Bullet();
	}
};