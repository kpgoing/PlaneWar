//
//  Gown.h
//  PlaneWar
//
//  Created by 徐 BOWEI on 15/5/31.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef __PlaneWar__Gown__
#define __PlaneWar__Gown__
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class   Gown
{
public:
//    Gown();
//    static sf::Image image;
    void setuse()
    {
        use = true;
    }
    bool getuse()
    {
        return use;
    }
private:
//    sf::Texture  texture;
    bool use = false;
};
#endif /* defined(__PlaneWar__Gown__) */
