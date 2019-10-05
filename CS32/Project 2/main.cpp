//
//
#include <iostream>
#include "Sequence.h"
#include <cassert>
int main() {
    Sequence s;
    // insert new string into an empty sequence
    // isnert more string into the previous sequence
    s.insert(0, "aaa");
    s.insert(1, "aaa");
    s.insert(2, "aaa");
    s.insert(3, "bbb");
    s.insert(4, "eee");
    s.insert(5, "fff");
    s.insert(6, "ggg");
    // find
    assert(s.find("aaa") == 0);
    //remove
    assert(s.remove("aaa") == 3);
    assert(s.size() == 4);
    // insert without giving position
    s.insert("aaa");
    s.insert("hhh");
    s.insert("ccc");
    //size
    assert(s.size() == 7);
    //set
    s.set(5, "aaa");

    ItemType value;
    assert(s.get(0, value) && value == "aaa");
    assert(s.get(1, value) && value == "bbb");
    assert(s.get(2, value) && value == "ccc");
    assert(s.get(3, value) && value == "eee");
    assert(s.get(4, value) && value == "fff");
    assert(s.get(5, value) && value == "aaa");
    assert(s.get(6, value) && value == "hhh");

    Sequence s2;
    // insert empty string
    s2.insert(0, "A");
    s2.insert(1, "B");
    s2.insert(2, "");
    s2.insert(3, "C");
    assert(s2.size() == 4);
    assert(s2.find("") == 2);
    // swap function
    s.swap(s2);
    assert(s.size() == 4  &&   s2.size() == 7 );
    assert(s2.get(0, value) && value == "aaa");
    assert(s2.get(1, value) && value == "bbb");
    assert(s2.get(2, value) && value == "ccc");
    assert(s2.get(3, value) && value == "eee");
    assert(s2.get(4, value) && value == "fff");
    assert(s2.get(5, value) && value == "aaa");
    assert(s2.get(6, value) && value == "hhh");
    assert(s.get(0, value) && value == "A");
    assert(s.get(1, value) && value == "B");
    assert(s.get(2, value) && value == "");
    assert(s.get(3, value) && value == "C");





    // invalid inserts
    assert( s2.insert(250, "a")==-1);
    assert( s2.insert(999, "a")==-1);


// interleave
    Sequence r;
    interleave(s2 ,s, r);
    assert(r.size() == 11 );
    assert(r.get(0, value) && value == "aaa");
    assert(r.get(1, value) && value == "A");
    assert(r.get(2, value) && value == "bbb");
    assert(r.get(3, value) && value == "B");
    assert(r.get(4, value) && value == "ccc");
    assert(r.get(5, value) && value == "");
    assert(r.get(6, value) && value == "eee");
    assert(r.get(7, value) && value == "C");
    assert(r.get(8, value) && value == "fff");
    assert(r.get(9, value) && value == "aaa");
    assert(r.get(10, value) && value == "hhh");



    // swap back
    // check if the size matters
    s.swap(s2);
    assert(s.size() == 7  &&   s2.size() == 4);
    assert(s.get(0, value) && value == "aaa");
    assert(s.get(1, value) && value == "bbb");
    assert(s.get(2, value) && value == "ccc");
    assert(s.get(3, value) && value == "eee");
    assert(s.get(4, value) && value == "fff");
    assert(s.get(5, value) && value == "aaa");
    assert(s.get(6, value) && value == "hhh");
    assert(s2.get(0, value) && value == "A");
    assert(s2.get(1, value) && value == "B");
    assert(s2.get(2, value) && value == "");
    assert(s2.get(3, value) && value == "C");


// interleave again
    // check if the size matters
    interleave(s2 ,s, r);
    assert(r.size() == 11 );
    assert(r.get(0, value) && value == "A");
    assert(r.get(1, value) && value == "aaa");
    assert(r.get(2, value) && value == "B");
    assert(r.get(3, value) && value == "bbb");
    assert(r.get(4, value) && value == "");
    assert(r.get(5, value) && value == "ccc");
    assert(r.get(6, value) && value == "C");
    assert(r.get(7, value) && value == "eee");
    assert(r.get(8, value) && value == "fff");
    assert(r.get(9, value) && value == "aaa");
    assert(r.get(10, value) && value == "hhh");

    Sequence s3;
    s3.insert(0, "aaa");
    s3.insert(1, "hhh");

  // interleave with oneself
    interleave(s3, s3, r);
   // r.dump();
    assert(r.size() == 4 );
    assert(r.get(0, value) && value == "aaa");
    assert(r.get(1, value) && value == "aaa");
    assert(r.get(2, value) && value == "hhh");
    assert(r.get(3, value) && value == "hhh");

    // subsequence
    assert(subsequence(s, s3) == 5);
    assert(subsequence(s3, s3)== 0);


    std::cout << "Passed all tests";
}

