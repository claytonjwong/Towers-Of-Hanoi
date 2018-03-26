//
//  View.cpp
//  ToH
//
//  Created by CLAYTON WONG on 3/24/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <stdio.h>
#include <SFML/Window/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "View.h"

using namespace std;

vector<sf::RectangleShape> View::getRods(int cnt, int width){
    vector<sf::RectangleShape> rods;
    int space=300,x=space,y=200;
    for (int i=0; i<cnt; ++i,x+=space){
        sf::Vector2f size(5,800);
        sf::RectangleShape rod(size);
        rod.move(x,y);
        rod.setFillColor(sf::Color(250,250,250));
        rods.push_back(rod);
    }
    return rods;
}
