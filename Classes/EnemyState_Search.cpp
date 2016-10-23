#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Search.h"
#include "EnemyState_Approach.h"

const float SEARCHING_RANGE = 400.f;

void EnemyState_Search::startState(Enemy* enemy)
{
	CCLOG("start_Searching!");
}

void EnemyState_Search::runState(Enemy* enemy, float dt)
{
	float distance = enemy->getDistance();

	if ( distance < SEARCHING_RANGE)
	{
		enemy->changeState<EnemyState_Approach>();
	}
}

void EnemyState_Search::endState(Enemy* enemy)
{
	CCLOG("end_Searching!");
}