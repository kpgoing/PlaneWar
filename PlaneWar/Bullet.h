//
//  Bullet.h
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/19.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef __PlaneWar__Bullet__
#define __PlaneWar__Bullet__
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Bullet: public sf::Sprite
{
public:
    Bullet();
    static sf::Image image;
//    static void load();
    void setuse(bool);
    bool getuse();
    void check();
private:
    sf::Texture  texture;
    bool use = false;
    
};
#endif /* defined(__PlaneWar__Bullet__) */
