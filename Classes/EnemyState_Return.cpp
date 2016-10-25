#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Return.h"
#include "EnemyState_Search.h"



void EnemyState_Return::startState(Enemy* enemy)
{
	CCLOG("start_Return!");
}

// 원점으로 돌아간다. 이후 다시 서칭으로 바꾸어준다.
void EnemyState_Return::runState(Enemy* enemy, float dt)
{
	float distanceFromOrigin = enemy->getDistanceFromOrigin();

	if (isReturnComplete(enemy, distanceFromOrigin))
	{
		enemy->changeState<EnemyState_Search>();
	}
	else
	{
		auto originUnitVec = enemy->getUnitVecToOrigin();
		enemy->move(originUnitVec, dt);
	}
}

void EnemyState_Return::endState(Enemy* enemy)
{
	CCLOG("end_Return!");
}

bool EnemyState_Return::isReturnComplete(Enemy *enemy, float distanceFromOrigin)
{
	if (distanceFromOrigin < enemy->ORIGIN_RANGE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
