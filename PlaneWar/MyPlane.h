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
#include "Backgroud.h"
class MyPlane :public Plane
{
public:
    MyPlane(std::string name,sf::IntRect intrect):Plane(name,intrect){}
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
    bool downbool = false;
};
#endif /* defined(__PlaneWar__MyPlane__) */
