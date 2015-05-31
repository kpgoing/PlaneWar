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
    plane = new MyPlane();
    plane->setowner(this);
    myplane_size = plane->getsize();
    plane->setPosition((screen_size.x-myplane_size.x)/2,screen_size.y-myplane_size.y);
    setmyplaneweapons(plane->getweapon());
    life = new sf::Text(lifestr,font,30);
    life->setPosition(400, 10);
    life->setColor(sf::Color::Red);
}
sf::RenderWindow& Backgroud::getwindow()
{
    return window;
}
void Backgroud::setmyplaneweapons(std::vector<Weapon *> *p)
{
    myplaneweapons= p;
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
    str ="SCORE  "+ std::to_string(sumscore);
    text->setString(str);
    
}

void Backgroud::refresh()
{
    window.clear();
   
    window.draw(sprite);
    window.draw(*plane);
    for(auto &a:(*myplaneweapons))
    {
        for(auto&b:a->bullets)
        {
            window.draw(*b);
        }
    }
    for(auto &a:(*enemys))
    {
        window.draw(*a);
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
    for(auto &a:(*myplaneweapons))
    {
    for (auto i =( a->bullets.begin()); i<(a->bullets.end()); i++) {
        if ((*i)->getPosition().y<-5) {
            delete *i;
            a->bullets.erase(i);
            
        }
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
    for(auto &a:(*myplaneweapons))
    {
    for(auto &b:a->bullets)
    {
        for (auto i = enemys->begin(); i<enemys->end(); i++) {
            if ((!(*i)->isdown())&&b->getGlobalBounds().intersects((*i)->getGlobalBounds())) {
                std::uniform_int_distribution<unsigned> u(0,20);
                std::default_random_engine e(time(0));
                if (u(e)>15) {
                    (*i)->changetobomb();
                }else
                (*i)->setdownbegin(true);
                addscore(10);
               b->setuse(true);
            }
        }
    }
    }
}
void Backgroud::touchhero()
{
    for (auto i = enemys->begin(); i<enemys->end(); i++) {
        if ((!(*i)->isdown())&&plane->getGlobalBounds().intersects((*i)->getGlobalBounds())) {
            if ((*i)->ischangetobmob()) {
                plane->gownup();
                (*i)->setdownover(true);
            }else
            {
            (*i)->setdownbegin(true);
            plane->setdownbegin(true);
            }
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
    for(auto &a:(*myplaneweapons))
    {
    for (auto i = a->bullets.begin(); i<a->bullets.end(); i++) {
        if ((*i)->getuse()) {
            delete *i;
            a->bullets.erase(i);
            panduan = true;
        }
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
            if ((*i)->getGlobalBounds().intersects(plane->getGlobalBounds())) {
                delete *i;
                (a->bullets).erase(i);
                plane->ishurt();
                if(plane->getlife()>=0)
                deblood();
            }
        }
    }

}
bool Backgroud::isover()
{
    if (plane->isdownover()) {
        int i = 0;
        bool panduan = true;
        sf::Text over("game over",font,60);
        over.setColor(sf::Color::Red);
        over.setPosition(50,200);
        window.clear();
        score = new sf::Text(str,font, 40);
        score->setPosition(110, 300);
        sf::Text tryagain("try again",font,20);
        sf::Text exitbutton("close",font,20);
        tryagain.setPosition(50, 500);
        exitbutton.setPosition(300, 500);
        window.draw(tryagain);
        window.draw(exitbutton);
        window.draw(*score);
        window.draw(over);
        window.display();
        sf::Event event;
        while (panduan) {
        
        while (window.pollEvent(event)) {
        
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
             {
                 tryagain.setCharacterSize(40);
                 exitbutton.setCharacterSize(20);
                 i = 1;
             }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
            {
                tryagain.setCharacterSize(20);
                exitbutton.setCharacterSize(40);
                i = 0;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
            {
                if (i==1) {
                    again();
                    return true;
                }else
                {
                    exit(0);
                }
                }
            window.clear();
            window.draw(tryagain);
            window.draw(exitbutton);
            window.draw(*score);
            window.draw(over);
            window.display();

        }
        

    
        }
    
    }
    return false;
}
void Backgroud::deblood()
{
//    plane->delife();
    lifestr = "";
    lifestr.append("OOO",plane->getlife());

    life->setString(lifestr);
}
void Backgroud::change(int i)
{
    for(auto &a:*enemyweapons)
        {
            a->setspeed(i);
        }
}
