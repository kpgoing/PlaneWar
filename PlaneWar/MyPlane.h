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
    MyPlane(std::string name = "shoot.png",sf::IntRect intrect = sf::IntRect(165, 360,102, 126)):Plane(name,intrect){
//        weapons->push_back(new Weapon(-1));
//        weapons->push_back(new Weapon(1));
//        weapons->push_back(new Weapon(-2));
//        weapons->push_back(new Weapon(2));
        this->setColor(sf::Color::Blue);
        lifenumber = 3;
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
    void buttlesmoving();
    int getlife()
    {
        return life;
    }
    void gownup()
    {
        grade++;
        switch (grade) {
            case 2:
                weapons->push_back(new Weapon(-1));
                weapons->push_back(new Weapon(1));
                break;
            case 3:
                weapons->push_back(new Weapon(-2));
                weapons->push_back(new Weapon(2));
                break;
            default:
                break;
        }
    }
    Backgroud* getowner();
//    virtual ~MyPlane();
//    sf::Vector2u getSize();
private:
    sf::Image image;
    sf::Texture  texture;
    sf::Vector2u image_size;
    Backgroud *pwindow;
    int grade = 1;
    int i = 0;
    int speed =1;
    int life = 3;
};
#endif /* defined(__PlaneWar__MyPlane__) */
