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
        enemyweapons.push_back(((*(enemys.end()-1)))->getweapon());
        i++;
        return;
    }
    while (i%5==0) {
        enemys.push_back(new Enemy2());
        enemyweapons.push_back(((*(enemys.end()-1)))->getweapon());
        i++;
        return;
    }
    enemys.push_back(new Enemy());
     enemyweapons.push_back(((*(enemys.end()-1)))->getweapon());
    i++;
}

void Army::setowner(Backgroud * pbackground)
{
    background = pbackground;
    pbackground->setenemys(&enemys);
    pbackground->setenemyweapons(&enemyweapons);
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
            std::cout<<"Aaa"<<std::endl;
            a->down();
        }
    }

}