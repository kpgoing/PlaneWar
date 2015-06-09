//
//  Plane.h
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/25.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef __PlaneWar__Plane__
#define __PlaneWar__Plane__
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Weapon.h"
#include <string>
#include <random>
class Plane:public sf::Sprite
{
public:
    Plane(std::string,sf::IntRect);
    bool fire(sf::Event);
    void buttlesmoving();
    sf::Vector2u getsize();
    virtual bool down(){
        downbool  = true;
        return true;}
    bool isdown();
    Weapon* getweapon()
    {
        return weapon;
    }
private:
    
    sf::Vector2f plane_position;
    sf::Image image;
    sf::Texture  texture;
protected:
    sf::Vector2u plane_size;
      Weapon *weapon;
      bool downbool;
};
#endif /* defined(__PlaneWar__Plane__) */
