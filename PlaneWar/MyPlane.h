//
//  MyPlane.h
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/19.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef __PlaneWar__MyPlane__
#define __PlaneWar__MyPlane__
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Bullet.h"
#include "Backgroud.h"
class MyPlane :public sf::Sprite
{
public:
    MyPlane();
    sf::Vector2u getImage_size();
    bool checkleft();
    bool checkright();
    bool checkup();
    bool checkdown();
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    void moving(sf::Event);
//    void setweapon(Weapon*);
//    Weapon* useweapon();
    //    void fire();
    void setowner(Backgroud *);
    Backgroud* getowner();
//    sf::Vector2u getSize();
private:
    sf::Image image;
    sf::Texture  texture;
    sf::Vector2u image_size;
    std::vector<sf::Sprite*> bullets;
    Backgroud *pwindow;
    int i = 0;
    int speed =1;
//    Weapon *weapon;
};
#endif /* defined(__PlaneWar__MyPlane__) */
