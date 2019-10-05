//
//  Side.hpp
//  project3
//
//  Created by Lingyan Dou on 5/12/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//

#ifndef Side_hpp
#define Side_hpp



enum Side { NORTH, SOUTH };

const int NSIDES = 2;
const int POT = 0;

inline
Side opponent(Side s)
{
    return Side(NSIDES - 1 - s);
}


#endif /* Side_hpp */
