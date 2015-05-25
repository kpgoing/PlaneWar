//
//  Enemy2.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/24.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Enemy2.h"
#include <random>
Enemy2::Enemy2()
{
    if (!image.loadFromFile(resourcePath()+"shoot.png")) {
        return EXIT_FAILURE;
    }
    texture.loadFromImage(image,sf::IntRect(504, 750, 169, 258));
    this->setTexture(texture);
    std::uniform_int_distribution<unsigned> u(100,200);
    std::default_random_engine e(time(0));
    this->setPosition(u(e), -100);
}
bool Enemy2::down()
{
    texture.loadFromImage(image,sf::IntRect(0, 747,166, 261));
//    texture.loadFromImage(image,sf::IntRect( 873, 697,57, 51));
//    texture.loadFromImage(image,sf::IntRect(267, 296,57, 51));
//    texture.loadFromImage(image,sf::IntRect(930, 697,57, 51));
    downbool = true;
    return true;
}
bool Enemy2::isdown()
{
    return downbool;
}
void Enemy2::setimage()
{
    texture.loadFromImage(image,sf::IntRect(504, 750, 169, 258));

}