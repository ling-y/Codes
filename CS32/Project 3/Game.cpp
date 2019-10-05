//
//  Game.cpp
//  project3
//
//  Created by Lingyan Dou on 5/12/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//
#include <iostream>
#include <map>

using namespace std;

#include "Game.h"


//North
                    //1  2  3  4  5  6
                    //----------------
                    //2  4  0  0  0  0
//North's pot  22                        16  South's pot
                    //0  0  1  1  1  1
                    //----------------
                    //1  2  3  4  5  6
//South 


Game::Game(const Board& b, Player* south, Player* north):
mBoard(b),mSouth(south),mNorth(north),mTurn(SOUTH)
{
    
}




void Game::display() const
{
    
 cout<< "\t\t  --Kalah-- \t\n";
    if (mTurn==SOUTH) {
        cout<<mSouth->name()<<"'s Turn!"<<endl;
    }
    else if (mTurn==NORTH) {
        cout<<mNorth->name()<<"'s Turn!"<<endl;
    }
    cout<<"\t\t"<<mNorth->name()<<"\t"<<endl;
    int holes = mBoard.holes();
    cout<<" ";
    for(int i=1;i<holes+1;i++)
    {
        cout<< " " <<mBoard.beans(NORTH,i) << " ";
    }
    cout<< "\n" << mBoard.beans(NORTH,0);
    for (int i=1;i<holes+1;i++)
    {
        cout<< "   ";
    }
    cout<<mBoard.beans(SOUTH,0)<<endl;
     cout<<" ";
    for(int i=1;i<holes+1;i++)
    {
        cout<< " " <<mBoard.beans(SOUTH,i) << " ";
    }
    cout<<"\n"<<"\t\t"<<mSouth->name()<<"\t"<<endl;
}

//int Game::Simplemove(Side s, int hole){
// 
//    Side endSide,winner;
//    int endHole,value,value2;
//    bool over, hasWinner;
//    
//    Board old=mBoard;
//  
//        mBoard.sow(s, hole, endSide, endHole);
//       if (endSide==s && endHole==0)
//               {
//                   status(over, hasWinner, winner);
//                   if (over==0){
//                       Board b(mBoard);
//                      std::map<int, int> m;
//                       for (int i = 1; i < mBoard.holes() + 1; i++)
//                       {
//                           if (b.beans(s, i) != 0)
//                       {
//                           value2=Simplemove(s, i);
//                           b=mBoard;
//                           m[value2] = i;
//                       }
//                           
//
//                           
//                       }
//                       
//                       std::map<int, int>::iterator itr ;
//                       if (s==NORTH)
//                       {
//                           itr = m.begin();
//                           value = itr->first;
//                           thehole = itr->second;
//                       }
//                       else
//                       {
//                           itr = m.end();
//                           itr--;
//                           value = itr->first;
//                           thehole = itr->second;
//                       }
//                       
//                       return value;
//                   }
//               }
//        
//        if (endSide==s && endHole!=0 && (old.beans(s, endHole)==0) && mBoard.beans(opponent(s), endHole)!=0){
//            mBoard.moveToPot(s, endHole, s);
//            mBoard.moveToPot(opponent(s), endHole, s);
//        }
//        
//        mTurn=opponent(s);
//        int value = mBoard.beans(SOUTH, 0)-mBoard.beans(NORTH, 0);
//        return value;
//    }



void Game::status(bool& over, bool& hasWinner, Side& winner) const
{
    //If the game isn't over (i.e., more moves are possible), set over to false and do not change anything else. Otherwise, set over to true and hasWinner to true if the game has a winner, or false if it resulted in a tie. If hasWinner is set to false, leave winner unchanged; otherwise, set it to the winning side.
    over=0;
    
    int southbeans=mBoard.beansInPlay(SOUTH);
    int northbeans=mBoard.beansInPlay(NORTH);
    int sumS,sumN;
    
    if ( southbeans==0 || northbeans ==0)
    {
        over=1;
        sumS=mBoard.beans(SOUTH, 0)+southbeans;
        sumN=mBoard.beans(NORTH, 0)+northbeans;
        
        if (sumS==sumN)
        {
            hasWinner=0;
        }
        else if (sumS>sumN)
        {
            hasWinner=1;
            winner=SOUTH;
        }
        else{
            hasWinner=1;
            winner=NORTH;
        }
        
    }
    
}



