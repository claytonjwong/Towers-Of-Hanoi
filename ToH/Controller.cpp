//
//  Controller.cpp
//  ToH
//
//  Created by CLAYTON WONG on 3/24/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Controller.h"
#include "View.h"

void Controller::init(){
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    myWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }
    
    // Play the music
    music.play();
    
    sf::Clock waitClock,moveClock;
    sf::Time waitTime=waitClock.restart(),moveTime=moveClock.restart();
    float waitDuration=0,moveDuration=0;
    myState=WAITING;
    
    Move currMove;
    // Start the game loop
    while (myWindow.isOpen())
    {
        // Process events
        sf::Event event;
        while (myWindow.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                myWindow.close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                myWindow.close();
            }
        }
        
        auto rods=myView.getRods();
        auto disks=myView.getDisks();
        
        
        if (myState==WAITING){
            if (waitDuration==0){
                waitTime=waitClock.restart();
            }
            
            waitDuration+=waitTime.asSeconds();
            
            if (waitDuration > 10.0f){ // WAITING to MOVING
                waitDuration=0;
                myState=MOVING;
                
                /*
                for (int i=0; i<disks.size(); ++i){
                    std::cout << "disk " << i
                    << ": x=" << disks[i].getShape().getPosition().x
                    << " y=" << disks[i].getShape().getPosition().y << std::endl;
                }
                std::cout << std::endl;
                */
                
                currMove=myModel.getNextMove();
            
                if (currMove.diskID==Move::DONE){
                    myState=DONE;
                } else {
                    myView.moveDisk(currMove);
                    
                    /*
                    disks=myView.getDisks();
                    for (int i=0; i<disks.size(); ++i){
                        //for (auto disk: disks){
                        std::cout << "disk " << i
                        << ": x=" << disks[i].getShape().getPosition().x
                        << " y=" << disks[i].getShape().getPosition().y << std::endl;
                    }
                    std::cout << std::endl << std::endl << std::endl;
                    */
                    myState=WAITING;
                }
                
            }
        }
        
        /*
        if (myState==MOVING){
            if (moveDuration==0){
                currMove=myModel.getNextMove();
                
                std::cout << "current move: "
                << " disk=" << currMove.diskID
                << " src=" << currMove.srcRod
                << " dst=" << currMove.dstRod
                << std::endl;
                
                disks[currMove.diskID].setState(Disk::MOVING);
                moveTime=moveClock.restart();
            }

            if (disks[currMove.diskID].getState()==Disk::WAITING){ // MOVING to WAITING
                rods[currMove.srcRod].decrementDiskHeight(Disk::HEIGHT);
                rods[currMove.dstRod].incrementDiskHeight(Disk::HEIGHT);
                waitDuration=0;
                myState=WAITING;
                
                
            }
            
            moveDuration+=moveTime.asSeconds();
            
            if (moveDuration > 100.0f){
                
                for (int i=0; i<disks.size(); ++i){
                    //for (auto disk: disks){
                    std::cout << "disk " << i
                    << ": x=" << disks[i].getShape().getPosition().x
                    << " y=" << disks[i].getShape().getPosition().y << std::endl;
                }
                
                moveDuration=0;
                disks[currMove.diskID].move(currMove,rods);
                
                for (int i=0; i<disks.size(); ++i){
                    //for (auto disk: disks){
                    std::cout << "disk " << i
                    << ": x=" << disks[i].getShape().getPosition().x
                    << " y=" << disks[i].getShape().getPosition().y << std::endl;
                }
            }
        }
         */
        
        
        // Clear screen
        myWindow.clear(sf::Color::Black);
        
        
        for (auto rod: rods)
            myWindow.draw(rod.getShape());
        

        for (auto disk: disks){
            myWindow.draw(disk.getShape());
        }
        
        // Update the window
        myWindow.display();
    }
}
