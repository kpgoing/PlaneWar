//
//  Enemy1.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/24.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Enemy1.h"
#include <random>

bool Enemy1::down()
{
    this->setTextureRect(sf::IntRect( 534, 655,69, 95));
    this->setTextureRect(sf::IntRect( 603, 655, 69, 95));
    this->setTextureRect(sf::IntRect(  672, 653,69, 95));
    this->setTextureRect(sf::IntRect( 741, 653,69, 95));

    downbool = true;
    return true;
}

//void Enemy1::setimage()
//{
//    texture.loadFromImage(image,sf::IntRect(534, 612,57, 43));
//}