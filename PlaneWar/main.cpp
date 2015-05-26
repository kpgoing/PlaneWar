
#define SCREEN_WIDTH 480
#define SCREEN_HIGTH 800
#include "ResourcePath.hpp"
#include "Backgroud.h"
#include "Weapon.h"
#include "Army.h"
#include <iostream>
using  namespace std;
int main(int, char const**)
{
    Backgroud window;
    Army army;
    army.setowner(&window);
//    sf::Vector2u screen_size(SCREEN_WIDTH,SCREEN_HIGTH);
    sf::Clock clock1,clock2,clock3,clock4,clock5;
    sf::Time time1 ,time2,time3,time4,time5;
//    sf::Vector2u myplane_size = myplane.getsize();
//    myplane.setPosition((screen_size.x-myplane_size.x)/2,screen_size.y-myplane_size.y);
    
 
    sf::Music music;
    sf::Music music_bullet;
    sf::Music music_down;
    int jishu = 1;
    if (!music_down.openFromFile(resourcePath()+"enemy3_down.ogg")) {
        return EXIT_FAILURE;
    }

    if (!music_bullet.openFromFile(resourcePath()+"bullet.ogg")) {
        return EXIT_FAILURE;
    }
    if (!music.openFromFile(resourcePath()+"game_music.ogg")) {
        return EXIT_FAILURE;
    }
    music.play();
        while (window.getwindow().isOpen())
    {
        sf::Event event;
        while (window.getwindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.getwindow().close();
        }
        window.getmyplane().moving(event);
            time1 = clock1.getElapsedTime();
            if((double)time1.asSeconds()>0.1){
                if(window.getmyplane().fire(event))
                    music_bullet.play();
                clock1.restart();
        }
        time2 = clock2.getElapsedTime();
        if ((double)time2.asSeconds()>0.5) {
            army.add();
            army.fire();
            clock2.restart();
        }
//        time3 = clock3.getElapsedTime();
//        if ((double)time3.asSeconds()>0.5) {
//            window.touchenemy();
//            clock3.restart();
//        }
        window.getmyplane().buttlesmoving();
        army.moving();
        window.check();
        army.bulletfly();
        if(window.touchbullet())
        {
            music_down.play();
        }
        time5 = clock5.getElapsedTime();
        if(time5.asSeconds()>0.3&&jishu<5){
            army.down();
            jishu++;
            clock5.restart();
            
        }
        if (jishu==5) {
            jishu=1;
        }
        window.touchenemy();
        window.touch();
        window.touchhero();
        window.refresh();
        window.enemybulletstouch();
        time4 = clock4.getElapsedTime();
//        if ((double)time4.asSeconds()>0.5) {
//            window.isover();
//            clock4.restart();
//            
//        }
    }
    return EXIT_SUCCESS;
}
