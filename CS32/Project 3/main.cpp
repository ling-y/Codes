////
////  main.cpp
////  project3
////
////  Created by Lingyan Dou on 5/12/19.
////  Copyright © 2019 Lingyan Dou. All rights reserved.
////
//
//#include <iostream>
//
//#include "Board.h"

//int main(int argc, const char * argv[]) {
//
//    Board b = Board(5,1);
//    assert(b.totalBeans()==10);
//    b.setBeans(SOUTH, 1, 1);
//    b.setBeans(SOUTH, 2, 2);
//    b.setBeans(SOUTH, 3, 3);
//    b.setBeans(SOUTH, 4, 4);
//    b.setBeans(SOUTH, 5, 18);
//      assert(b.totalBeans()==33);
//    Side one;
//    int two;
//
//  b.sow(SOUTH, 1, one, two);
//
//    assert(b.beans(SOUTH, 1)==0);
//     assert(b.beans(SOUTH, 2)==3);
//      assert(b.beans(SOUTH, 3)==3);
//     assert(b.beans(SOUTH, 4)==4);
//    //0334
////
//   b.sow(SOUTH, 2, one, two);
//    assert(b.beans(SOUTH, 1)==0);
//    assert(b.beans(SOUTH, 2)==0);
//    assert(b.beans(SOUTH, 3)==4);
//    assert(b.beans(SOUTH, 4)==5);
//    assert(b.beans(SOUTH, 5)==19);
//
// //  004519
//   b.sow(SOUTH, 5, one, two);
//    assert(b.beans(SOUTH, 1)==2);
//    assert(b.beans(SOUTH, 2)==2);
//    assert(b.beans(SOUTH, 3)==5);
//    assert(b.beans(SOUTH, 4)==6);
//    assert(b.beans(SOUTH, 5)==1);
//
//    assert(b.beans(NORTH, 1)==3);
//    assert(b.beans(NORTH, 2)==3);
//    assert(b.beans(NORTH, 3)==3);
//    assert(b.beans(NORTH, 4)==3);
//    assert(b.beans(NORTH, 5)==3);
//    assert(b.beans(SOUTH, 0)==2);
//    assert(b.beans(NORTH, 0)==0);
//
//
//
//        b.setBeans(NORTH, 5, 1);
//       b.setBeans(NORTH, 4, 2);
//       b.setBeans(NORTH, 3, 3);
//       b.setBeans(NORTH, 2, 4);
//      b.setBeans(NORTH, 1, 18);
//    assert(b.totalBeans()==46);
//    assert(b.beansInPlay(NORTH)==28);
//    assert(b.beansInPlay(SOUTH)==16);
//
//    b.sow(NORTH, 1, one, two);
//
//    assert(b.beans(SOUTH, 1)==4);
//    assert(b.beans(SOUTH, 2)==4);
//    assert(b.beans(SOUTH, 3)==7);
//    assert(b.beans(SOUTH, 4)==8);
//    assert(b.beans(SOUTH, 5)==3);
//
//    assert(b.beans(NORTH, 1)==1);
//    assert(b.beans(NORTH, 2)==5);
//    assert(b.beans(NORTH, 3)==4);
//    assert(b.beans(NORTH, 4)==3);
//    assert(b.beans(NORTH, 5)==3);
//    assert(b.beans(SOUTH, 0)==2);
//    assert(b.beans(NORTH, 0)==2);
//    Board b(3, 2); //construct board



//}
//
//
//
//
//
//
//
//
//
////}
#include <iostream>
#include <cassert>
#include  "Game.h"


using namespace std;

int main(){
//    BadPlayer bp1("bp12");
//    BadPlayer bp2("bp2");
//    Board b(2, 0);
//    b.setBeans(SOUTH, 1, 1);
//
//    b.setBeans(NORTH, 1, 5);
//
//    Game g(b, &bp1, &bp2);
//    bool over;
//    bool hasWinner;
//    Side winner;
//    g.status(over, hasWinner, winner);
//    assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 0 &&
//           g.beans(NORTH, 1) == 5 && g.beans(NORTH, 2) == 0 &&
//           g.beans(SOUTH, 1) == 1 && g.beans(SOUTH, 2) == 0 );
////
//    g.move();
//
//    g.status(over, hasWinner, winner);
//    assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 0 &&
//           g.beans(NORTH, 1) == 5 && g.beans(NORTH, 2) == 0 &&
//           g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 1 );
//
//  g.move();
//    g.status(over, hasWinner, winner);
//    assert(!over && g.beans(NORTH, POT) == 3 && g.beans(SOUTH, POT) == 0 &&
//           g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 1 &&
//           g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 2 );
//
//    g.move();
//    g.status(over, hasWinner, winner);
//    assert(over && g.beans(NORTH, POT) == 3 && g.beans(SOUTH, POT) == 1 &&
//           g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 2 &&
//           g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 0);
//
//           g.move();
//
//    assert(over && g.beans(NORTH, POT) == 5 && g.beans(SOUTH, POT) == 1 &&
//           g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 0 &&
//           g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 0 );
//    assert(hasWinner && winner == NORTH);
//
//           cout<<"YESSS"<<endl;
////    Side endside;
////    int endhole;
////    b1.sow(SOUTH, 6, endside, endhole);
////   // g.display();
////    cout<<endhole;
////    if (endside==SOUTH)
////        cout<<"south";
////    if(endside==NORTH)
////        cout<<"north";
    SmartPlayer sp("sp");
    SmartPlayer sp2("sp2");
    HumanPlayer hp("hp");
    Board b(6,2);
    Game g(b, &sp, &sp2);
    g.play();


}

