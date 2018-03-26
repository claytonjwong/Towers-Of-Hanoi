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
        : myWindow(sf::VideoMode(1200, 800), "SFML window"), myModel{model}, myView{view} {}
    
    void init();
    
    /* accessors */
private:
    sf::RenderWindow myWindow;
    Model myModel;
    View myView;
};

#endif /* Controller_h */
