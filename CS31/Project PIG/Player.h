//
//  Player.h
//  Pig
//
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Die.h"

namespace cs31
{
    
    // CS 31 students have been provided this class to represent
    // one of the Pig Players.  Each Player has its own Die, knows
    // its current score from the current round of rolling as well as its overall total.
    // CS 31 students need to complete the TODO portions of this class
    class Player
    {
    public:
        Player();
        int  roll( int amount = 0 );  // toss the Die, unless provided a forced amount value
        void endTurn( );              // end turn, transferring the current score into the total
        int  getTotal( ) const;       // what is the Player's total?
        int  getScore( ) const;       // what is the Player's score?
    private:
        Die  mDie;    // the Player's die
        int  mScore;  // the Player's current rolling total
        int  mTotal;  // the Player's overall game total
    };
    
}

#endif
