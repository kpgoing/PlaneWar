//
//  Enemy1.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/24.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Enemy1.h"
#include <random>
Enemy1::Enemy1()
{
    if (!image.loadFromFile(resourcePath()+"shoot.png")) {
        return EXIT_FAILURE;
    }
    texture.loadFromImage(image,sf::IntRect(534, 612,57, 43));
    this->setTexture(texture);
    std::uniform_int_distribution<unsigned> u(0,400);
    std::default_random_engine e(time(0));
    this->setPosition(u(e), -100);
}
bool Enemy1::down()
{
    texture.loadFromImage(image,sf::IntRect( 267, 347, 57, 51));
    texture.loadFromImage(image,sf::IntRect( 873, 697,57, 51));
    texture.loadFromImage(image,sf::IntRect(267, 296,57, 51));
    texture.loadFromImage(image,sf::IntRect(930, 697,57, 51));
    downbool = true;
    return true;
}
bool Enemy1::isdown()
{
    return downbool;
}
void Enemy1::setimage()
{
    texture.loadFromImage(image,sf::IntRect(534, 612,57, 43));
}