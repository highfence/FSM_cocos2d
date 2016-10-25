#include "pch.h"
#include "player.h"

const char PLAYER_RESOURCE[] = "player.png";
const float INIT_WIDTH = 0.2f;
const float INIT_HEIGHT = 0.2f;
const int MAX_HP = 4;
const int PIXEL_PER_SEC = 300;
const int _x = 0;
const int _y = 1;

auto visibleSize = Size(1024, 768);


enum DIRECTION
{
	NONE = 0, RIGHT = 1, LEFT = -1, UP = 1, DOWN = -1
};

bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	// 초기 방향 설정
	m_Direction[_x] = NONE;
	m_Direction[_y] = NONE;

	// 초기 스프라이트 설정.
	m_Hp = MAX_HP;
	m_pHead = Sprite::create(PLAYER_RESOURCE);
	m_pHead->setPosition(Vec2(visibleSize.width * INIT_WIDTH, visibleSize.height * INIT_HEIGHT));
	addChild(m_pHead);

	// 키보드 입력을 위한 keylistener 설정.
	auto keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
	keylistener->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(keylistener, 2);


	return true;
}

void Player::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event)
{

	switch (keyCode)
	{
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW :
			m_Direction[_x] = RIGHT;
			break;
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW :
			m_Direction[_x] = LEFT;
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW :
			m_Direction[_y] = UP;
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW :
			m_Direction[_y] = DOWN;
			break;
	}
}

void Player::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event)
{

	switch (keyCode)
	{
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			m_Direction[_x] = NONE;
			break;
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			m_Direction[_x] = NONE;
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
			m_Direction[_y] = NONE;
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			m_Direction[_y] = NONE;
			break;
	}
}

void Player::move(float dt)
{
	float dtX = (float)m_Direction[_x] * PIXEL_PER_SEC * dt;
	float dtY = (float)m_Direction[_y] * PIXEL_PER_SEC * dt;

	auto currentX = m_pHead->getPositionX();
	auto currentY = m_pHead->getPositionY();

	m_pHead->setPosition(currentX + dtX, currentY + dtY);
}

// 클래스 밖에서 player의 위치를 알고 싶을 때 사용하는 함수.
Vec2 Player::getPosition()
{
	Vec2 position = Vec2(m_pHead->getPosition().x, m_pHead->getPosition().y);
	return position;
}
