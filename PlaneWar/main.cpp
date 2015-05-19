
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
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#define SCREEN_WIDTH 480
#define SCREEN_HIGTH 800
// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include "MyPlane.h"
int main(int, char const**)
{
    Backgroud window;
    sf::Vector2u screen_size(SCREEN_WIDTH,SCREEN_HIGTH);
    MyPlane myplane;
    Bullet bullet;
    sf::Time a;
    myplane.setwindow(&window);
    sf::Texture backgoround;
    if (!backgoround.loadFromFile(resourcePath()+"background.png")) {
        return EXIT_FAILURE;
    }
    sf::Vector2u myplane_size = myplane.getImage_size();
    //    texture.update(firstplane);
    sf::Sprite backgroundsprite(backgoround);
    //    sprite.setColor(sf::Color(0, 255, 0));
    myplane.setPosition((screen_size.x-myplane_size.x)/2,screen_size.y-myplane_size.y);
    sf::Music music;
    if (!music.openFromFile(resourcePath()+"game_music.ogg")) {
        return EXIT_FAILURE;
    }
    music.play();
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
            if (myplane.checkleft()) {
                myplane.move(-1,0);
            }
        }
        
        // Right Arrow pressed
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
            if(myplane.checkright())
            {
            myplane.move(1,0);
            }
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
            if(myplane.checkup())
            {
            myplane.move(0,-1);
            }
        }
        // Right Arrow pressed
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
            if(myplane.checkdown())
            {
            myplane.move(0,1);
            }
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            if (a.asMilliseconds()%1==0) {
                myplane.fire();
            }
        }
        // clear the window with black color
//        window.clear();
        
        // draw everything here...
        // window.draw(...);
        window.draw(backgroundsprite);
        window.draw(myplane);
        window.draw(bullet);
        // end the current frame
        window.display();
    }
    return EXIT_SUCCESS;
}

// Create the main window
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

//    // Set the Icon
//    sf::Image icon;
//    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
//        return EXIT_FAILURE;
//    }
//    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
//
// Load a sprite to display
//    sf::Texture texture;
//    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
//        return EXIT_FAILURE;
//    }
//    sf::Sprite sprite(texture);
//
//    // Create a graphical text to display
//    sf::Font font;
//    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
//        return EXIT_FAILURE;
//    }
//    sf::Text text("Hello SFML", font, 50);
//    text.setColor(sf::Color::Black);
//
//    // Load a music to play
//    sf::Music music;
//    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
//        return EXIT_FAILURE;
//    }
//
//    // Play the music
//    music.play();
//
//    // Start the game loop
//    while (window.isOpen())
//    {
//        // Process events
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // Close window: exit
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//
//            // Escape pressed: exit
//            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
//                window.close();
//            }
//        }
//
//        // Clear screen
//        window.clear();
//
//        // Draw the sprite
//        window.draw(sprite);
//
//        // Draw the string
//        window.draw(text);
//
//        // Update the window
//        window.display();
//    }

//    return EXIT_SUCCESS;
//}
