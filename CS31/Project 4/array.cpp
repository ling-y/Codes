//
//  main.cpp
//  Project4
//
//  Created by Lingyan Dou on 2/6/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//

#include <iostream>
#include <cassert>
using namespace std;


bool hasDuplicates( const std::string array[ ],  int size );


int  countAllDigits( const std::string array[ ] , int size );


bool isInDecreasingOrder( const std::string array[ ], int size );

int  shiftRight( std::string array[ ], int size, int amount, std::string placeholder );


int  find( const std::string array[ ], int size, std::string match );


int  replaceAllCharacters( std::string array[ ], int size, char findLetter, char replaceLetter );


int main(){
    string folks[8] = {
        "samwell", "jon", "margaery", "daenerys",
        "tyrion", "sansa", "howard123", "jon"
    };
    string people[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
    
    assert(hasDuplicates(folks, 3 ) == false);
    assert(hasDuplicates(folks, 8 ) == true);
    assert(hasDuplicates(folks, -1) == false);
    assert(hasDuplicates(folks, 0) == false);
    
    assert(countAllDigits(folks, 8) == 3);
    assert(countAllDigits(folks, 6) == 0);
    assert(countAllDigits(folks, 0) == -1);
    assert(countAllDigits(folks, -223) == -1);
    
    string aaa[9] = { "ddd", "ccc", "bbb", "aaa", "BBB", "AAA" , "zzz", "aaa", "aaa"};
    
    assert(isInDecreasingOrder(aaa, 3) == true);
    assert(isInDecreasingOrder(aaa, 6) == true);
    assert(isInDecreasingOrder(aaa, -1) == false);
    assert(isInDecreasingOrder(aaa, 0) == true);
    assert(isInDecreasingOrder(aaa, 1) == true);
    assert(isInDecreasingOrder(aaa, 7) == false);
    
    
    string people2[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
    assert(shiftRight(people2, 5, 3, "foo") == 3 && people2[0] == "foo"&& people2[1]=="foo"&& people2[2]=="foo"&& people2[3]=="samwell"&& people2[4]=="jon");
    assert(shiftRight(people2, -5, 3, "foo" ) == -1);
    assert(shiftRight(people2, 5, 25, "foo" ) == 5 && people2[0] == "foo" && people2[1]=="foo" && people2[2]=="foo" && people2[3]=="foo"&& people2[4]=="foo");
    
    
    assert(find( folks, 5, "foo") == -1);
    assert(find( folks, -90, "foo") == -1);
    assert(find( folks, 0, "foo") == -1);
    assert(find( folks, 8, "jon" ) == 1);
    assert(find( aaa, 9, "aaa") == 3);
    
    assert(replaceAllCharacters( people, -5, 'z', 'a' )==-1);
    assert(replaceAllCharacters( people, 0, 'z', 'a' )==-1);
    assert(replaceAllCharacters( people, 5, 'a', '_' )==4 && (people[0] == "s_mwell")&& (people[1] == "jon") && (people[2] == "m_rg_ery")&& (people[3] == "d_enerys" )&& (people[4] == "tyrion" )) ;
    assert(replaceAllCharacters( people, 5, 'z', 'a' )==0);
    
}



bool hasDuplicates( const std::string array[ ],  int size ){
    if (size>0){
        for (size_t i=0; i<size; i++){
            for (size_t k=i+1; k<size; k++){
                //  cerr<<k;
                // check duplicates
                if (array[i] == array[k]){
                    return true;
                }
            }
        }
    }
    return false;
}


int  countAllDigits( const std::string array[ ] , int size ){
    int counter=0;
    if (size>0){
        //array by array
        for (size_t i=0; i<size; i++){
            //char by char
            for (size_t k=0; k<array[i].size(); k++){
                if ( array[i][k]>='0' &&  array[i][k]<='9'){
                    counter++;
                }
            }
        }
        if (counter>=0){
            return counter;
        }
    }
    return -1;
}

// decreasing order
bool isInDecreasingOrder( const std::string array[ ], int size ){
    //size is 0
    if(size==0)
        return true;
    ////<0
    else if(size<0)
        return false;
    for (size_t i=0; i<(size-1); i++){
        // cerr<<array[i]<<"\n"<<array[i+1];
        if (array[i]<=array[i+1]){
            return false;
        }
    }
    return true;
}


int  shiftRight( std::string array[ ], int size, int amount, std::string placeholder ){
    if (size==0 || amount==0)
        return 0;
    else if (size>0 && amount>0)
        
    {   //size is larger
        if (amount<size)
        {
            int max=size-1-amount;
            for (int i=max; i>=0; i--){
                array[(i+amount)]=array[i];
            }
            for (size_t k=0; k<amount; k++){
                array[k] = placeholder;
            }
            return amount;
        }
        //amount is larger
        if (amount>=size)
        {
            for (size_t i=0; i<size; i++)
            {   array[i]=placeholder;
                
            }
            return size;
        }
    }
    return -1;
    
}


int  find( const std::string array[ ], int size, std::string match ){
    if (size>0){
        for (int i=0; i<size; i++){
            //check matches
            if (array[i]==match){
                return i;
                //least index number
                break;
            }
        }
    }
    return -1;
}


int  replaceAllCharacters( std::string array[ ], int size, char findLetter, char replaceLetter ){
    if (size>0){
        //initialize a counter
        int counter=0;
        //two loops
        for (size_t i=0; i<size; i++){
            // array by array
            for (size_t k=0; k<array[i].size(); k++){
                //char by char
                if (array[i][k] == findLetter){
                    array[i][k] = replaceLetter;
                    counter++;
                }
                
            }
            
        }
        return counter;
        
    }
    return -1;
}
