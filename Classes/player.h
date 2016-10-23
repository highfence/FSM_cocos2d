#pragma once

class Player : public Sprite
{
public :
	CREATE_FUNC(Player);

	virtual bool   init();
	void           onKeyPressed(EventKeyboard::KeyCode, Event*);
	void           onKeyReleased(EventKeyboard::KeyCode, Event*);

	void           move(float);
	Vec2		   getPosition();

private :
	Sprite*        m_pHead;
	int            m_Direction[2];
	int            m_Hp;
};