//
//  Backgroud.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/19.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Backgroud.h"       
#include <iostream>
#include <string>
using namespace std;
sf::RenderWindow Backgroud::window(sf::VideoMode(480,800),"plane");
Backgroud::Backgroud()
{
    if (!texture.loadFromFile(resourcePath()+"background.png")) {
        return EXIT_FAILURE;
    }
    sprite.setTexture(texture);
    if (!font.loadFromFile(resourcePath() + "Promses Broken Dream1.ttf")) {
        return EXIT_FAILURE;
    }
    text = new sf::Text(str, font, 30);
    text->setPosition(0,10);
    plane.setowner(this);
    sf::Vector2u myplane_size = plane.getsize();
    plane.setPosition((screen_size.x-myplane_size.x)/2,screen_size.y-myplane_size.y);
    setbullets(&(plane.getweapon()->bullets));
    life = new sf::Text(lifestr,font,30);
    life->setPosition(400, 10);
    life->setColor(sf::Color::Red);
}
sf::RenderWindow& Backgroud::getwindow()
{
    return window;
}
void Backgroud::setbullets(std::vector<Bullet*> *p)
{
    bullets = p;
}
void Backgroud::setenemys(std::vector<Enemy*> *p)
{
    enemys = p;
}
void Backgroud::setenemyweapons(std::vector<Weapon*> *p)
{
    enemyweapons = p;
}
void Backgroud::addscore(int score)
{
    sumscore +=score;
    str ="SCORE:"+ std::to_string(sumscore);
    text->setString(str);
    
}

void Backgroud::refresh()
{
    window.clear();
   
    window.draw(sprite);
    window.draw(plane);
    for(auto &a:(*bullets))
    {
        window.draw(*a);
    }
    for(auto &a:(*enemys))
    {
        window.draw(*a);
//        for(auto &b:(((a)->getweapon())->bullets))
//        {
//            window.draw(*b);
//        }
    }
    for(auto &a:*enemyweapons)
    {
        for(auto&b:a->bullets)
        {
            window.draw(*b);
        }
    }
    
    window.draw(*text);
    window.draw(*life);
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
    
    for (auto i = (enemys->begin()); i<(enemys->end()); i++) {
        if ((*i)->getPosition().y>800) {
            delete *i;
            enemys->erase(i);
            
        }
    }
    for(auto &a:(*enemyweapons))
    {
        for(auto i = (a->bullets).begin();i<(a->bullets).end();i++)
        {
            if ((*i)->getPosition().y>800) {
                delete *i;
                a->bullets.erase(i);
                
            }
        }
    }

}
void Backgroud::touch()
{
    
    for(auto &a:(*bullets))
    {
        for (auto i = enemys->begin(); i<enemys->end(); i++) {
            if ((!(*i)->isdown())&&a->getGlobalBounds().intersects((*i)->getGlobalBounds())) {
                (*i)->setdownbegin(true);
                addscore(10);
               a->setuse(true);
            }
        }
    }
}
void Backgroud::touchhero()
{
    for (auto i = enemys->begin(); i<enemys->end(); i++) {
        if ((!(*i)->isdown())&&plane.getGlobalBounds().intersects((*i)->getGlobalBounds())) {
            (*i)->setdownbegin(true);
            plane.setdownbegin(true);
            
        }
}
}
void Backgroud::touchenemy(){
    for (auto i = enemys->begin(); i<enemys->end(); i++) {
        if ((*i)->isdownover()) {
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
void Backgroud::enemybulletstouch()
{
    for(auto &a:(*enemyweapons))
    {
        for(auto i =((a->bullets).begin());i<((a->bullets).end());i++)
        {
            if ((*i)->getGlobalBounds().intersects(plane.getGlobalBounds())) {
                delete *i;
                (a->bullets).erase(i);
                plane.ishurt();
                deblood();
            }
        }
    }

}
void Backgroud::isover()
{
    if (plane.isdownover()) {
        sf::Text over("game over",font,60);

        window.clear() ;
        window.draw(over);
        window.display();

        while (true) {
            ;
        }
    }
}
void Backgroud::deblood()
{
    static int lifeint = 3;
    lifeint--;
    switch (lifeint) {
        case 2:
            lifestr = "OO";
            break;
        case 1:
            lifestr = "O";
            break;
        case 0:
            lifestr = "";
        default:
            break;
    }
    life->setString(lifestr);
}
