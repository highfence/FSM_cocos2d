#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Approach.h"
#include "EnemyState_Return.h"
#include "EnemyState_Escape.h"


void EnemyState_Approach::startState(Enemy* enemy)
{
	CCLOG("start_Approach!");
}

// ���� �ڸ����� 500 �ȼ� �ȱ����� �߰��Ѵ�.
// 500�ȼ��� �Ѿ�� �ٽ� ���ڸ��� ���ư����� state�� ����.
// ������ ������ �÷��̾�� �־����� �������� �̵�.
void EnemyState_Approach::runState(Enemy* enemy, float dt)
{
	float distanceFromOrigin = enemy->getDistanceFromOrigin();

	if (enemy->getIsAttacked())
	{
		enemy->changeState<EnemyState_Escape>();
	}
	else if (isEnemyOutOfOriginRange(enemy, distanceFromOrigin))
	{
		enemy->changeState<EnemyState_Return>();
	}
	else
	{
		auto unitVec = enemy->getUnitVec();
		enemy->move(unitVec, dt);
	}

}

void EnemyState_Approach::endState(Enemy* enemy)
{
	CCLOG("end_Approach!");
}

// enemy�� ������ return_range�� ������� �˷��ִ� �Լ�.
bool EnemyState_Approach::isEnemyOutOfOriginRange(Enemy *enemy, float distanceFromOrigin)
{
	if (distanceFromOrigin < enemy->RETURN_RANGE)
	{
		return false;
	}
	else
	{
		return true;
	}
}
