#pragma once
#include "EnemyState.h"

// 접근을 포기하고 원점으로 다시 돌아가는 상태.
class EnemyState_Return : public EnemyState
{
public : 
	CREATE_FUNC(EnemyState_Return);
	bool		init() override
	{
		return true;
	}

	void		startState(Enemy* enemy) override;
	void		runState(Enemy* enemy, float dt) override;
	void		endState(Enemy* enemy) override;

	bool		isReturnComplete(Enemy*, float);
};