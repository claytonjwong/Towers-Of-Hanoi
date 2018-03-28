//
//  Move.h
//  ToH
//
//  Created by CLAYTON WONG on 3/23/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef Move_h
#define Move_h

struct Move {
    int diskID,srcRod,dstRod;
    Move() : diskID{-1}, srcRod{-1}, dstRod{-1} {}
    Move(int disk, int src, int dst) : diskID{disk}, srcRod{src}, dstRod{dst} {}
    Move(const Move& rhs)=default;
    Move& operator=(const Move& rhs)=default;
};

#endif /* Move_h */
