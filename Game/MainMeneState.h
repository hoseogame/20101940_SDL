#pragma once
#include "MenuState.h"
#include "GameObject.h"
#include "StateParser.h"
#include "MenuButton.h"
#include "TextureManager.h"
#include "Game.h"

class MainMeneState : public MenuState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }

private:
	virtual void setCallbacks(const std::vector<Callback>& callbacks);
	static void s_menuToPlay();
	static void s_exitFromMenu();
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
	//std::vector<std::string> m_textureIDList;
	//static bool isPlay;
};

