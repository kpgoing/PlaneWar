//
//  Army.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/24.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Enemy.h"
#include <random>
Enemy::Enemy(){
    if (!texture.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(0, 0,69, 99))) {
        return EXIT_FAILURE;
        }
    this->setTexture(texture);
    std::uniform_int_distribution<unsigned> u(0,400);
    std::default_random_engine e(time(0));
    this->setPosition(u(e), -100);
    
}
void Enemy::down()
{
    texture.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(534, 655, 69, 95));
    
}