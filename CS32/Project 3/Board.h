//
//  Board.hpp
//  project3
//
//  Created by Lingyan Dou on 5/12/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//

#ifndef Board_h
#define Board_h


#include <vector>
#include "Side.h"

using namespace std;



class Board{
public:
    Board(int nHoles, int nInitialBeansPerHole=0);
    

    int holes() const;
    int beans(Side s, int hole) const;
    int beansInPlay(Side s) const;
    int totalBeans() const;
    bool sow(Side s, int hole, Side& endSide, int& endHole);
    bool moveToPot(Side s, int hole, Side potOwner);
    bool setBeans(Side s, int hole, int beans);
    
private:
    int mHoles;
    vector <int> Sarray, Narray;
    int mTotalBeans;
    int mSpot,mNpot;
    
};
#endif /* Board_h */
