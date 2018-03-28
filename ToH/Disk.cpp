//
//  Disk.cpp
//  ToH
//
//  Created by CLAYTON WONG on 3/27/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "Move.h"
#include "Disk.h"
#include "Rod.h"

Disk::Disk(sf::Vector2f pos, sf::Vector2f dim, sf::Color& color) {
    myShape.setPosition(pos);
    myShape.setSize(dim);
    myShape.setFillColor(color);
}

sf::RectangleShape Disk::getShape() const{
    return myShape;
}

Disk::State Disk::getState() const{
    return myState;
}

void Disk::setState(Disk::State state){
    myState=state;
}

void Disk::setPosition(sf::Vector2f pos){
    myShape.setPosition(pos);
}

