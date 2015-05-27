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
#include "Plane.h"
class Backgroud;
class MyPlane :public Plane
{
public:
    MyPlane(std::string name = "shoot.png",sf::IntRect intrect = sf::IntRect(0, 99, 102, 126)):Plane(name,intrect){
//        weaponleft = new Weapon(-1);
//        weaponright  = new Weapon(1);
    }
    bool fire(sf::Event);
    bool checkleft();
    bool checkright();
    bool checkup();
    bool checkdown();
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    void moving(sf::Event);
    void setowner(Backgroud *);
    virtual bool down();
    void ishurt();
    virtual void buttlesmoving();

    Backgroud* getowner();
//    sf::Vector2u getSize();
private:
    sf::Image image;
    sf::Texture  texture;
    sf::Vector2u image_size;
    Backgroud *pwindow;
//    Weapon *weaponleft;
//    Weapon *weaponright;
    int i = 0;
    int speed =1;
    int life = 3;
};
#endif /* defined(__PlaneWar__MyPlane__) */
