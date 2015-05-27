//
//  Backgroud.h
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/19.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef __PlaneWar__Backgroud__
#define __PlaneWar__Backgroud__
#define SCREEN_WIDTH 480
#define SCREEN_HIGTH 800
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "ResourcePath.hpp"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Myplane.h"
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
    void enemybulletstouch();
    void addscore(int);
    void setfont();
    void isover();
    void setenemyweapons(std::vector<Weapon*>*);
    void deblood();
    MyPlane& getmyplane()
    {
        return plane;
    }
    static sf::RenderWindow window;
private:
    sf::Texture texture;
    sf::Sprite sprite;
    MyPlane plane;
    sf::String str = "SCORE:";
    sf::Text *text;
    sf::Font font;
    sf::Text *life;
    sf::String lifestr = "OOO";
    int sumscore = 0;
    std::vector<Bullet*> *bullets;
    std::vector<Enemy*> *enemys;
    std::vector<Weapon*> *enemyweapons;
    sf::Vector2u screen_size =sf::Vector2u(SCREEN_WIDTH,SCREEN_HIGTH);
};
#endif /* defined(__PlaneWar__Backgroud__) */
