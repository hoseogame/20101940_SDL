#pragma once
#include "Player.h"
#include "BaseCreator.h"

class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Player();
	}
};