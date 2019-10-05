//
//  Game.hpp
//  project3
//
//  Created by Lingyan Dou on 5/12/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>


#include "Player.h"

class Game{
public:
    Game(const Board& b, Player* south, Player* north);
    void display() const;
    void status(bool& over, bool& hasWinner, Side& winner) const;
    bool move();
    void play();
    int beans(Side s, int hole) const;
private:
    Board mBoard;
    Player * mSouth;
    Player * mNorth;
    Side mTurn;
 //   int Simplemove(Side s, int hole);

    
};
#endif /* Game_hpp */
