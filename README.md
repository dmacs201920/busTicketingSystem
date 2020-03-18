# busTicketingSystem
A novice implementation of a bus ticketing system in C

OM SRI SAI RAM

/*
   Name Of the student: G.S.K.ASHVANTH

 Registration No.  : 173233

 Pursuing Course   : III.B.Sc Mathematics (Hons)

      Campus       : BRINDAVAN
*/

-- ALL THE FUNCTIONS IN THE PROGRAM ARE WRITTEN SOLELY BY ASHVANTH.



* This Project is about SIMPLE BUS TICKETING SYSTEM.

* In this you can be an ADMIN as well as a PASSENGER.

* As ADMIN you can CREATE Buses,Modify Buses,Delete Buses,Display Passenger List.

* As PASSENGER you Book Ticket,Cancel Ticket,See the Buses,See the Bus Seating Arrangement of each Bus,Print Ticket.

* For Compilation use make.

* The file BUS.txt contains the structure of Buses.

* The directory Passenger_log contains seperate file for each passenger who is booking.

* FOR ADMIN :
   Only one USERNAME:Swami999
   	    PASSWORD:999Swami

  If the above mentioned are not used then after 3 chances it closes the program completely.

* FOR PASSENGER:
 
  Only two set of usernames and passwords.

 	    USERNAME:dharshan123      USERNAME:ashvanth333
	    PASSWORD:123dharshan      PASSWORD:333ashvanth


  If the above mentioned are not used then after 3 chances it closes the program completely.

* In main.c:
     Main function is called here.

* In header.h:

  This my own header file which contains structures of bus,time,date,passenger,seat and Function Prototypes.

* In functions.c:

  Many functions implementaions are done in this file.
  Many funtions includes:

  // GENERAL FUNCTION PROTOTYPES

  void adLogin(FILE *);
  This function is for admin login.

  void pLogin(FILE *);
  This function is for passenger login.

  void printline();
  This function just prints a line of * character for drawing lines.

  void COVER();
  This function prints the cover for project.

  void menu(FILE *);
  This function helps to choose the user whether to be an ADMIN or PASSENGER.

  void admenu(FILE *);
  This function contains admin functions.

  void pmenu(FILE *);
  This function conatins passenger functions.

  int leap(date *);
  This function checks whether the given date is leap year or not.
  Returns 1 if it is a LEAP YEAR.

  char *itoa(unsigned long int );
  This function converts a given unsigned long integer into a string of chars.


// ADMIN FUNTION PROTOTYPES

  int search(FILE *,int );
  This function whetther the bus number already exists int the file or not.
  Return 1 if present else 0.

  void newbus(FILE *);
  This function creates bus and writes in to the file.

  void delete_bus(FILE *);
  This function deletes the bus and writes it into the file.

  void modify_bus(FILE *);
  This function modifies the bus and writes it into the file

  void update_bus(FILE *,int ,int ,int ,seat **);
  This functions updates the bus after each time bus gets added or deleted but this is not used in 
  my project.

  void display_passenger_list(FILE *);
  This function displays all the passengers who have booked across all buses.

  void display_bus_list(FILE *);
  This function displays all the buses in the file.

// PASSENGER FUNCTION PROTOTYPES

  void ticket_reservation(FILE *);
  This function books ticket for a passenger.

  void ticket_cancellation(FILE *);
  This function cancels a ticket for the passenger.

  int search_date(FILE *,date);
  This function returns 1 if the searched date is found.

  int search_place(FILE *,char *,char *);
  This function returns 1 if the searched source and destionation is found.

  int check_seat_free(bus,int,int);
  This function whether the given seat is free or not.

  void bill(float,int);
  This function generates bill.

  void print_ticket(FILE *);
  This prints the ticket of a particular passenger.

  void bus_seating_arrangement(FILE *);
  This function prints the bus outline of a particular bus.






