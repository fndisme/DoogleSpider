/*
 * =====================================================================================
 *
 *       Filename:  GameplayLayer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月08日 14时23分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fang Dongheng (fndisme), fndisme@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef FND_GAME_GAMEPLAYLAYER_H
#define FND_GAME_GAMEPLAYLAYER_H
#include "cocos2d.h"

class GameplayLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    GameplayLayer() ;

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    //static cocos2d::CCScene* scene();
    
    // a selector callback
   // void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(GameplayLayer);

    void didAccelerate(cocos2d::CCAcceleration* acc) ;
    void update(float delta) ;
    bool ccTouchBegan(cocos2d::CCTouch*, cocos2d::CCEvent* event) ;
    void spiderDidDrop(cocos2d::CCObject*) ;
private:
    cocos2d::CCSprite* player;
    cocos2d::CCPoint playerVelocity ;
    cocos2d::CCArray* spiders ;
    int numSpiderMoved ;
    float spiderMovedDuration ;
    void initSpiders() ;
    void resetSpiders() ;
    void spidersUpdate(float) ;
    void runSpiderMoveSequence(cocos2d::CCSprite*) ;

};


#endif
