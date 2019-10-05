//
//  BoxOffice.cpp
//  Project5
//
//  Created by Lingyan Dou on 2/20/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;
#include "BoxOffice.h"
#include "Ticket.h"

// constructor
BoxOffice::BoxOffice(){}

Ticket BoxOffice::buyTicket(string row, int seat, string event,string venue,Ticket::KIND kind, string daytime){
    double price=0;
    Ticket t(row, seat, event, venue, 0.0, kind, daytime);
    t.setPrice(price);
    price= t.getPrice();
    Ticket tp(row, seat, event, venue, price, kind, daytime);
    return tp;
}

Ticket BoxOffice::buyRoyceHallTicket(string row, int seat, string event,Ticket::KIND kind, string daytime){
   double price=0;
   Ticket t(row, seat, event,"Royce Hall", 0.0, kind, daytime);
    t.setPrice(price);
    price= t.getPrice();
    Ticket rt(row, seat, event,"Royce Hall", price, kind, daytime);
    return rt;
}

Ticket BoxOffice::buyRoyceHallStaffTicket(string row, int seat, string event,Ticket::KIND kind, string daytime){
    double price=0;
    Ticket t(row, seat, event,"Royce Hall", 0.0, kind, daytime);
    t.setPrice(price);
    price= t.getPrice();
    // discounts
    if (price<40){
        price=price*0.90;
    }
    if (price>=40){
        price=price-20;
    }
    Ticket rt(row, seat, event,"Royce Hall", price, kind, daytime);
    return rt;
}

Ticket BoxOffice::buyRoyceHallStudentTicket(string row, int seat, string event,Ticket::KIND kind, string daytime){
    double price=0;
    Ticket t(row, seat, event,"Royce Hall", 0.0, kind, daytime);
    t.setPrice(price);
    price= t.getPrice();
   // cerr<<price<<endl;
    // discounts
    if (price<40){
        price=price*0.80;
    }
    if (price>=40){
        price=price-30;
    }
    //cerr<<price<<endl;
    Ticket rt(row, seat, event,"Royce Hall", price, kind, daytime);
    return rt;
}
