#pragma once
#include "Player.h"
#include "InputHandler.h"
#include <iostream>
#include "Bullet.h"
using namespace std;

Player::Player() : AnimatedGraphic()
{
	_x = 300;
	_y = 350;
	//Vector2D(_x, _y);
	m_velocity.setX(300);
	m_velocity.setY(350);

}

void Player::draw()
{
	AnimatedGraphic::draw();
}

void Player::update()
{
	//m_velocity.setX(0);
	//m_velocity.setY(0);
	handleInput();

	AnimatedGraphic::update();
}

void Player::handleInput()
{
	//Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	//m_velocity = *target - m_position;
	m_velocity /= 30;
	//	SDL_SCANCODE_RIGHT = 79,
	//	SDL_SCANCODE_LEFT = 80,
	//	SDL_SCANCODE_DOWN = 81,
	//	SDL_SCANCODE_UP = 82,
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && _x > 0)
	{
		//if (m_velocity.getX() < 0)
			//m_velocity.getX() - 2;
		m_velocity.setX(m_velocity.getX() - SPEED);
		_x -= SPEED;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		//m_velocity.getX() + 2;
		m_velocity.setX(m_velocity.getX() + SPEED);
		_x += SPEED;
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) && _y > 0)
	{
		//if (m_velocity.getX() < 0)
		//m_velocity.getX() - 2;
		m_velocity.setY(m_velocity.getY() - SPEED);
		_y -= SPEED;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		//m_velocity.getX() + 2;
		m_velocity.setY(m_velocity.getY() + SPEED);
		_y += SPEED;
	}
	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	//{
	//	_bullet->fire(_x, _y, -90, 5);
	//	//_gravity -= 0.2f;
	//	//m_velocity.setY(m_velocity.getY() + _gravity);
	//}

}

void Player::clean()
{
	SDLGameObject::clean();
}

void Player::load(const LoaderParams* pParam)
{
	AnimatedGraphic::load(pParam);
}