//
//  Weapon.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/20.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Weapon.h"
Weapon::Weapon(MyPlane *plane)
{
    myplane = plane;
    myplane->getowner()->setbullets(&bullets);
}
bool Weapon::fire(sf::Event event)
{
    
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::LAlt) {
        bullets.push_back(new Bullet());
    
//        myplane->getowner()->addsprite(bullets[i]);
        sf::Vector2u plane_size = myplane->getImage_size();
        sf::Vector2f plane_position = myplane->getPosition();
        (*(bullets.end()-1))->setPosition(plane_size.x/2+plane_position.x,plane_position.y-20);
        
        return true;
    }
    return false;
}
void Weapon::fly()
{
    for(auto &a:bullets)
    {
        a->move(0, -5);
    }
}