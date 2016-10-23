#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Approach.h"
#include "EnemyState_Search.h"
#include "EnemyState_Return.h"

const float RETURN_RANGE = 500.f;

void EnemyState_Approach::startState(Enemy* enemy)
{
	CCLOG("start_Approach!");
}

// 원래 자리에서 500 픽셀 안까지는 추격한다.
// 500픽셀이 넘어가면 다시 제자리로 돌아가도록 state를 변경.
void EnemyState_Approach::runState(Enemy* enemy, float dt)
{
	float originDistance = enemy->getOriginDistance();
	
	if (originDistance < RETURN_RANGE)
	{
		auto unitVec = enemy->getUnitVec();
		enemy->move(unitVec, dt);
	}
	else
	{
		enemy->changeState<EnemyState_Return>();
	}

}

void EnemyState_Approach::endState(Enemy* enemy)
{
	CCLOG("end_Approach!");
}