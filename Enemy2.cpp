//
//  Enemy2.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/24.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Enemy2.h"
#include <random>

bool Enemy2::down()
{
    this->setTextureRect(sf::IntRect(0, 747,166, 261));
//    texture.loadFromImage(image,sf::IntRect( 873, 697,57, 51));
//    texture.loadFromImage(image,sf::IntRect(267, 296,57, 51));
//    texture.loadFromImage(image,sf::IntRect(930, 697,57, 51));
    downbool = true;
    return true;
}
//
//void Enemy2::setimage()
//{
//    texture.loadFromImage(image,sf::IntRect(504, 750, 169, 258));
//
//}