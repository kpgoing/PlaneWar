//
//  Army.h
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/24.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef __PlaneWar__Army__
#define __PlaneWar__Army__
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Enemy.h"
#include "Backgroud.h"
class Army
{
public:
    void setowner(Backgroud*);
    void add();
    void moving();
    void down();
private:
    std::vector<Enemy*> enemys;
    Backgroud *background;
};
#endif /* defined(__PlaneWar__Army__) */
