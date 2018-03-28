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
#include <memory>

class Model {
public:
    
    /* constructors */
    Model(unsigned int disks) : myCurrMoveIndex{-1}/*, myDisks(RODS,std::vector<int>())*/ {
        myDiskCount=disks>MAX_DISKS ? MAX_DISKS : disks;
        generateMoves();
    }
    Model(const Model& src) : Model(src.getDiskCount()) {}
    
    /* accessors */
    std::vector<std::vector<int>> getDisks() const;
    
    int getDiskCount() const;
    
    Move getNextMove() {
        if (++myCurrMoveIndex < myMoves.size())
            return myMoves[myCurrMoveIndex];
        myCurrMoveIndex=(int)myMoves.size()-1;
        return myMoves[myCurrMoveIndex];
    }
    
    const unsigned int MAX_DISKS=6,RODS=3,SRC=0,DST=1,AUX=2;

private:
    unsigned int myDiskCount;
    int myCurrMoveIndex;
    std::vector<Move> myMoves;
    //std::vector<std::vector<int>> myDisks;

    /* helpers */
    //void initializeRods();
    void generateMoves();
    void go(int N, int src, int dst, int aux, std::vector<Move>& moves);
};

#endif /* Model_h */
