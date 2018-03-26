//
//  Model.h
//  ToH
//
//  Created by CLAYTON WONG on 3/23/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef Model_h
#define Model_h

#include "Move.h"
#include <vector>

class Model {
public:
    
    /* constructors */
    Model(unsigned int disks) : myDisks{disks}, myCurrMove{nullptr}, myRods(RODS,std::vector<int>()) {
        initializeRods();
        generateMoves();
    }
    Model(const Model& src) : Model(src.getDisks()) {}
    
    /* accessors */
    std::vector<std::vector<int>> getRods() const;
    int getDisks() const;
    
private:
    const unsigned int RODS=3,SRC=0,DST=1,AUX=2;
    const unsigned int myDisks;
    std::unique_ptr<Move> myCurrMove;
    std::vector<Move> myMoves;
    std::vector<std::vector<int>> myRods;

    /* helpers */
    void initializeRods();
    void generateMoves();
    void go(int N, int src, int dst, int aux, std::vector<Move>& moves);
};

#endif /* Model_h */
