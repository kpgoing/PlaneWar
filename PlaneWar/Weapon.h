//
//  Weapon.h
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/20.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef __PlaneWar__Weapon__
#define __PlaneWar__Weapon__
#include "Bullet.h"
class Weapon
{
public:
    friend class  Plane;
    Weapon(int i):direction(i){}
    bool fire(sf::Event,sf::Vector2u,sf::Sprite*);
    bool fire2(sf::Vector2u plane_size, sf::Sprite*plane);
    void fly();
    void fly2();

     std::vector<Bullet*> bullets;
private:
//    MyPlane *myplane;
    int i = 0;
    int direction = 0;
};
#endif /* defined(__PlaneWar__Weapon__) */
