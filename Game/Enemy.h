#pragma once
#include "AnimatedGraphic.h"

class Enemy : public AnimatedGraphic
{
public:
	Enemy();
	~Enemy(){}
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParam);
private:
	void handleInput();
};