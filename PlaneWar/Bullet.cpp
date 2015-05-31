//
//  Bullet.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/19.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Bullet.h"
//void Bullet::load()
//{
//    image.loadFromFile(resourcePath()+"shoot.png");
//}
Bullet::Bullet()
{
    if (!texture.loadFromImage(image)) {
        return EXIT_FAILURE;
    }
    this->setTexture(texture);
    this->setTextureRect(sf::IntRect(1004, 987,9, 21));
}
void Bullet::setuse(bool b)
{
    use = b;
}
bool Bullet::getuse()
{
    return use;
}