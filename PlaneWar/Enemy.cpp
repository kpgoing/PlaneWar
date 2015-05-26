//
//  Enemy.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/24.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//


#include "Enemy.h"
#include <random>
#include <iostream>
bool Enemy::down()
{
    this->setTextureRect(sf::IntRect(267, 347,57, 51));
    this->setTextureRect(sf::IntRect(873, 697,57, 51));
    this->setTextureRect(sf::IntRect(267, 296,57, 51));
    this->setTextureRect(sf::IntRect(930, 697,57, 51));
    downbool = true;
    return true;
}
//void Enemy::fire2()
//{
//    Weapon.
//}