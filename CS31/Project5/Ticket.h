//
//  Proj5.hpp
//  Project5
//
//  Created by Lingyan Dou on 2/20/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//

#ifndef Ticket_h
#define Ticket_h

#include <stdio.h>
#include <iostream>
#include <string>




class Ticket
{
public:
    enum KIND{ATHLETICGAME,CONCERT,MOVIE,OTHER};
    // constructor
    Ticket();
    Ticket (std::string row, int seat, std::string event, std::string venue, double price, KIND kind, std::string daytime);
    
    std::string getRow();
    int getSeat();
    std::string getEvent();
    std::string getVenue();
    double getPrice();
    std::string getDayTime();
    void setPrice(double price);
    KIND getKind();
    
   
    
private:
   std:: string mRow;
    int mSeat;
    std::string mEvent;
   std::string mVenue;
    double mPrice;
    KIND mKind;
    std::string mDayTime;
    
    
};







#endif /* Ticket_h */
