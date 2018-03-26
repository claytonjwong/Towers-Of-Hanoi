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
#include "Model.h"
#include "View.h"

using namespace std;

vector<sf::RectangleShape> View::getRods(const Model& model, const sf::Window& window){
    vector<sf::RectangleShape> rods;
    auto disks=model.getDisks();
    int space=300,x=space,y=200;
    for (int i=0; i<model.RODS; ++i,x+=space){
        sf::Vector2f rodSize(5,800);
        sf::RectangleShape rod(rodSize);
        rod.move(x,y);
        rod.setFillColor(sf::Color(250,250,250));
        rods.push_back(rod);
        
        int diskY=700;
        for (int j=0; j<disks[i].size(); ++j){
            int width=(disks[i][j]+1)*80;
            sf::Vector2f diskSize(width,20);
            sf::RectangleShape disk(diskSize);
            disk.move(x,diskY);
            disk.setFillColor(sf::Color(250,250,250));
            rods.push_back(disk);
            diskY-=50;
        }
    }
    return rods;
}

sf::RectangleShape View::getDisk(int x, int y, int width, sf::Color& color){
    sf::RectangleShape disk;
    sf::Vector2u size(50,width);
    disk.move(x,y);
    disk.setFillColor(color);
    return disk;
}
