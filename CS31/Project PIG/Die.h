//
//  Die.h
//  Pig
//
//

#ifndef DIE_H
#define DIE_H

namespace cs31
{
    
    // CS 31 Students have been provided this class which
    // simulates a random Die toss.  When roll( ) is called,
    // a value between 1 - mSides will be calculated and stored.
    // Retrieve the value rolled by calling getValue( ).
    class Die
    {
    public:
        Die( int sides = 6 );   // by default, a six sided die
        void roll();            // tossing the die, updating mValue
        int  getValue( ) const; // retrieve the value that was just tossed
    private:
        int  mSides;            // how many sides are on this die?
        int  mValue;            // the value of the most recent toss
    };

    
}
#endif
