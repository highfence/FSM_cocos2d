#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

class Player;
class Enemy;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
	void update(float);
    
	Vec2 calculateInterval();
	
	CREATE_FUNC(HelloWorld);


	Player* player;
	Enemy* enemy;
};

#endif // __HELLOWORLD_SCENE_H__
