#pragma once
#include "EnemyState.h"

// Player와의 거리가 일정 이하 될 때까지 기다리는 상태.
class EnemyState_Search : public EnemyState
{
public :
	CREATE_FUNC(EnemyState_Search);
	bool		init() override
	{
		return true;
	}

	void		startState(Enemy* enemy) override;
	void		runState(Enemy* enemy, float dt) override;
	void		endState(Enemy* enemy) override;

	bool		isPlayerInSearchRange(Enemy*, float);

};