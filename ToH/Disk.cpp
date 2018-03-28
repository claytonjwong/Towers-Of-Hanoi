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
    if (myState==WAITING)
        return WAITING;
    return MOVING;
}

void Disk::setState(Disk::State state){
    myState=state;
}

void Disk::move(Move& m, std::vector<Rod>& rods){
    int x=rods[m.dstRod].getShape().getPosition().x,y=rods[m.dstRod].getDiskHeight();
    myShape.move(x,y);
}
