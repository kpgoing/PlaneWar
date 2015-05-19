//
//  Backgroud.h
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/19.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef __PlaneWar__Backgroud__
#define __PlaneWar__Backgroud__
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "ResourcePath.hpp"
class Backgroud
{
public:
    Backgroud();
    friend class MyPlane;
    void draw2(sf::Sprite&);
    sf::RenderWindow& getwindow();
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RenderWindow window(sf::VideoMode(480,800),"plane");
    std::vector<sf::Sprite&> sprites;
};
#endif /* defined(__PlaneWar__Backgroud__) */
