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
//#include "Army.h"
class Backgroud
{
public:
     friend class MyPlane;
    Backgroud();
    void setmyplaneweapons(std::vector<Weapon*> *);
    void setenemys(std::vector<Enemy*> *);
    sf::RenderWindow& getwindow();
    void refresh();
    void addplane(sf::Sprite*);
    void check();
    void touch();
    void touchenemy();
    bool touchbullet();
    void touchhero();
    void usebomb(sf::Event);
    void enemybulletstouch();
    void addscore(int);
    void setfont();
    bool isover();
    void setenemyweapons(std::vector<Weapon*>*);
    void deblood();
    void change(int);
    void baomu(int i)
    {
        switch (i) {
            case 2:
                zm = "second";
                break;
            case 3:
                zm = "third";
                break;
            case 4:
                zm = "forth";
                break;
            default:
                break;
        }
        zimu = new sf::Text(zm,font,70);
        zimu->setPosition(100, 300);
        sf::Clock clock;
        sf::Time time;
        time = clock.getElapsedTime();
        while (time.asSeconds()<2) {
            window.clear();
            window.draw(*zimu);
            window.display();
            time = clock.getElapsedTime();
        }
    }
    void clearscreen()
    {
        enemys->clear();
        enemyweapons->clear();
    }
    MyPlane& getmyplane()
    {
        return *plane;
    }
    void changebombnum(int);
    void again()
    {
//        delete  plane;
        str = "SCORE  0";
        plane = new MyPlane();
        sumscore = 0;
        plane->setowner(this);
        lifestr = "OOO";
//        score->setString(str);
        text->setString(str);
        change(1);
        life->setString(lifestr);
        setmyplaneweapons(plane->getweapon());
        clearscreen();
//        plane.setdownbegin(false);
//        plane.setdownover(false);
//        plane->setlife(3);
//        deblood();
//        plane.setTextureRect(sf::IntRect(165, 360,102, 126));
        plane->setPosition((screen_size.x-myplane_size.x)/2,screen_size.y-myplane_size.y);
//        refresh();
    }
    static sf::RenderWindow window;
private:
//    Army *army;
    sf::Texture texture;
    sf::Sprite sprite;
    MyPlane *plane;
    std::string str = "SCORE  0";
    sf::Text *text;
    sf::Font font;
    sf::Text *life;
    sf::Text *score;
    sf::Text *zimu;
    sf::Text *bomb;
    std::string bombstr = "BBB";
    std::string zm = "sceond guan";
    std::string lifestr = "OOO";
    sf::Vector2u myplane_size;
    int sumscore = 0;
    int bombnum = 3;
    std::vector<Weapon*> *myplaneweapons;
    std::vector<Enemy*> *enemys;
    std::vector<Weapon*> *enemyweapons;
    sf::Vector2u screen_size =sf::Vector2u(SCREEN_WIDTH,SCREEN_HIGTH);
};
#endif /* defined(__PlaneWar__Backgroud__) */
