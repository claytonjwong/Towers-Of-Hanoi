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

int Model::getDisks() const {
    return myDisks;
}

vector<vector<int>> Model::getRods() const {
    return myRods;
}

/* helpers */
void Model::generateMoves(){
    go(myDisks,SRC,DST,AUX,myMoves);
}

void Model::initializeRods(){
    for (int i=myDisks; i>0; --i)
        myRods[SRC].push_back(i);
}

void Model::go(int N, int src, int dst, int aux, vector<Move>& moves){
    if (N==0) return;
    go(N-1,src,aux,dst,moves);
    moves.push_back(Move(src,dst));
    go(N-1,aux,dst,src,moves);
}

