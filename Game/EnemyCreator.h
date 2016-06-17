#pragma once
#include "Enemy.h"
#include "BaseCreator.h"

class EnemyCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Enemy();
	}
};