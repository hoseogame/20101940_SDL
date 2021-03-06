#pragma once
#include "Enemy.h"
#include "InputHandler.h"

Enemy::Enemy() : AnimatedGraphic()
{
}

void Enemy::draw()
{
	AnimatedGraphic::draw();
}

void Enemy::update()
{
	//if (m_position.getY() < 0) {
	//	m_velocity.setY(2);
	//}
	//else if (m_position.getY() > 400) {
	//	m_velocity.setY(-2);
	//}

	//m_velocity /= 30;

	//m_velocity.setX(m_velocity.getX() - 4);

	AnimatedGraphic::update();
}

void Enemy::clean()
{
	AnimatedGraphic::clean();
}

void Enemy::handleInput()
{
	/*if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;*/
}

void Enemy::load(const LoaderParams* pParam)
{
	m_velocity.setY(2);
	AnimatedGraphic::load(pParam);
}