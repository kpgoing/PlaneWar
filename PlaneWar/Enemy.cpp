//
//  Enemy.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/24.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//


#include "Enemy.h"
#include <random>
Enemy::Enemy(){
    if (!image.loadFromFile(resourcePath()+"shoot.png")) {
        return EXIT_FAILURE;
    }
    texture.loadFromImage(image,sf::IntRect(0, 0,69, 99));
    this->setTexture(texture);
    std::uniform_int_distribution<unsigned> u(0,400);
    std::default_random_engine e(time(0));
    this->setPosition(u(e), -100);
    downbool = false;
}
bool Enemy::down()
{
    texture.loadFromImage(image,sf::IntRect( 534, 655,69, 95));
    texture.loadFromImage(image,sf::IntRect( 603, 655, 69, 95));
    texture.loadFromImage(image,sf::IntRect(  672, 653,69, 95));
    texture.loadFromImage(image,sf::IntRect( 741, 653,69, 95));
 
    downbool = true;
    return true;
}
bool Enemy::isdown()
{
    return downbool;
}
void Enemy::setimage()
{
     texture.loadFromImage(image,sf::IntRect(0, 0,69, 99));
}