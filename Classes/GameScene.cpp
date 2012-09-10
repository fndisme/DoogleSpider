/*
 * =====================================================================================
 *
 *       Filename:  GameScene.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月08日 15时09分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fang Dongheng (fndisme), fndisme@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "GameScene.h"
#include "GameplayLayer.h"
#include "BackgroundLayer.h"
#include <cassert>

USING_NS_CC ;

bool GameScene::init() {

  if(!base_type::init()) return false ;


  BackgroundLayer* backLayer = BackgroundLayer::create() ;
  addChild(backLayer, 0) ;
  GameplayLayer* gameLayer = GameplayLayer::create() ;
  addChild(gameLayer, 5) ;
  return true ;
}

