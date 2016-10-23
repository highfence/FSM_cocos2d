#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Search.h"
#include "math.h" // for sqrt

const char ENEMY_RESOURCE[] = "enemy.png";
const char CIRCLE_RESOURCE[] = "pixel500circle.png";
const float INIT_WIDTH = 0.8f;
const float INIT_HEIGHT = 0.8f;
const int PIXEL_PER_SEC = 200;

auto visibleSize_E = Size(1024, 768);

bool Enemy::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	m_Origin = Vec2(visibleSize_E.width * INIT_WIDTH, visibleSize_E.height * INIT_HEIGHT);
	m_pHead = Sprite::create(ENEMY_RESOURCE);
	m_pHead->setPosition(Vec2(visibleSize_E.width * INIT_WIDTH, visibleSize_E.height * INIT_HEIGHT));
	addChild(m_pHead);

	changeState<EnemyState_Search>();

	return true;
}

void Enemy::update(float dt)
{
	m_pState->runState(this, dt);
}


// 클래스 밖에서 enemy의 위치가 필요할 때 사용하는 함수.
Vec2 Enemy::getPosition()
{
	Vec2 position = Vec2(m_pHead->getPosition().x, m_pHead->getPosition().y);
	return position;
}


// 클래스 밖에서 Player와의 거리를 알려주기 위하여 사용하는 set함수. 
void Enemy::setInteval(Vec2 interval)
{
	float x = interval.x;
	float y = interval.y;

	m_Interval = Vec2(x, y);
	m_Distance = abs(sqrt( x * x + y * y ));

	return;
}

// 플레이어와 enemy와의 거리를 반환하는 함수.
float Enemy::getDistance()
{
	return m_Distance;
}

// 가야할 유닛벡터를 반환하는 함수.
Vec2 Enemy::getUnitVec()
{
	Vec2 unitVec(m_Interval.x / m_Distance, m_Interval.y / m_Distance);
	return unitVec;
}

// 원래 있던 자리까지의 유닛벡터를 반환하는 함수.
Vec2 Enemy::getOriginUnitVec()
{
	float originDistance = getOriginDistance();
	Vec2 origin = getOrigin();

	float x = origin.x - m_pHead->getPosition().x;
	float y = origin.y - m_pHead->getPosition().y;

	Vec2 originUnitVec(x / originDistance, y / originDistance);
	return originUnitVec;
}

// 유닛벡터와 dt를 받아 움직이게 하는 함수.
void Enemy::move(Vec2 unitVec, float dt)
{
	float dtX = unitVec.x * PIXEL_PER_SEC * dt;
	float dtY = unitVec.y * PIXEL_PER_SEC * dt;

	auto currentX = m_pHead->getPositionX();
	auto currentY = m_pHead->getPositionY();

	m_pHead->setPosition(currentX + dtX, currentY + dtY);
}

// 원래 위치로부터 얼마나 떨어져 있는지를 반환하는 함수.
float Enemy::getOriginDistance()
{
	float originDistance;
	
	float currentX = m_pHead->getPosition().x;
	float currentY = m_pHead->getPosition().y;

	float x = m_Origin.x - currentX;
	float y = m_Origin.y - currentY;

	originDistance = abs(sqrt(x * x + y * y));

	return originDistance;
}

// 원점을 반환하는 함수.
Vec2 Enemy::getOrigin()
{
	return m_Origin;
}

// 현재의 State를 반환하는 함수.
EnemyState * Enemy::getState()
{
	return m_pState;
}

// State를 세팅하는 함수.
void Enemy::setState(EnemyState * inputState)
{
	m_pState = inputState;
	return;
}



