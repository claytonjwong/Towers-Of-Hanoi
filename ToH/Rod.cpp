//
//  Rod.cpp
//  ToH
//
//  Created by CLAYTON WONG on 3/27/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Disk.h"
#include "Rod.h"

Rod::Rod(sf::Vector2f pos, sf::Vector2f dim, sf::Color color) {
    myShape.setPosition(pos);
    myShape.setSize(dim);
    myShape.setFillColor(color);
    myHeight=pos.y+dim.y-Disk::HEIGHT;
}

int Rod::getDiskHeight() const {
    return myHeight;
}

sf::RectangleShape Rod::getShape(){
    return myShape;
}

void Rod::incrementDiskHeight(int amount) {
    myHeight-=amount;
}

void Rod::decrementDiskHeight(int amount) {
    myHeight+=amount;
}

