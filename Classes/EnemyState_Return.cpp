#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Return.h"
#include "EnemyState_Search.h"

const float ORIGIN_RANGE = 50.f;

void EnemyState_Return::startState(Enemy* enemy)
{
	CCLOG("start_Return!");
}

// 원점으로 돌아간다. 이후 다시 서칭으로 바꾸어준다.
void EnemyState_Return::runState(Enemy* enemy, float dt)
{
	float originDistance = enemy->getOriginDistance();

	if (originDistance > ORIGIN_RANGE)
	{
		auto originUnitVec = enemy->getOriginUnitVec();
		enemy->move(originUnitVec, dt);
	}
	else
	{
		enemy->changeState<EnemyState_Search>();
	}
}

void EnemyState_Return::endState(Enemy* enemy)
{
	CCLOG("end_Return!");
}