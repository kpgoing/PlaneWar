//
//  Backgroud.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/19.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Backgroud.h"
Backgroud::Backgroud()
{
    if (!texture.loadFromFile(resourcePath()+"background.png")) {
        return EXIT_FAILURE;
    }
    sprite.setTexture(texture);
}
void Backgroud::draw2(sf::Sprite &psprite)
{
    sprites.push_back(psprite);
    window.draw(psprite);
}
sf::RenderWindow& Backgroud::getwindow()
{
    return window;
}