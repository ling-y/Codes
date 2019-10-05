//
//  Player.hpp
//  project3
//
//  Created by Lingyan Dou on 5/12/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//

#ifndef Player_h
#define Player_h


#include <iostream>
#include "Board.h"
#include <string>


class Player{
public:
    Player(std::string name);
    std::string name() const;
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const = 0;
    virtual ~Player();
    
    
private:
    std::string mName;
   // Board* m_board;
    // bool mIsActive;

};


class HumanPlayer: public Player
{
public:
    HumanPlayer(std::string name);
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const;
  //  virtual ~HumanPlayer();
    
};


class BadPlayer: public Player
{
public:
    BadPlayer(std::string name);
     virtual int chooseMove(const Board& b, Side s) const;
    // virtual ~BadPlayer();
};

class SmartPlayer: public Player
{
public:
    SmartPlayer(std::string name);
    virtual int chooseMove(const Board& b, Side s) const;
   // virtual ~SmartPlayer();
private:
   int Evaluation(const Board& b, Side s, int& thehole,  int times) const;
    // chooseMove helper funciton to evaluate which move is better(lead to greater difference)
    
};
#endif /* Player_hpp */
