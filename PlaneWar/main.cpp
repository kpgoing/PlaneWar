
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//
#define SCREEN_WIDTH 480
#define SCREEN_HIGTH 800
// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include "MyPlane.h"
#include "Weapon.h"
#include "Army.h"
#include <iostream>
using  namespace std;
int main(int, char const**)
{
    Backgroud window;
    Army army;
    army.setowner(&window);
    sf::Vector2u screen_size(SCREEN_WIDTH,SCREEN_HIGTH);
    MyPlane myplane;
    Bullet bullet;
    sf::Clock clock1,clock2,clock3;
    sf::Time time1 ,time2,time3;
    myplane.setowner(&window);
    Weapon myweapon(&myplane);
    sf::Vector2u myplane_size = myplane.getImage_size();
    myplane.setPosition((screen_size.x-myplane_size.x)/2,screen_size.y-myplane_size.y);
    sf::Music music;
    window.addplane(&myplane);
    if (!music.openFromFile(resourcePath()+"game_music.ogg")) {
        return EXIT_FAILURE;
    }
    music.play();
        while (window.getwindow().isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.getwindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.getwindow().close();
        }
        myplane.moving(event);
//        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::LAlt) {
            time1 = clock1.getElapsedTime();
            if((double)time1.asSeconds()>0.1){
                myweapon.fire(event);
                clock1.restart();
        }
        time2 = clock2.getElapsedTime();
        if ((double)time2.asSeconds()>1) {
            army.add();
            clock2.restart();
        }
        myweapon.fly();
        army.moving();
        window.refresh();
        
    }
    return EXIT_SUCCESS;
}
