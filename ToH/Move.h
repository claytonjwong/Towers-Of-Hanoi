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
    const int src,dst;
    Move(int src, int dst) : src{src}, dst{dst} {}
};

#endif /* Move_h */
