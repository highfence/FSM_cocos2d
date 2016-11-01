#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Approach.h"
#include "EnemyState_Return.h"
#include "EnemyState_Escape.h"


void EnemyState_Approach::startState(Enemy* enemy)
{
	CCLOG("start_Approach!");
}

// 원래 자리에서 500 픽셀 안까지는 추격한다.
// 500픽셀이 넘어가면 다시 제자리로 돌아가도록 state를 변경.
// 공격을 받으면 플레이어에서 멀어지는 방향으로 이동.
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

// enemy가 내부의 return_range를 벗어났는지 알려주는 함수.
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
