#pragma once

#include "EnemyState.h"



class Enemy : public Sprite
{
public :
	CREATE_FUNC(Enemy);

	virtual bool      init();
	virtual void      update(float dt) override;

	/* State */
	template<typename T_STATE>
	void              changeState();

	EnemyState*       getState();
	void              setState(EnemyState*);

	/* Functions */
	Vec2			  getPosition();
	void			  setInterval(Vec2);
	float			  getDistance();
	Vec2              getUnitVec();
	void              move(Vec2, float);
	float             getDistanceFromOrigin();
	Vec2              getOriginPoint();
	Vec2			  getUnitVecToOrigin();

	/* Const values */
	const float		  SEARCHING_RANGE = 400.f;
	const float       RETURN_RANGE = 500.f;
	const float		  ORIGIN_RANGE = 50.f;

private :
	Sprite*           m_pHead;
	EnemyState*		  m_pState;

	Vec2	          m_Origin;
	Vec2			  m_Interval;
	float			  m_Distance;

};


// State를 전환.
template <typename T_STATE>
void Enemy::changeState()
{
	// state가 존재한다면 종료.
	if (m_pState)
	{
		getState()->endState(this);
		removeComponent(m_pState);
	}

	auto m_pState = T_STATE::create();
	setState(m_pState);
	getState()->startState(this);
	addComponent(m_pState);

	return;
}