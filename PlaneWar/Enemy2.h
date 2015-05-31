//
//  Enemy2.h
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/24.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef __PlaneWar__Enemy2__
#define __PlaneWar__Enemy2__
#include "Enemy.h"
class Enemy2:public Enemy
{
public:
    Enemy2(std::string name = "shoot.png",sf::IntRect intrect = sf::IntRect(335, 750,169, 258)):Enemy(name,intrect){
        weapons->push_back(new Weapon(-1));
        weapons->push_back(new Weapon(1));
    }

    virtual bool down();
private:
    sf::Texture texture;
    sf::Image image;
};
#endif /* defined(__PlaneWar__Enemy2__) */
