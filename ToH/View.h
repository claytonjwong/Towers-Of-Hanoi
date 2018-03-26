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
#include "Model.h"

class View {
public:
    
    /* constructor */
    View() : direction{1}, autoPlay{true}, state{0} {}
    
    /* accessors */
    //int getDirection() const;
    
    std::vector<sf::RectangleShape> getRods(const Model& model, const sf::Window& window);
    //void drawDisks(sf::Window& window);
    //bool moveDisk(sf::Window& window, int src, int dst);
    //bool isAutoPlay() const;
    
    /* helpers */
    
private:
    int direction;
    bool autoPlay;
    int state;
    
    sf::RectangleShape getDisk(int x, int y, int width, sf::Color& color);
};

#endif /* View_h */
