//
//  Board.cpp
//  project3
//
//  Created by Lingyan Dou on 5/12/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//

#include "Board.h"
#include <iostream>

Board::Board(int nHoles, int nInitialBeansPerHole):
mSpot(0),mNpot(0)
{
    if (nHoles<=0)
        nHoles = 1;
    if (nInitialBeansPerHole<0)
        nInitialBeansPerHole = 0;
    
    mHoles=nHoles;
    mTotalBeans=nHoles*nInitialBeansPerHole*2;
    
    for (int i = 0; i < nHoles; i++)
    {
        Sarray.push_back(nInitialBeansPerHole);
        Narray.push_back(nInitialBeansPerHole);
    }

  
    
}


int Board::holes() const
{
    return mHoles;
}

int Board::beans(Side s, int hole) const{
    if (hole<0 || hole > mHoles)
        return -1;
    if (s==SOUTH)
    {
        if (hole==0)
            return mSpot;
        else
        return Sarray[hole-1];
    }
    else
    {    if (hole==0)
         return mNpot;
        else
         return Narray[hole-1];
    }
}



int Board::beansInPlay(Side s) const
{
    int sum=0;
    if (s==SOUTH){
        for (int i = 0; i < mHoles; i++){
            int curr= Sarray[i];
            sum+=curr;
        }
            }
    else {
        for (int i = 0; i < mHoles; i++){
            int curr= Narray[i];
            sum+=curr;
    }
    
}
        return sum;
}

int Board::totalBeans() const
    {
        return mTotalBeans;
    }


bool Board::sow(Side s, int hole, Side& endSide, int& endHole)
{
  // Check if the input hole number is valid
    if(hole>0 && hole<=mHoles)
    {
        //Check for side
        if (s==SOUTH && Sarray[hole-1] != 0)
        {
            int beans = Sarray[hole-1];
            Sarray[hole-1]=0;
//std::cout<<Narray[1];
            // Check for rounds
            int round = beans/(2*mHoles+1);
            
                for(int k = 0; k < mHoles; k++)
                {
                    Sarray[k]+=round;
                    Narray[k]+=round;
            }
            mSpot+=round;
            beans = beans-round*(2*mHoles+1);
          //  cout<<beans;
            // Check for remaining beans
            int max=mHoles-hole;
            // 1.check if the beans end on the south side
            if (beans<=max)
            {
                endHole=hole;
                for (int i=0; i<beans; i++)
                {
                    Sarray[hole+i]++;
                    endHole= hole+i+1;
                }
                endSide=SOUTH;

                
                return true;
            }
            
            else{
                for (int i=0; i<max; i++)
                {
                    Sarray[hole+i]++;
                }
                beans=beans-max-1;
                mSpot++;
                // check if it ends up in the pot
                if (beans==0)
                {
                    endSide=SOUTH;
                    endHole=0;
                    return true;
                }
          //      cout<<beans;
                // 2. check if beans end on the north side
            if(beans<=mHoles){
            for (int i = 0; i < beans; i++)
            {
              //  cout<<"  "<<i<<"   ";
                Narray[mHoles-1-i]++;
                endHole=mHoles-i;
            }
                endSide=NORTH;
                return true;
                }
                
                else
                {
                    // 3. the beans end up on the South
                    for (int i = 0; i < mHoles; i++)
                    {
                        Narray[i]++;
                    }
                    beans= beans-mHoles;
               //  cout<<beans;
                    for(int i=0;i<beans;i++)
                    {
                        Sarray[i]++;
                        endHole=i+1;
                       // cout<<i;
                    }
                    endSide=SOUTH;
                    return true;
                }
        }
            
        }
            
            

            if (s==NORTH && Narray[hole-1] != 0)
            {
                int beans = Narray[hole-1];
                Narray[hole-1]=0;
                int round = beans/(2*mHoles+1);
                for (int i = 0; i < round; i++)
                {
                    for(int k = 0; k < mHoles; k++)
                    {
                        Sarray[k]++;
                        Narray[k]++;
                    }
                    mNpot++;
                }
                beans = beans-round*(2*mHoles+1);
                
                int max=hole-1;
                if (beans<=max)
                {
                    endHole=hole;
                    for (int i=0; i<beans; i++)
                    {
                        Narray[hole-2-i]++;
                        endHole=hole-1-i;
                    }
                    endSide=NORTH;
                    return true;
                }
                else{
                    
                    for (int i=0; i<max; i++)
                    {
                        Narray[hole-2-i]++;
                    }
                    beans=beans-max-1;
                    mNpot++;
                    if (beans==0)
                    {
                        endHole=0;
                        endSide=NORTH;
                        return true;
                    }
                    
                    if(beans<=mHoles){
                    for (int i = 0; i < beans; i++)
                    {
                        Sarray[i]++;
                        endHole=i+1;
                    }
                    endSide=SOUTH;
                        return true;}
                    
                    else{
                        
                        for (int i = 0; i < mHoles; i++)
                        {
                            Sarray[i]++;
                        }
                        beans= beans-mHoles;
                        //  cout<<beans;
                        for(int i=0;i<beans;i++)
                        {
                            Narray[mHoles-1-i]++;
                            endHole=mHoles-i;
                            // cout<<i;
                        }
                        endSide=NORTH;
                        return true;
                    }
                        
                }

}
        
        
    }
        

            return false;
        }


bool Board::moveToPot(Side s, int hole, Side potOwner){
   
    if (hole>0 && hole<= mHoles){
         int i =0;
        if(s==SOUTH)
        {
            i = Sarray[hole-1];
            Sarray[hole-1]=0;
        }
        if(s==NORTH)
        {
            i = Narray[hole-1];
            Narray[hole-1]=0;
        }
        if (potOwner==SOUTH)
        {
            mSpot+=i;
            return true;
        }
        if (potOwner==NORTH)
        {
            mNpot+=i;
            return true;
        }
    }
    return false;
}

bool Board::setBeans(Side s, int hole, int beans){
    if (hole>=0 && hole<= mHoles && beans>=0)
    {
        int pre=0;
        if(s==SOUTH)
        {
            if(hole==0){
                pre = mSpot;
                mSpot= beans;
            }
            else{
                pre = Sarray[hole-1];
                Sarray[hole-1]=beans;
            }
        }
        else{
            if(s==NORTH)
            {
                if(hole==0)
                {
                    pre = mNpot;
                    mNpot=beans;
                }
                else
                {
                    pre = Narray[hole-1];
                    Narray[hole-1]=beans;
                }
            }
    }
        mTotalBeans=mTotalBeans-pre+beans;
        return true;
    }
    return false;
}
