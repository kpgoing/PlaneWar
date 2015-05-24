//
//  Backgroud.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/19.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Backgroud.h"       
#include <iostream>
using namespace std;
sf::RenderWindow Backgroud::window(sf::VideoMode(480,800),"plane");
Backgroud::Backgroud()
{
    if (!texture.loadFromFile(resourcePath()+"background.png")) {
        return EXIT_FAILURE;
    }
    sprite.setTexture(texture);
}
void Backgroud::addsprite(sf::Sprite *a)
{
    sprites.push_back(a);
}
sf::RenderWindow& Backgroud::getwindow()
{
    return window;
}
void Backgroud::addplane(sf::Sprite * pplane)
{
    plane =pplane;
}
void Backgroud::refresh()
{
    window.clear();
    for (auto i = sprites.begin(); i<sprites.end(); i++) {
        if ((*i)->getPosition().y<-5) {
            sprites.erase(i);
//            delete *i;

        }
    }
    window.draw(sprite);
    window.draw(*plane);
    
    for(auto &a:sprites)
    {
        window.draw(*a);
    }
    window.display();
}
