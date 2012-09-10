/*
 * =====================================================================================
 *
 *       Filename:  BackgroundLayer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月08日 13时54分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fang Dongheng (fndisme), fndisme@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "BackgroundLayer.h"
#include <iostream>

USING_NS_CC ;

bool BackgroundLayer::init() {
  if(!CCLayer::init()) return false ;

  CCSprite* backgroundImage = CCSprite::create("background.png") ;

  CCSize visualSize = CCDirector::sharedDirector()->getVisibleSize() ;
  CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin() ;

  backgroundImage->setPosition(ccp(visualSize.width / 2 + origin.x,
        visualSize.height / 2 + origin.y)) ;
  addChild(backgroundImage, 0, 0) ;
  backgroundImage->setScaleX(visualSize.width / 1024.0f) ;
  backgroundImage->setScaleY(visualSize.height / 768.0f) ;

  std::cout << "x:" << visualSize.width / 2 + origin.x
    << " y:" << visualSize.height / 2 + origin.y << std::endl ;
  

  return true ;
}
