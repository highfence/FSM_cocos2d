#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Escape.h"
#include "EnemyState_Approach.h"

void EnemyState_Escape::startState(Enemy* enemy)
{
	CCLOG("start_Escape!");
}

// 플레이어가 A를 누르고 있으면 계속 유닛벡터의 반대쪽으로 가도록 이동.
// 아니라면 다시 어프로치 상태로 전환.
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