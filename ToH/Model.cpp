//
//  Model.cpp
//  ToH
//
//  Created by CLAYTON WONG on 3/24/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <stdio.h>
#include "Model.h"

using namespace std;


int Model::getDiskCount() const {
    return myDiskCount;
}

/*
vector<vector<int>> Model::getDisks() const {
    return myDisks;
}
 */

/* helpers */

void Model::generateMoves(){
    go(myDiskCount,SRC,DST,AUX,myMoves);
}

/*
void Model::initializeRods(){
    for (int i=myDiskCount; i>0; --i)
        myDisks[SRC].push_back(i);
}
 */

void Model::go(int N, int src, int dst, int aux, vector<Move>& moves){
    if (N==0) return;
    go(N-1,src,aux,dst,moves);
    moves.push_back(Move(N-1,src,dst)); // use N-1 for 0-based index for diskID
    go(N-1,aux,dst,src,moves);
}

