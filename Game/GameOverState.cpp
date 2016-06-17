#pragma once
#include "GameOverState.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameObject.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
#include "StateParser.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

bool GameOverState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("text.xml", s_gameOverID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_gameOverToMain);
	m_callbacks.push_back(s_restartPlay);
	setCallbacks(m_callbacks);
	std::cout << "entering PauseState\n";

	return true;
}

bool GameOverState::onExit()
{
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	return true;
}
void GameOverState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void GameOverState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->setState(State::Menu);
}

void GameOverState::s_restartPlay()
{
	TheGame::Instance()->setState(State::Play);
}
void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}
