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
//    void setbullets(std::vector<sf::Sprite*> *);
    friend class MyPlane;
//    void draw(sf::Sprite);
    sf::RenderWindow& getwindow();
//    void showbackground();
    void addsprite(sf::Sprite*);
    void refresh();
    void addplane(sf::Sprite*);
    static sf::RenderWindow window;
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite *plane;
//    std::vector<sf::Sprite*> *bullets;
//    std::vector<sf::Sprite*> *enemys;
    std::vector<sf::Sprite*> sprites;
};
#endif /* defined(__PlaneWar__Backgroud__) */