bool Game::move()
//If the game is over, return false. Otherwise, make a complete move for the player whose turn it is (so that it becomes the other player's turn) and return true. "Complete" means that the player sows the seeds from a hole and takes any additional turns required or completes a capture. If the player gets an additional turn, you should display the board so someone looking at the screen can follow what's happening.
{
    bool over,hasWinner;
    Side winner,endSide;
    int endHole;
    //check for status
    status(over, hasWinner, winner);
    //if game not over
    if (over==0)
    {
        Board old=mBoard;
        if(mTurn==SOUTH)
        {
            //move
            int choose= mSouth->chooseMove(mBoard, SOUTH);
            mBoard.sow(SOUTH, choose, endSide, endHole);
        //    cout<<endHole;
            //check if it ends in this side’s pot

            if(endSide==SOUTH && endHole==0)
            {
                status(over, hasWinner, winner);
                if (over==0)
                {
                    cout<<"IN THE POT!"<<endl;
                    this->display();
                    return Game::move();
                    
                }
                else
                    return true;
            }
            //check for capture
            if (endSide==SOUTH && endHole!=0  && mBoard.beans(NORTH, endHole)!=0)
            {
              
                if( endHole==choose || old.beans(SOUTH, endHole)==0)
                {
                 //   cout<<"yep";
                    mBoard.moveToPot(NORTH, endHole, SOUTH);
                    mBoard.moveToPot(SOUTH, endHole, SOUTH);
                }
            }
            
            mTurn=NORTH;
            return true;
        }
        else
        {
            int choose= mNorth->chooseMove(mBoard, NORTH);
            mBoard.sow(NORTH, choose, endSide, endHole);
            if(endSide==NORTH && endHole==0)
            {
                cout<<"IN THE POT!"<<endl;
                this->display();
                return Game::move();
            }
            if (endSide==NORTH && endHole!=0 && mBoard.beans(SOUTH, endHole)!=0)
            {
                if(endHole==choose || old.beans(NORTH, endHole)==0)
                {
                    mBoard.moveToPot(NORTH, endHole, NORTH);
                    mBoard.moveToPot(SOUTH, endHole, NORTH);
                }
            }
            
            mTurn=SOUTH;
            return true;
        }
      //  mTurn=opponent(mTurn);
    }
    
    
    for(int i=1; i<mBoard.holes()+1;i++){
    mBoard.moveToPot(SOUTH, i, SOUTH);
    mBoard.moveToPot(NORTH, i, NORTH);
    }
    return false;
}


void Game::play()
{
    bool over,hasWinner;
    Side winner;
    //status
    status(over, hasWinner, winner);
    //while loop
    while(over!=1)
    {
       // display and move
        display();
        cout << "Enter to Continue:";
        cin.ignore(1000,'\n');
        move();
  //status again
        status(over, hasWinner, winner);
    }
    if (hasWinner==1)
    {
        //collect all beans
        move();
        display();
        // announce winners
        cout<<mNorth->name()<<"'s Score: "<<mBoard.beans(NORTH, 0)<<endl;
        cout<<mSouth->name()<<"'s Score: "<<mBoard.beans(SOUTH, 0)<<endl;
        if(winner==SOUTH)
            cout<<"\n"<<mSouth->name()<<" WINs!!!"<<endl;
        else
            cout<<"\n"<<mNorth->name()<<" WINs!!!"<<endl;
    }
    else
        cout<<"\nIt's a TIE!!!"<<endl;
    
}

int Game::beans(Side s, int hole) const
{
    return mBoard.beans(s,hole);
}
