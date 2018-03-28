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

View::View(Model& model, sf::Vector2i dim) :
myHeight{dim.y}, myWidth{dim.x},
myColors{sf::Color(255,0,0),sf::Color(255,127,0),sf::Color(255,255,0),sf::Color(0,255,0),sf::Color(0,0,255),sf::Color(148,0,211)}
{
    // rods
    int space=myWidth/4,x=space,y=100;
    for (int i=0; i<model.RODS; ++i){
        Rod rod(sf::Vector2f(x,y),sf::Vector2f(5,400),sf::Color(250,250,250));
        myRods.push_back(rod);
        x+=space;
    }
    
    // disks ( draw bottom up, then reverse, so that index 0 is the smallest disk on top )
    for (int i=model.getDiskCount()-1; i>=0; --i){
        int x=myRods[model.SRC].getShape().getPosition().x,y=myRods[model.SRC].getDiskHeight();
        int diskWidth=(i+1)*Disk::WIDTH_FACTOR;
        sf::Vector2f pos(x-diskWidth/2,y);
        sf::Vector2f dim(diskWidth,Disk::HEIGHT);
        Disk disk(pos,dim,myColors[i]);
        myDisks.push_back(disk);
        myRods[model.SRC].incrementDiskHeight(Disk::HEIGHT);
    }
    reverse(myDisks.begin(),myDisks.end());
    
}

std::vector<Rod> View::getRods() const {
    return myRods;
}

std::vector<Disk> View::getDisks() const {
    return myDisks;
}

/*
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
            disk.setFillColor(sf::Color::Red);
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
 */
