#pragma once
#include "AnimatedGraphic.h"
#include "Bullet.h"
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#define SPEED 5

class Bullet;
class Player : public AnimatedGraphic
{
public:
	Player();
	virtual ~Player() {}
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams *pParams);

	Bullet* bulletLink(Bullet* bullet) { _bullet = bullet; }

private:
	void handleInput();
private:
	float _x, _y;
	Bullet* _bullet;
};