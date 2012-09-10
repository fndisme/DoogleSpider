/*
 * =====================================================================================
 *
 *       Filename:  GameScene.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月08日 15时08分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fang Dongheng (fndisme), fndisme@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef FND_GAME_GAMESCENE_H
#define FND_GAME_GAMESCENE_H
#include "cocos2d.h"

class GameScene : public cocos2d::CCScene {
  typedef cocos2d::CCScene base_type ;
  public:
    virtual bool init() ;

    CREATE_FUNC(GameScene) ;
  private:

} ;
#endif
