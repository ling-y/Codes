//
//  Board.h
//  Pig
//
//

#ifndef BOARD_H
#define BOARD_H
#include <string>

namespace cs31
{
    // CS 31 students have been provided this class to represent
    // a Pig Board.  Each Board is made up of a Human score and total
    // as well as a Computer score and total.  A Board also knows the
    // most recent value rolled, whether the game is over, whose
    // turn it is to roll and whether the computer or human won.
    // The display( ) method is used by the Pig game to print the
    // current state of the game.
    // CS 31 students need to complete the TODO portions of this class
    class Board
    {
    public:
        Board();
        
        // accessor and mutator for the human's score
        void setHumanScore( int score );
        int  getHumanScore() const;
        
        // accessor and mutator for the computer's score
        void setComputerScore( int score );
        int  getComputerScore() const;
        
        // accessor and mutator for the recently rolled value
        void setRolledValue( int amount );
        int  getRolledValue() const;
        
        // identify whose turn it is
        void setHumanTurn( );
        void setComputerTurn( );
        bool isHumanTurn() const;
        
        // identify who won the game
        void markComputerAsWinner();
        void markHumanAsWinner();
        bool isHumanWinner() const;
        
        // accessor and mutator for the game over boolean
        void setGameOver( bool value );
        bool isGameOver( ) const;
        
        // accessor and mutator for the human's total
        void setHumanTotal( int total );
        int  getHumanTotal( ) const;
        
        // accessor and mutator for the computer's total
        void setComputerTotal( int total );
        int  getComputerTotal( ) const;
        
        // stringify this Board using a Pig game layout
        std::string display( ) const;
    private:
        int  mHumanScore, mHumanTotal;          // the human's score and total
        int  mComputerScore, mComputerTotal;    // the computer's score and total
        int  mRolledValue;                      // the recently rolled value
        bool mIsHumanTurn;                      // is it the Human's turn?
        bool mGameOver;                         // is the game over?
        bool mHumanWon;                         // did the Human win?
    };
}

#endif
