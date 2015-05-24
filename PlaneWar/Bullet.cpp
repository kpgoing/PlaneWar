//
//  Bullet.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/19.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Bullet.h"
Bullet::Bullet()
{
    if (!texture.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(1004, 987,9, 21))) {
        return EXIT_FAILURE;
    }
    this->setTexture(texture);
    this->setPosition(100, 100);
}
