/*
    BUS - TICKETING SYSTEM

    WRITTEN BY: Ashvanth
    STARTED ON: 18/1/20

*/

#include"header.h"  //my header
#include<stdio.h>  
#include<stdlib.h>   
#include<string.h> 

void main()
{
     
 FILE *fb,*fp;

    fb=fopen("BUS.txt","rb+");
    if(fb==NULL)
    {
	fb=fopen("BUS.txt","wb+");
	if(fb==NULL)
	{
	    printf("Error in opening the file\n");
	    exit(0);
	}
    }

   /* fp=fopen("Passenger.txt","rb+");
    if(fb==NULL)
    {
	fb=fopen("Passenger.txt","wb+");
	if(fb==NULL)
	{
	    printf("Error in opening the file\n");
	    exit(0);
	}
    }*/
   
     COVER();
     
     menu(fb);
     
    fclose(fb);

}

 

    
  

