#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Search.h"
#include "math.h" // for sqrt

const char ENEMY_RESOURCE[] = "enemy.png";
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


// Ŭ���� �ۿ��� enemy�� ��ġ�� �ʿ��� �� ����ϴ� �Լ�.
Vec2 Enemy::getPosition()
{
	Vec2 position = Vec2(m_pHead->getPosition().x, m_pHead->getPosition().y);
	return position;
}


// Ŭ���� �ۿ��� Player���� �Ÿ��� �˷��ֱ� ���Ͽ� ����ϴ� set�Լ�. 
void Enemy::setInterval(Vec2 interval)
{
	float x = interval.x;
	float y = interval.y;

	m_Interval = Vec2(x, y);
	m_Distance = abs(sqrt( x * x + y * y ));

	return;
}

// �÷��̾�� enemy���� �Ÿ��� ��ȯ�ϴ� �Լ�.
float Enemy::getDistance()
{
	return m_Distance;
}

// ������ ���ֺ��͸� ��ȯ�ϴ� �Լ�.
Vec2 Enemy::getUnitVec()
{
	Vec2 unitVec(m_Interval.x / m_Distance, m_Interval.y / m_Distance);
	return unitVec;
}

// ���� �ִ� �ڸ������� ���ֺ��͸� ��ȯ�ϴ� �Լ�.
Vec2 Enemy::getUnitVecToOrigin()
{
	float distanceFromOrigin = getDistanceFromOrigin();
	Vec2 origin = getOriginPoint();

	float x = origin.x - m_pHead->getPosition().x;
	float y = origin.y - m_pHead->getPosition().y;

	Vec2 unitVecToOrigin(x / distanceFromOrigin, y / distanceFromOrigin);
	return unitVecToOrigin;
}

// ������ �޴��� Ȯ�����ִ� �Լ�.
void Enemy::setIsAttacked(bool IsAttacked)
{
	m_IsAttacked = IsAttacked;
	return;
}

// IsAttacked�� ��ȯ�ϴ� �Լ�.
bool Enemy::getIsAttacked()
{
	return m_IsAttacked;
}

// ���ֺ��Ϳ� dt�� �޾� �����̰� �ϴ� �Լ�.
void Enemy::move(Vec2 unitVec, float dt)
{
	float dtX = unitVec.x * PIXEL_PER_SEC * dt;
	float dtY = unitVec.y * PIXEL_PER_SEC * dt;

	auto currentX = m_pHead->getPositionX();
	auto currentY = m_pHead->getPositionY();

	m_pHead->setPosition(currentX + dtX, currentY + dtY);
}

// ���� ��ġ�κ��� �󸶳� ������ �ִ����� ��ȯ�ϴ� �Լ�.
float Enemy::getDistanceFromOrigin()
{
	float distanceFromOrigin;
	
	float currentX = m_pHead->getPosition().x;
	float currentY = m_pHead->getPosition().y;

	float x = m_Origin.x - currentX;
	float y = m_Origin.y - currentY;

	distanceFromOrigin = abs(sqrt(x * x + y * y));

	return distanceFromOrigin;
}

// ������ ��ȯ�ϴ� �Լ�.
Vec2 Enemy::getOriginPoint()
{
	return m_Origin;
}

// ������ State�� ��ȯ�ϴ� �Լ�.
EnemyState * Enemy::getState()
{
	return m_pState;
}

// State�� �����ϴ� �Լ�.
void Enemy::setState(EnemyState * inputState)
{
	m_pState = inputState;
	return;
}



