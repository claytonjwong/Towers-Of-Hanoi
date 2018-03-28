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
    
    // load move sound to play
    sf::Music moveSound;
    if (!moveSound.openFromFile(resourcePath() + "move.ogg")) {
        return EXIT_FAILURE;
    }
    
    // Play the music
    //music.play();
    
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
        
        // Clear screen
        myWindow.clear(sf::Color::Black);
        
        // draw rods
        auto rods=myView.getRods();
        for (auto rod: rods)
            myWindow.draw(rod.getShape());
        
        // draw disks
        auto disks=myView.getDisks();
        for (auto disk: disks){
            myWindow.draw(disk.getShape());
        }
        
        // Update the window
        myWindow.display();
        
        
        if (myState==WAITING){
            if (waitDuration==0){
                waitTime=waitClock.restart();
            }
            
            waitDuration+=waitTime.asSeconds();
            
            if (waitDuration > 100.0f){ // *** WAITING to MOVING ***
                moveDuration=0;
                myState=MOVING;
            }
        }
        
        if (myState==MOVING){
            if (moveDuration==0){
                moveTime=moveClock.restart();
                currMove=myModel.getNextMove();
            }
            
            moveDuration+=moveTime.asSeconds();
            
            if (moveDuration > 100.0f){
                if (currMove.diskID==Move::DONE){ // *** DONE ***
                    myState=DONE;
                } else {
                    myView.moveDisk(currMove);
                    moveSound.play();
                    
                    waitDuration=0;
                    myState=WAITING; // *** MOVING to WAITING ***
                }
            }
        }
    } // game loop
}
