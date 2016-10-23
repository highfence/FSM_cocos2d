#include "pch.h"
#include "HelloWorldScene.h"
#include "player.h"
#include "Enemy.h"
#include "SimpleAudioEngine.h"


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	player = Player::create();
	addChild(player);

	enemy = Enemy::create();
	enemy->setInteval(calculateInterval());
	addChild(enemy);

	scheduleUpdate();
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
}

void HelloWorld::update(float dt)
{
	enemy->setInteval(calculateInterval());
	player->move(dt);
}

// player와 enemy간의 interval을 반환하는 함수.
Vec2 HelloWorld::calculateInterval()
{
	Vec2 enemyPosition = enemy->getPosition();
	Vec2 playerPosition = player->getPosition();

	Vec2 interval = Vec2(playerPosition.x - enemyPosition.x, playerPosition.y - enemyPosition.y);

	return interval;
}
