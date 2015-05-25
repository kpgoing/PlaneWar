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
class Enemy:public sf::Sprite
{
public:
    Enemy();
    virtual bool down();
    virtual bool isdown();
    virtual void setimage();
    
private:
    sf::Texture texture;
    sf::Image image;
    bool downbool = false;
};
#endif /* defined(__PlaneWar__Enemy__) */
