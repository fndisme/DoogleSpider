/*
 * =====================================================================================
 *
 *       Filename:  GameplayLayer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月08日 14时25分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fang Dongheng (fndisme), fndisme@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "GameplayLayer.h"

USING_NS_CC ;

bool GameplayLayer::init() {
  if(!CCLayer::init()) return false ;

  setTouchEnabled(true) ;
  //setAccelerometerEnabled(true) ;
  CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true) ;

  player = CCSprite::create("alien.png") ;

  CCSize visualSize = CCDirector::sharedDirector()->getVisibleSize() ;
  CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin() ;
  float imageHeight = player->getTexture()->getContentSizeInPixels().height ;

  player->setPosition(ccp(visualSize.width / 2 + origin.x,
        imageHeight / 2 + origin.y)) ;
  addChild(player, 0, 1) ;
  scheduleUpdate() ;
  initSpiders() ;
  return true ;
}

void GameplayLayer::initSpiders() {
  CCSize size = CCDirector::sharedDirector()->getWinSize() ;
  CCSprite* tempSpider = CCSprite::create("spider.png") ;
  float imageWidth = tempSpider->getTexture()->getContentSizeInPixels().width ;

  int numberSpiders = size.width / imageWidth ;

  spiders = CCArray::create(this, numberSpiders) ;
  for(int i = 0 ; i < numberSpiders ; ++i) {
    CCSprite* spider = CCSprite::create("spider.png") ;
    addChild(spider, 0, 2) ;
    spiders->addObject(spider) ;
  }

  resetSpiders() ;
}

void GameplayLayer::resetSpiders() {

  CCSize screenSize = CCDirector::sharedDirector()->getWinSize() ;

  CCSprite* tempSpider = static_cast<CCSprite*>(spiders->lastObject()) ;

  CCSize size = tempSpider->getTexture()->getContentSizeInPixels() ;

  int num = spiders->count() ;

  for(int i = 0 ; i < num ; ++i) {
    CCSprite* spider = static_cast<CCSprite*>(spiders->objectAtIndex(i)) ;
    spider->setPosition(ccp(
          size.width * i + size.width * 0.5f,
          screenSize.height + size.height)) ;
    spider->stopAllActions() ;
  }

  unschedule(schedule_selector(GameplayLayer::spidersUpdate)) ;

  schedule(schedule_selector(GameplayLayer::spidersUpdate), 0.7f) ;
  numSpiderMoved = 0 ;
  spiderMovedDuration = 4.0f ;
}

void GameplayLayer::spidersUpdate(float f) {
  for(int i = 0 ; i < 10 ; ++i) {
    int randomSpiderIndex = CCRANDOM_0_1() * spiders->count() ;
    CCSprite* spider = static_cast<CCSprite*>(spiders->objectAtIndex(randomSpiderIndex)) ;
    if(spider->numberOfRunningActions() == 0) {
      runSpiderMoveSequence(spider) ;
    }
  }
}

void GameplayLayer::runSpiderMoveSequence(CCSprite* spider) {
  numSpiderMoved ++ ;
  if(numSpiderMoved % 8 == 0 && spiderMovedDuration > 2.0f) {
    spiderMovedDuration -= 1.0f ;
  }

  CCPoint belowScreenPosition =
    ccp(spider->getPosition().x,
        -spider->getTexture()->getContentSizeInPixels().height) ;
  CCMoveTo* newmove = CCMoveTo::create(spiderMovedDuration, belowScreenPosition) ;
  CCCallFuncN* callDidDrop = CCCallFuncN::create(this, callfuncN_selector(
        GameplayLayer::spiderDidDrop)) ;
  CCFiniteTimeAction* sequence = CCSequence::create(newmove, callDidDrop, NULL) ;
  spider->runAction(sequence) ;

}

void GameplayLayer::spiderDidDrop(CCObject* o) {
  CCSprite* spider = static_cast<CCSprite*>(o) ;
  CC

}

bool GameplayLayer::ccTouchBegan(CCTouch* touch, CCEvent* event) {
  CCLog("touch at %f %f", touch->getLocation().x, touch->getLocation().y) ;
  if(touch->getLocation().x >= player->getPosition().x) playerVelocity.x = 100.0f ;
  else playerVelocity.x = -100.0f ;
  return true ;
}

void GameplayLayer::update(float f) {

  CCSize visualSize = CCDirector::sharedDirector()->getVisibleSize() ;
  CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin() ;
  CCSize picSize = player->getTexture()->getContentSizeInPixels() ;
  CCPoint pos = player->getPosition() ;
  pos.x += playerVelocity.x * f ;
  if(pos.x < origin.x + picSize.width * 0.5f) 
    pos.x = origin.x + picSize.width * 0.5f ;
  if(pos.x > origin.x + visualSize.width - picSize.width * 0.5f)
    pos.x = origin.x + visualSize.width - picSize.width * 0.5f ;
  player->setPosition(pos) ;
}

void GameplayLayer::didAccelerate(CCAcceleration* acc) {
  CCPoint pos = player->getPosition() ;
  pos.x += acc->x * 10 ;
  player->setPosition(pos) ;
}

GameplayLayer::GameplayLayer() : player(0),playerVelocity(0.0f, 0.0f) {}
