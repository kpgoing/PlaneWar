//
//  Weapon.cpp
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/20.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "Weapon.h"
//Weapon::Weapon(MyPlane *plane)
//{
//    myplane = plane;
//    myplane->getowner()->setbullets(&bullets);
//}
bool Weapon::fire(sf::Event event,sf::Vector2u plane_size, sf::Sprite*plane)
{
    
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::LAlt) {
        bullets.push_back(new Bullet());
        sf::Vector2f plane_position = plane->getPosition();
        (*(bullets.end()-1))->setPosition(plane_size.x/2+plane_position.x,plane_position.y-20);
        
        return true;
    }
    return false;
}
void Weapon::fly()
{
    for(auto &a:bullets)
    {
        a->move(direction, -5);
    }
}
void Weapon::fly2()
{
    for(auto &a:bullets)
    {
        a->move(direction, 1);
    }
}


bool Weapon::fire2(sf::Vector2u plane_size, sf::Sprite*plane)
{
    bullets.push_back(new Bullet());
    sf::Vector2f plane_position = plane->getPosition();
    (*(bullets.end()-1))->setPosition(plane_size.x/2+plane_position.x,plane_position.y+50);
    return true;
}