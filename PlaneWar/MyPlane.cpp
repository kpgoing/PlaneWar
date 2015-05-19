//
//  MyPlane.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/19.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "MyPlane.h"
MyPlane::MyPlane()
{
    if (!image.loadFromFile(resourcePath() +"主飞机.png"))
    {
        return EXIT_FAILURE;
    }
    if (!texture.loadFromImage(image)) {
        return EXIT_FAILURE;
    }
    this->setTexture(texture);
    image_size = image.getSize();
}
void MyPlane::setwindow(Backgroud *opwindow)
{
    pwindow = opwindow;
}
sf::Vector2u MyPlane::getImage_size()
{
    return image_size;
}
bool MyPlane::checkleft()
{
    sf::Vector2f position = getPosition();
    if (position.x == 0) {
        return false;
    }else
    {
        return true;
    }
}
bool MyPlane::checkright()
{
    sf::Vector2f position =getPosition();
    if (position.x == 480-image_size.x) {
        return false;
    }else
    {
        return true;
    }
}
bool MyPlane::checkup()
{
    sf::Vector2f position = getPosition();
    if (position.y == 0) {
        return false;
    }else
    {
        return true;
    }
}
bool MyPlane::checkdown()
{
    sf::Vector2f position = getPosition();
    if (position.y == 800-image_size.y) {
        return false;
    }else
    {
        return true;
    }
}
void MyPlane::fire()
{
    static Bullet bullet;
    bullet.setPosition(image_size.x/2+getPosition().x,image_size.y);
    pwindow->draw2(bullet);
}