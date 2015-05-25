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
};
sf::RenderWindow& Backgroud::getwindow()
{
    return window;
}
void Backgroud::addplane(sf::Sprite * pplane)
{
    plane =pplane;
}
void Backgroud::setbullets(std::vector<Bullet*> *p)
{
    bullets = p;
}
void Backgroud::setenemys(std::vector<Enemy*> *p)
{
    enemys = p;
}
void Backgroud::refresh()
{
    window.clear();
   
    window.draw(sprite);
    window.draw(*plane);
    
    for(auto &a:(*bullets))
    {
        window.draw(*a);
    }
    for(auto &a:(*enemys))
    {
        window.draw(*a);
    }
    window.display();
}
void Backgroud::check()
{
    for (auto i =( bullets->begin()); i<(bullets->end()); i++) {
        if ((*i)->getPosition().y<-5) {
            delete *i;
            bullets->erase(i);
            
        }
    }
    
    for (auto i = (enemys->begin()); i<
         (enemys->end()); i++) {
        if ((*i)->getPosition().y>800) {
            delete *i;
            enemys->erase(i);
            
        }
    }
}
void Backgroud::touch()
{
    
    for(auto &a:(*bullets))
    {
        for (auto i = enemys->begin(); i<enemys->end(); i++) {
            if (a->getGlobalBounds().intersects((*i)->getGlobalBounds())) {
                (*i)->down();
            a->setuse(true);
            }
        }
    }
}
void Backgroud::touchhero()
{
    for (auto i = enemys->begin(); i<enemys->end(); i++) {
        if (plane->getGlobalBounds().intersects((*i)->getGlobalBounds())) {
            (*i)->down();
        }
}
}
void Backgroud::touchenemy(){
    for (auto i = enemys->begin(); i<enemys->end(); i++) {
        if ((*i)->isdown()) {
            delete *i;
            enemys->erase(i);
        }
    }
 
}
bool Backgroud::touchbullet()
{
    bool panduan = false;
    for (auto i = bullets->begin(); i<bullets->end(); i++) {
        if ((*i)->getuse()) {
            delete *i;
            bullets->erase(i);
            panduan = true;
        }
    }
    return panduan;
}
