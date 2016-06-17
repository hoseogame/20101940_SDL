#pragma once
#include "MenuButton.h"
#include "BaseCreator.h"

class MenuButtonCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new MenuButton();
	}
};