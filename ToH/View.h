//
//  View.h
//  ToH
//
//  Created by CLAYTON WONG on 3/23/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef View_h
#define View_h

#include <SFML/Window/Window.hpp>
#include <vector>
#include "Model.h"
#include "Rod.h"
#include "Disk.h"

class View {
public:
    
    /* constructor */
    View(Model& model, sf::Vector2i dim);
    
    /* accessors */
    //int getDirection() const;
    std::vector<Rod> getRods() const;
    std::vector<Disk> getDisks() const;
    
    //std::vector<sf::RectangleShape> getRods(const Model& model, const sf::Window& window);
    //void drawDisks(sf::Window& window);
    //bool moveDisk(sf::Window& window, int src, int dst);
    //bool isAutoPlay() const;
    
    void moveDisk(Move& m){
        int x=myRods[m.dstRod].getShape().getPosition().x-myDisks[m.diskID].getShape().getSize().x/2;
        int y=myRods[m.dstRod].getDiskHeight();
        myDisks[m.diskID].setPosition(sf::Vector2f(x,y));
        myRods[m.srcRod].decrementDiskHeight(Disk::HEIGHT);
        myRods[m.dstRod].incrementDiskHeight(Disk::HEIGHT);
    }
    

    
    /* helpers */
    
private:
    int myHeight,myWidth;
    std::vector<Rod> myRods;
    std::vector<Disk> myDisks;
    std::vector<sf::Color> myColors;
};

#endif /* View_h */
