//
//  Proj5.cpp
//  Project5
//
//  Created by Lingyan Dou on 2/20/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//

#include "Ticket.h"
#include "Project5Helper.h"
#include <iostream>
#include <string>
using namespace std;

Ticket::Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime)
{
    mRow = row;
    mSeat = seat;
    mEvent = event;
    mVenue = venue;
    mPrice = price;
    mDayTime = daytime;
    mKind = kind;
    
}

// getters
string Ticket::getRow(){
    return mRow;
}
int Ticket::getSeat(){
   return mSeat;
}

string Ticket::getEvent(){
    return mEvent;
}
string Ticket::getVenue(){
    return mVenue;
}

double Ticket::getPrice(){
    return mPrice;
}

string Ticket::getDayTime(){

    return mDayTime;
}

Ticket::KIND Ticket::getKind(){
    return mKind;
}

//set price
void Ticket::setPrice(double price){
   // initialisze
    mPrice=0;
    // not RH
    if (mVenue != "Royce Hall"){
        mPrice=price;
    }
    // Royce hall
    else if (mVenue == "Royce Hall"){
         Project5Helper k;
        // pm special price
    if (k.endsWithPM(mDayTime) == true){
        if(mKind == CONCERT)
        {
            mPrice = 65.00;
        }
        else if(mKind == OTHER)
        {
            mPrice = 55.00;
        }
        else if(mKind == MOVIE)
        {
            mPrice = 12.50;
        }
        else if(mKind == ATHLETICGAME)
        {
            mPrice = 75.00;
        }
    }
        // original price
    else if (k.endsWithPM(mDayTime) == false)
    {
        if(mKind == CONCERT)
        {
            mPrice = 50.00;
        }
        else if(mKind == ATHLETICGAME)
        {
            mPrice = 75.00;
        }
        else if(mKind == MOVIE)
        {
            mPrice = 12.50;
        }
        else if(mKind == OTHER)
        {
            mPrice = 40.00;
        }
    }
    // orchestra double the price
    if (k.startsWithOrchestra(mRow)==true){
        mPrice = mPrice*2;
    }
    }
    
}
