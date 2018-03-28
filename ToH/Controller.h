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
    enum State { WAITING, MOVING, DONE };
    
    /* constructors */
    Controller(Model model, View view, sf::Vector2i dim)
    : myWindow(sf::VideoMode(dim.x,dim.y), "Towers of Hanoi"), myModel{model}, myView{view}, myState{WAITING} {}
    
    Controller(const Controller& src)=delete;
    Controller& operator=(const Controller& rhs)=delete;
    
    void init();
    
    /* accessors */
private:
    sf::RenderWindow myWindow;
    Model myModel;
    View myView;
    int myState;
};

#endif /* Controller_h */
