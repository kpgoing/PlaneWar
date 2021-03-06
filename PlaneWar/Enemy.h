//
//  Enemy.h
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/24.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef __PlaneWar__Enemy__
#define __PlaneWar__Enemy__
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Plane.h"
class Enemy:public Plane
{
public:
    Enemy(std::string name = "shoot.png",sf::IntRect intrect = sf::IntRect(534, 612, 57, 43)):Plane(name,intrect){
        std::uniform_int_distribution<unsigned> u(0,400);
        std::default_random_engine e(time(0));
        this->setPosition(u(e), -200);}
    virtual bool down();
    virtual bool fire2();
    void changetobomb()
    {
        isbomb = true;
        this->setTextureRect(sf::IntRect(267, 398, 58, 88));
    }
    bool ischangetobmob()
    {
        return isbomb;
    }
    void setbomb()
    {
        isbomb = true;
    }
    void changetobomb2()
    {
        isbomb2 = true;
        this->setTextureRect(sf::IntRect(102, 118, 60, 107));
    }
    bool ischangetobmob2()
    {
        return isbomb2;
    }
    void setbomb2()
    {
        isbomb2 = true;
    }

//    virtual void setimage();
    
private:
    sf::Texture texture;
    sf::Image image;
    sf::Clock clock;
    sf::Time sftime;
    bool isbomb = false;
    bool isbomb2 = false;
//protected:
//    int downstate = 1;
//    bool downbool = false;
};
#endif /* defined(__PlaneWar__Enemy__) */
