//
//  Plane.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/25.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Plane.h"
Plane::Plane(std::string name,sf::IntRect intrect)
{
    if (!image.loadFromFile(resourcePath()+"shoot.png")) {
        return EXIT_FAILURE;
    }
    texture.loadFromImage(image);
    this->setTexture(texture);
    this->setTextureRect(intrect);
    plane_size = sf::Vector2u(intrect.width,intrect.height);
    weapon = new Weapon();
    downbegin = false;
    downover = false;
}
bool Plane::fire(sf::Event event)
{
    return  weapon->fire(event,plane_size,this);
}
sf::Vector2u Plane::getsize()
{
    return plane_size;
}
void Plane::buttlesmoving()
{
    weapon->fly();
}
bool Plane::isdown()
{
    return downbegin;
}
