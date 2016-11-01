#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Escape.h"
#include "EnemyState_Approach.h"

void EnemyState_Escape::startState(Enemy* enemy)
{
	CCLOG("start_Escape!");
}

// �÷��̾ A�� ������ ������ ��� ���ֺ����� �ݴ������� ������ �̵�.
// �ƴ϶�� �ٽ� ������ġ ���·� ��ȯ.
void EnemyState_Escape::runState(Enemy* enemy, float dt)
{
	if (!enemy->getIsAttacked())
	{
		enemy->changeState<EnemyState_Approach>();
	}
	else
	{
		auto unitVec = enemy->getUnitVec();
		enemy->move(-unitVec, dt);
	}
}

void EnemyState_Escape::endState(Enemy* enemy)
{
	CCLOG("end_Escape!");
}