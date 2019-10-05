#include <iostream>
#include <string>
#include <cassert>

#include "Ticket.h"
#include "BoxOffice.h"

using namespace std;

int main(){
//{
    Ticket t( "Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", 150.00, Ticket::ATHLETICGAME, "August 1, 7:30PM" );
    BoxOffice b;
    
 
    assert( std::to_string( t.getPrice() ) == "150.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Pavillion Row 13" );
    assert( t.getSeat() == 45 );
    
    t = b.buyRoyceHallStudentTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "20.000000" );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20 );
    
    t = b.buyRoyceHallStaffTicket( "Balcony Row J", 120, "An Evening With David Sedaris", Ticket::KIND::OTHER, "October 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "35.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Balcony Row J" );
    assert( t.getSeat() == 120 );
    
    t = b.buyRoyceHallTicket( "Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "130.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    
  
 
    
    t= b.buyRoyceHallStudentTicket( "Orchestra Row U", 20, "CS31", Ticket::ATHLETICGAME, "September 1, 7:30" );
        assert( double( t.getPrice() ) == 120.000000);
        assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
        assert( t.getRow() == "Orchestra Row U" );
        assert( t.getEvent() == "CS31" );
        assert( t.getVenue() == "Royce Hall" );
        assert( t.getSeat() == 20 );
        assert( t.getDayTime()== "September 1, 7:30");
  
    t= b.buyRoyceHallStudentTicket( "Orchestra Row U", 20, "CS31", Ticket::ATHLETICGAME, "September 1, 7:30PM" );
    assert( double( t.getPrice() ) == 120.000000);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30PM");
   
    t= b.buyRoyceHallStudentTicket( "Row U", 20, "CS31", Ticket::ATHLETICGAME, "September 1, 7:30PM" );
    assert( double( t.getPrice() ) == 45.000000);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30PM");
    
    t= b.buyRoyceHallStudentTicket( "Row U", 20, "CS31", Ticket::ATHLETICGAME, "September 1, 7:30" );
    assert( double( t.getPrice() ) == 45.000000);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30");
    
    
    t= b.buyRoyceHallStaffTicket( "Orchestra Row U", 20, "CS31", Ticket::ATHLETICGAME, "September 1, 7:30" );
    assert( double( t.getPrice() ) == 130.000000);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30");
    
    t= b.buyRoyceHallStaffTicket( "Orchestra Row U", 20, "CS31", Ticket::ATHLETICGAME, "September 1, 7:30PM" );
    assert( double( t.getPrice() ) == 130.000000);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30PM");
    
    t= b.buyRoyceHallStaffTicket( "Row U", 20, "CS31", Ticket::ATHLETICGAME, "September 1, 7:30PM" );
    assert( double( t.getPrice() ) == 55.000000);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30PM");
    
    t= b.buyRoyceHallStaffTicket( "Row U", 20, "CS31", Ticket::ATHLETICGAME, "September 1, 7:30" );
    assert( double( t.getPrice() ) == 55.000000);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30");
    
    
    t= b.buyRoyceHallTicket( "Orchestra Row U", 20, "CS31", Ticket::ATHLETICGAME, "September 1, 7:30" );
    assert( double( t.getPrice() ) == 150.000000);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30");
    
    t= b.buyRoyceHallTicket( "Orchestra Row U", 20, "CS31", Ticket::ATHLETICGAME, "September 1, 7:30PM" );
    assert( double( t.getPrice() ) == 150.000000);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30PM");
    
    t= b.buyRoyceHallTicket( "Row U", 20, "CS31", Ticket::ATHLETICGAME, "September 1, 7:30PM" );
    assert( double( t.getPrice() ) == 75.000000);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30PM");
    
    t= b.buyRoyceHallTicket( "Row U", 20, "CS31", Ticket::ATHLETICGAME, "September 1, 7:30" );
    assert( double( t.getPrice() ) == 75.000000);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30");
    
    
    
    
    
    

    t= b.buyRoyceHallStudentTicket( "Row U", 20, "CS31", Ticket::MOVIE, "September 1, 7:30" );
    assert( double( t.getPrice() ) == 10.000000);
    assert( t.getKind() == Ticket::KIND::MOVIE);
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30");

    t= b.buyRoyceHallStaffTicket( "Orchestra Row U", 20, "CS31", Ticket::MOVIE, "September 1, 7:30" );
    assert( double( t.getPrice() ) == 22.500000);
    assert( t.getKind() == Ticket::KIND::MOVIE);
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30");
    
    t= b.buyRoyceHallStaffTicket( "Row U", 20, "CS31", Ticket::MOVIE, "September 1, 7:30" );
    assert( double( t.getPrice() ) == 11.250000);
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30");
    

    t= b.buyRoyceHallTicket( "Row U", 20, "CS31", Ticket::MOVIE, "September 1, 7:30" );
    assert( double( t.getPrice() ) == 12.500000);
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30");

    
    
    
    
    
    t= b.buyRoyceHallStudentTicket( "Row U", 20, "CS31", Ticket::CONCERT, "September 1, 7:30" );
    assert( double( t.getPrice() ) == 20.000000);
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30");
    
    t= b.buyRoyceHallStudentTicket( "Orchestra Row U", 20, "CS31", Ticket::CONCERT, "September 1, 7:30PM" );
    assert( double( t.getPrice() ) == 100.000000);
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30PM");
    
    t= b.buyRoyceHallStaffTicket( "Row U", 20, "CS31", Ticket::CONCERT, "September 1, 7:30" );
    assert( double( t.getPrice() ) == 30.000000);
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30");
    
    
    t= b.buyRoyceHallTicket( "Row U", 20, "CS31", Ticket::CONCERT, "September 1, 7:30PM" );
    assert( double( t.getPrice() ) == 65.000000);
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30PM");
    
    
    
    
    t= b.buyRoyceHallStudentTicket( "Row U", 20, "CS31", Ticket::OTHER, "September 1, 7:30" );
    assert( double( t.getPrice() ) == 10.000000);
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30");
    
    t= b.buyRoyceHallStudentTicket( "Row U", 20, "CS31", Ticket::OTHER, "September 1, 7:30PM" );
    assert( double( t.getPrice() ) == 25.000000);
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30PM");
    
    t= b.buyRoyceHallStaffTicket( "Orchestra Row U", 20, "CS31", Ticket::OTHER, "September 1, 7:30PM" );
    assert( double( t.getPrice() ) == 90.000000);
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30PM");
    
    
    t= b.buyRoyceHallTicket( "Row U", 20, "CS31", Ticket::OTHER, "September 1, 7:30PM" );
    assert( double( t.getPrice() ) == 55.000000);
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Row U" );
    assert( t.getEvent() == "CS31" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getSeat() == 20 );
    assert( t.getDayTime()== "September 1, 7:30PM");
    
    cout << "all tests passed!" << endl ;

    return 0;
    }


