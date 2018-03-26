//
//  Controller.h
//  ToH
//
//  Created by CLAYTON WONG on 3/23/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef Controller_h
#define Controller_h


#include "Model.h"
#include "View.h"

class Controller {
public:
    /* constructors */
    Controller(Model model, View view)
        : window(sf::VideoMode(800, 600), "SFML window"), model{model}, view{view} {}
    
    void init();
    
    /* accessors */
private:
    sf::RenderWindow window;
    Model model;
    View view;
};

#endif /* Controller_h */
