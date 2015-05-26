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
    switch (downstate) {
        case 1:this->setTextureRect(sf::IntRect(267, 347,57, 51));
            downstate++;
        break;
        case 2:this->setTextureRect(sf::IntRect(873, 697,57, 51));
         downstate++;
            break;
        case 3:this->setTextureRect(sf::IntRect(267, 296,57, 51));
         downstate++;
            break;
        case 4: this->setTextureRect(sf::IntRect(930, 697,57, 51));
         downstate++;
            downover = true;
            break;
        default:
            break;
    }
//    this->setTextureRect(sf::IntRect(267, 347,57, 51));
//    this->setTextureRect(sf::IntRect(873, 697,57, 51));
//    this->setTextureRect(sf::IntRect(267, 296,57, 51));
//    this->setTextureRect(sf::IntRect(930, 697,57, 51));
    return true;
}
bool Enemy::fire2()
{
   return  weapon->fire2(plane_size,this);
}