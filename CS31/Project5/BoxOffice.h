//
//  BoxOffice.h
//  Project5
//
//  Created by Lingyan Dou on 2/20/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//

#ifndef BoxOffice_h
#define BoxOffice_h

#include <stdio.h>
#include "Ticket.h"

class BoxOffice{
public:
    
    BoxOffice();
Ticket buyTicket(std::string row, int seat, std::string event,std::string venue, Ticket::KIND kind, std::string daytime);
Ticket buyRoyceHallStudentTicket(std::string row, int seat, std::string event,Ticket::KIND kind, std::string daytime);
Ticket buyRoyceHallStaffTicket(std::string row, int seat, std::string event,  Ticket::KIND kind, std::string daytime);
Ticket buyRoyceHallTicket(std::string row, int seat, std::string event, Ticket::KIND kind, std::string daytime);
    
    
    
    
};








#endif /* BoxOffice_h */
