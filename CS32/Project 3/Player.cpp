//
//  Player.cpp
//  project3
//
//  Created by Lingyan Dou on 5/12/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//

#include "Player.h"
#include <map>
Player::Player(std::string name):
mName(name)
{
}

Player::~Player()
{}

std::string Player::name() const
{
    return mName;
    
}

bool Player::isInteractive() const
{
    return 0;
}


HumanPlayer::HumanPlayer(std::string name):
Player(name)
{}

//HumanPlayer::~HumanPlayer(){}

int HumanPlayer::chooseMove(const Board& b, Side s) const
{
    int choose;
    std::cout<<"Choose a Move:"<<std::endl;
    std::cin>>choose;
    
   if ( choose>0 && choose<= b.holes() && b.beans(s, choose)>0)
   {
       return choose;
   }
   else
   {
       return chooseMove(b, s);
   }
   // return -1;
    
}

bool HumanPlayer::isInteractive() const
{
    return 1;
}

BadPlayer::BadPlayer(std::string name):
Player(name)
{}

//BadPlayer::~BadPlayer(){}

int BadPlayer::chooseMove(const Board& b, Side s) const
{
//loop to find the first none zero hole on their side
//return the position of that hole
for(int i=1;i<b.holes()+1;i++)
    {
        if (b.beans(s, i)>0)
            return i;
    }
    return -1;
}

SmartPlayer::SmartPlayer(std::string name):
Player(name)
{}

//SmartPlayer::~SmartPlayer(){
//    
//}

int SmartPlayer::chooseMove(const Board& b, Side s) const

{

    int thehole=1;
    int times=0;

    Evaluation(b,s,thehole,times);
    
//    if (b.beans(s, thehole)==0){
//        for(int i=1;i<b.holes()+1;i++)
//            {
//                    if (b.beans(s, i)>0)
//                    {
//                         thehole = i;
//                        return i;
//                }
//    }
//
    
    
//    }
    
    return thehole;
    
}


int SmartPlayer::Evaluation(const Board& b, Side s, int& thehole, int times) const
{
   // cout<<"one"<<endl;
    
    int value;
    int value2;
    int endhole;
    Side  endside;
// Make a copy of board to make change
     Board copy=b;
    int southbeans=b.beansInPlay(SOUTH);
    int northbeans=b.beansInPlay(NORTH);
  
//- Check if some side is going to win(the beans number in one pot is greater than half of the total beans)(this step saves time)
//if yes, return positive and negative infinity depending on the winner (positive if south wins and negative if north wins)
  if(b.beans(SOUTH, 0)>(b.totalBeans()/2))
        {
            return 100000000;
        }
    if(b.beans(NORTH, 0)>(b.totalBeans()/2))
         {
             return -100000000;
         }
    
    
//- Check if the game ends
    if ( southbeans==0 || northbeans == 0)
    {
//if ends, set value to beans in South pot minus beans in the North pot (the difference in beans), return positive and negative infinity depending on the winner
        for (int i = 1; i < b.holes() + 1; i++)
        {
            copy.moveToPot(s, i , s);
            copy.moveToPot(opponent(s), i , opponent(s));
        }
            if(copy.beans(SOUTH, 0)>copy.beans(NORTH, 0))
            {
                return 100000000;
            }
            else if(copy.beans(NORTH, 0)>copy.beans(SOUTH, 0))
            {
                return -100000000;
            }
         else
             return 0;

        
    }
//- Check if depth>=6 (to limit the time)
        if(times>=6)
        {
//if it does, set value to the difference(South-North) between pots, return value
            // value always be (south-north)
            value=copy.beans(SOUTH, 0)-copy.beans(NORTH, 0);
            return value;
            
        }
    
// use map to record value with position
       std::map<int, int> m;
//Loop to find holes that contains beans(>0), for each of such hole
        for (int i = 1; i < b.holes() + 1; i++)
        {
            if (copy.beans(s, i) != 0)
            {
                copy.sow(s, i, endside, endhole);
     //    check for special cases
                // capture
                if (endside == s && endhole != 0 && copy.beans(opponent(s), endhole) != 0)
                {
                    if(b.beans(s, endhole)== 0 || endhole==i)
                    {
                    copy.moveToPot(s, endhole, s);
                    copy.moveToPot(opponent(s), endhole, s);
                    }
                }
                // pot -> again
                if(endside == s && endhole == 0)
                {
                    // recursion
                    value2 = Evaluation(copy, s, thehole, times);
                    copy=b;
                    m[value2] = i;
            //        thehole=i;
                }
else
{
            // recursion
                value2 = Evaluation(copy, opponent(s), thehole, times+1);

            // unmake the move
                copy=b;
                m[value2] = i;
                 //   thehole=i;
                }
            }
        }
        
    //sorted map
    std::map<int, int>::iterator itr ;
    if (s==NORTH)
    {
        itr = m.begin();
        value = itr->first;
        thehole = itr->second;
    }
    else
    {
        itr = m.end();
        itr--;
        value = itr->first;
        thehole = itr->second;
    }

        return value;

}






