//
//  Enemy1.h
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/24.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef __PlaneWar__Enemy1__
#define __PlaneWar__Enemy1__
#include "Enemy.h"
class Enemy1:public Enemy
{
public:
    Enemy1(std::string name = "shoot.png",sf::IntRect intrect =sf::IntRect(0, 0, 69, 99)):Enemy(name,intrect){}
    virtual bool down();
//    virtual void setimage();
private:
    sf::Texture texture;
    sf::Image image;
//    bool downbool = false;
};
#endif /* defined(__PlaneWar__Enemy1__) */
