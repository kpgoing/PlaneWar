//
//  Weapon.h
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/20.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef __PlaneWar__Weapon__
#define __PlaneWar__Weapon__
#include "MyPlane.h"
class Weapon
{
public:
    Weapon(MyPlane*);
    void fire(sf::Event);
    void fly();
private:
    MyPlane *myplane;
    std::vector<sf::Sprite*> bullets;
    int i = 0;
};
#endif /* defined(__PlaneWar__Weapon__) */
