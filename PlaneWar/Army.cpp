//
//  Army.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/24.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Army.h"
#include <iostream>
void Army::add()
{
    while (i%4==0) {
        enemys.push_back(new Enemy1());
        (*(enemys.end()-1))->setColor(sf::Color::Magenta);
//        (*(enemys.end()-1))->setbomb();
        for(auto&a:*((*(enemys.end()-1))->getweapon()))
        {
            enemyweapons.push_back(a);
        
        }
        i++;
        return;
    }
    while (i%5==0) {
        enemys.push_back(new Enemy2());
        (*(enemys.end()-1))->setColor(sf::Color::Green);
//        (*(enemys.end()-1))->setbomb();
        for(auto&a:*((*(enemys.end()-1))->getweapon()))
        {
            enemyweapons.push_back(a);
        }
        i++;
        return;
    }
    enemys.push_back(new Enemy());
    (*(enemys.end()-1))->setColor(sf::Color::Yellow);
//    (*(enemys.end()-1))->setbomb();
    for(auto&a:*((*(enemys.end()-1))->getweapon())){
        enemyweapons.push_back(a);
    }
    i++;
}

void Army::setowner(Backgroud * pbackground)
{
    background = pbackground;
    background->setenemys(&enemys);
    background->setenemyweapons(&enemyweapons);
}
void Army::moving()
{
    for(auto& a:enemys)
    {
        a->move(0, 0.5);
    }
}
bool Army::fire()
{
    for(auto&a:enemys)
    {
        if(!(a->ischangetobmob()))
        a->fire2();
    }
    return true;
}
bool Army::bulletfly()
{
    for(auto&a:enemyweapons)
    {
        a->fly2();
    }
    
    return true;
}
void Army::down()
{
    for(auto&a:enemys)
    {
        if (a->isdown()) {
            a->down();
        }
    }

}