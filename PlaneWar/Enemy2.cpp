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
    switch (downstate) {
        case 1:this->setTextureRect(sf::IntRect(0, 486,165, 261));
            downstate++;
            break;
        case 2:this->setTextureRect(sf::IntRect(0, 225,165, 261));
            downstate++;
            break;
        case 3:this->setTextureRect(sf::IntRect(839, 748,165, 260));
            downstate++;
            break;
        case 4: this->setTextureRect(sf::IntRect(165, 486,165, 261));
            downstate++;
            downover = true;
            break;
        default:
            break;
    }
//    this->setTextureRect(sf::IntRect(0, 486,165, 261));
//    this->setTextureRect(sf::IntRect(0, 225,165, 261));
//    this->setTextureRect(sf::IntRect(839, 748,165, 260));
//    this->setTextureRect(sf::IntRect(165, 486,165, 261));


    downbegin = true;
    return true;
}
//
//void Enemy2::setimage()
//{
//    texture.loadFromImage(image,sf::IntRect(504, 750, 169, 258));
//
//}