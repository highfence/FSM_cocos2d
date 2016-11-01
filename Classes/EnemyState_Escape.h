#pragma once
#include "EnemyState.h"

// Player에게서 공격을 받아 도망가는 상태
class EnemyState_Escape : public EnemyState
{
public :
	CREATE_FUNC(EnemyState_Escape);
	bool		init() override
	{
		return true;
	}

	void		startState(Enemy* enemy) override;
	void		runState(Enemy* enemy, float dt) override;
	void		endState(Enemy* enemy) override;

};