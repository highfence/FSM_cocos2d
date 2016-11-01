#pragma once
#include "EnemyState.h"

// Player���Լ� ������ �޾� �������� ����
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