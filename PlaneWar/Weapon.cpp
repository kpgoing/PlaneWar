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
}
void Weapon::fire(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::LAlt) {
        bullets.push_back(new Bullet());
        myplane->getowner()->addsprite(bullets[i]);
        sf::Vector2u plane_size = myplane->getImage_size();
        sf::Vector2f plane_position = myplane->getPosition();
        bullets[i]->setPosition(plane_size.x/2+plane_position.x,plane_position.y-20);
        i++;
    }
}
void Weapon::fly()
{
//    for (auto a = bullets.begin(); a<bullets.end(); a++) {
//        if ((*a)->getPosition().y<0) {
//            (*a)->~Sprite();
//            delete *a;
//        }
//    }
    for(auto &a:bullets)
    {
        a->move(0, -5);
    }
}