/*
 * =====================================================================================
 *
 *       Filename:  BackgroundLayer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月08日 13时52分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fang Dongheng (fndisme), fndisme@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef FND_GAME_BACKGROUNDLAYER_H
#define FND_GAME_BACKGROUNDLAYER_H
#include "cocos2d.h"

class BackgroundLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    //static cocos2d::CCScene* scene();
    
    // a selector callback
   // void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(BackgroundLayer);
};


#endif
