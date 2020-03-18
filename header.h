/*
   BUS - TICKETING SYSTEM

   WRITTEN BY:  G.S.K.Ashvanth

     REG.NO  :  173233

     COURSE  : III.B.Sc Mathematics(Hons)
  
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int tot_bus;  // Total no. of Buses in File

typedef struct     //structure for time
{
    int Hr,Min;
}time;

typedef struct        //structure for date
{
    int dd,mm,yyyy;
}date;
typedef struct passenger     //structure for passenger
{
    unsigned long int pid;
    date da;
    char name[50];
    char sex;
    int age;
    char source[20];
    char dest[20];
    int busn;
    int seat_no;
    char bty;
    time arr,dep;
    char book_status;
    float amount;
    //  int row,col;

}pass;

typedef struct seat
{
    pass p1;

}seat;

typedef struct bus    //structure for bus
{
    date d;
    int bnum;
    char btype;
    char bname[30];
    seat s[13][4];
    time depart,arrival;
    char from[20];
    char to[20];
    float fare;
    int ticket_left;


}bus;

// GENERAL FUNCTION PROTOTYPES
void adLogin(FILE *);
void pLogin(FILE *);
void printline();
void COVER();
void menu(FILE *);
void admenu(FILE *);
void pmenu(FILE *);
int leap(date *);
char *itoa(unsigned long int );

// ADMIN FUNTION PROTOTYPES
int search(FILE *,int );
void newbus(FILE *);
void delete_bus(FILE *);
void modify_bus(FILE *);
void update_bus(FILE *,int ,int ,int ,seat **);
void display_passenger_list(FILE *);
void display_bus_list(FILE *);

// PASSENGER FUNCTION PROTOTYPES
void ticket_reservation(FILE *);
void ticket_cancellation(FILE *);
int search_date(FILE *,date);
int search_place(FILE *,char *,char *);
int check_seat_free(bus,int,int);
void bill(float,int);
void print_ticket(FILE *);
void bus_seating_arrangement(FILE *);


