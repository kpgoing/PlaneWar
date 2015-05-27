
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

    sf::Clock clock1,clock2,clock3,clock4,clock5;
    sf::Time time1 ,time2,time3,time4,time5;

    sf::Music music;
    sf::Music music_bullet;
    sf::Music music_down;
    sf::Music game_over;
    if (!game_over.openFromFile(resourcePath()+"game_over.ogg")) {
        return EXIT_FAILURE;
    }
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
                if(window.getmyplane().fire(event)){
                    music_bullet.play();
                }
                clock1.restart();
        }
        time2 = clock2.getElapsedTime();
        if ((double)time2.asSeconds()>1) {
            army.add();
            army.fire();
            clock2.restart();
        }
        time3 = clock3.getElapsedTime();
        if ((double)time3.asSeconds()>0.2&&window.getmyplane().isdown()) {
            window.getmyplane().down();
            clock3.restart();
        }
        window.getmyplane().buttlesmoving();
        army.moving();
        window.check();
        army.bulletfly();
        if(window.touchbullet())
        {
            music_down.play();
        }
        time5 = clock5.getElapsedTime();
        if(time5.asSeconds()>0.1){
            army.down();
            clock5.restart();
        }
        if (window.getmyplane().isdown()) {
            game_over.play();
            music.stop();
        }
        window.touchenemy();
        window.touch();
        window.touchhero();
        window.refresh();
        window.enemybulletstouch();
        window.isover();
    }
    return EXIT_SUCCESS;
}
