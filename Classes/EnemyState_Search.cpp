#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Search.h"
#include "EnemyState_Approach.h"


void EnemyState_Search::startState(Enemy* enemy)
{
	CCLOG("start_Searching!");
}

void EnemyState_Search::runState(Enemy* enemy, float dt)
{
	float distance = enemy->getDistance();

	if ( isPlayerInSearchRange(enemy, distance) )
	{
		enemy->changeState<EnemyState_Approach>();
	}
}

void EnemyState_Search::endState(Enemy* enemy)
{
	CCLOG("end_Searching!");
}

// 플레이어가 enemy의 SEARCHING_RANGE안에 있다면 true를 반환하는 함수.
bool EnemyState_Search::isPlayerInSearchRange(Enemy* enemy, float distance)
{
	if (distance < enemy->SEARCHING_RANGE)
	{
		return true;
	}

	return false;
}
