#pragma once
#include "PlayState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "GameStateMachine.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "Enemy.h"
#include "SDLGameObject.h"
#include "GameOverState.h"
#include <iostream>
#include "StateParser.h"
#include "GameObjectFactory.h"


const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	//dynamic_cast<SDLGameObject*>(m_gameObjects[1])->
	//if (m_gameObjects[0]->g);
	//dynamic_cast<SDLGameObject*>(m_gameObjects[1])->getBullet()->setBulletX(dynamic_cast<SDLGameObject*>(m_gameObjects[0])->getPlayer()->getPosition().getX());
	//dynamic_cast<SDLGameObject*>(m_gameObjects[1])->getVIBullet()[0]->setBulletX(dynamic_cast<SDLGameObject*>(m_gameObjects[0])->getPlayer()->getPosition().getX());
	//dynamic_cast<SDLGameObject*>(m_gameObjects[1])->getPlay
	for (int i = 2; i < m_gameObjects.size(); i++)
	{
		if (checkCollision(
			dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
			dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
		{

			std::string textureID = "bullet";
			std::string typeID = "Bullet";


			//pGameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID, animSpeed));

			m_gameObjects.erase(m_gameObjects.begin() + i);
			//m_gameObjects.erase(m_gameObjects.begin() + 1);

			//GameObject* pGameObject = TheGameObjectFactory::Instance()->create(typeID);
			m_gameObjects[1] = TheGameObjectFactory::Instance()->create(typeID);;
			m_gameObjects[1]->load(new LoaderParams(200, 350, 21, 21, textureID, 1, 0, 1));

			//m_gameObjects.push_back(pGameObject);
			//std::string _textID = "Bullet";
			//(x, y, width, height, textureID, numFrames, callbackID, animSpeed))
			//m_gameObjects[1]->load(LoaderParams(100, 100, 100, 100, _textID, 1, 0, 0));
			//StateParser stateParser;
			//stateParser.parseState("text.xml", s_playID, &m_gameObjects, &m_textureIDList);
		}
		if (checkCollision(
			dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
			dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
		{
			TheGame::Instance()->setState(State::GameOver);
		}
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("text.xml", s_playID, &m_gameObjects, &m_textureIDList);
	std::cout << "entering PlayState\n";

	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }

	return true;
}