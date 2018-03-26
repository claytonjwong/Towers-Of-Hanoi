//
//  Controller.cpp
//  ToH
//
//  Created by CLAYTON WONG on 3/24/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

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
    
    sf::Clock clock;
    float duration=float();
    
    sf::Vector2f size(50,50);
    sf::RectangleShape shape(size);
    shape.setFillColor(sf::Color(100,250,50));
    
    int x=50,y=0;
    
    // Start the game loop
    while (myWindow.isOpen())
    {
        
        sf::Time dt=clock.restart();
        duration+=dt.asSeconds();
        
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
        
        auto rods=myView.getRods(myModel.RODS, myWindow.getSize().x);
        
        if (duration > 1.0f){
            duration=0;
            x+=10;
            shape.move(x,y);
        }
        
        // Clear screen
        myWindow.clear(sf::Color::Black);
        
        myWindow.draw(shape);
        for (auto rod: rods)
            myWindow.draw(rod);
        
        
        // Draw the sprite
        //window.draw(sprite);
        
        // Draw the string
        //window.draw(text);
        
        // Update the window
        myWindow.display();
    }
}
