#pragma once
#include "Bullet.h"
#include "InputHandler.h"

Bullet::Bullet() : AnimatedGraphic()
{
}

void Bullet::draw()
{
	AnimatedGraphic::draw();
}

void Bullet::update()
{
	handleInput();
	AnimatedGraphic::update();

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); )
	{
		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed;
		_viBullet->y += -sinf(_viBullet->angle) * _viBullet->speed;

		//m_velocity.setX(_viBullet->x);
		m_velocity.setY(-_viBullet->y);

		++_viBullet;
	}
}

void Bullet::clean()
{
	AnimatedGraphic::clean();
}

void Bullet::handleInput()
{
	m_velocity /= 30;
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		fire(400, 350, -90, 5);
	}

}

void Bullet::load(const LoaderParams* pParam)
{
	m_velocity.setY(2);
	AnimatedGraphic::load(pParam);
}


void Bullet::fire(float x, float y, float angle, float speed)
{
	tagBullet bullet;
	bullet.speed = speed;
	bullet.angle = angle;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;

	_vBullet.push_back(bullet);
}