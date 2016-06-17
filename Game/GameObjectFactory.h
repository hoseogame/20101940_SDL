#pragma once
#include <string>
#include <map>
#include <iostream>
#include "BaseCreator.h"

class GameObject;
class GameObjectFactory
{
public:
	static GameObjectFactory* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new GameObjectFactory();
			return s_pInstance;
		}
		else
			return s_pInstance;
	}

	bool registerType(std::string typeID, BaseCreator* pCreator);
	GameObject* create(std::string typeID);
private:
	GameObjectFactory() {}
	std::map<std::string, BaseCreator*> m_creators;
	static GameObjectFactory* s_pInstance;
};
typedef GameObjectFactory TheGameObjectFactory;