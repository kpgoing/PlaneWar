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
    enemys.push_back(new Enemy());
    background->addsprite(*(enemys.end()-1));
}
void Army::setowner(Backgroud * pbackground)
{
    background = pbackground;
}
void Army::moving()
{
    for(auto& a:enemys)
    {
        a->move(0, 1);
    }
}
//void Army::down()
//{
//    for(auto& a:enemys)
//    {
//        a->down();
//    }
//}