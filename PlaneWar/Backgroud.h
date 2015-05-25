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
#include "Enemy1.h"
#include "Enemy2.h"
#include "Bullet.h"
class Backgroud
{
public:
     friend class MyPlane;
    Backgroud();
    void setbullets(std::vector<Bullet*> *);
    void setenemys(std::vector<Enemy*> *);
    sf::RenderWindow& getwindow();
    void refresh();
    void addplane(sf::Sprite*);
    void check();
    void touch();
    void touchenemy();
    bool touchbullet();
    void touchhero();
    void addscore(int);
    void setfont();
    static sf::RenderWindow window;
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite *plane;
    sf::String str = "SCORE:";
    sf::Text *text;
    sf::Font font;
    int sumscore = 0;
    std::vector<Bullet*> *bullets;
    std::vector<Enemy*> *enemys;
};
#endif /* defined(__PlaneWar__Backgroud__) */
