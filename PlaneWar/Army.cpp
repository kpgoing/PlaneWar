//
//  Army.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/24.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Army.h"
void Army::add()
{
    while (i%4==0) {
        enemys.push_back(new Enemy1());
//        ((Enemy1*)(*(enemys.end()-1)))->setimage();
        i++;
        return;
    }
    while (i%5==0) {
        enemys.push_back(new Enemy2());
//        ((Enemy2*)(*(enemys.end()-1)))->setimage();
        i++;
        return;
    }
    enemys.push_back(new Enemy());
    i++;
}

void Army::setowner(Backgroud * pbackground)
{
    background = pbackground;
    pbackground->setenemys(&enemys);
}
void Army::moving()
{
    for(auto& a:enemys)
    {
        a->move(0, 1);
    }
}
//void Army::fire()
//{
//    for(auto&a:enemys)
//    {
//        a->useweapon()->fire();
//    }
//}