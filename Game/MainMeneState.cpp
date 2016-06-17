#include "MainMeneState.h"

const std::string MainMeneState::s_menuID = "MENU";
//bool MenuState::isPlay = false;

void MainMeneState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MainMeneState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MainMeneState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("text.xml", s_menuID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);

	setCallbacks(m_callbacks);
	std::cout << "entering MenuState\n";

	return true;
}

void MainMeneState::setCallbacks(const std::vector<Callback>& callbacks)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback( callbacks[pButton->getCallbackID()] );
		}
	}
}

bool MainMeneState::onExit()
{
	//for (int i = 0; i < m_gameObjects.size(); i++)
	//{
	//	m_gameObjects[i]->clean();
	//}
	//m_gameObjects.clear();

	//MenuState::onExit();
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	//TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	//TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

	return true;
}
void MainMeneState::s_menuToPlay()
{
	TheGame::Instance()->setState(State::Play);
}

void MainMeneState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}
