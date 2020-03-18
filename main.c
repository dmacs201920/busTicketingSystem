/*
   BUS - TICKETING SYSTEM

   WRITTEN BY:  G.S.K.Ashvanth

     REG.NO  :  173233

     COURSE  : III.B.Sc Mathematics(Hons)
  
*/

#include"header.h"  //my header
#include<stdio.h>  
#include<stdlib.h>   
#include<string.h> 
#include<ctype.h>

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

    
    COVER();

    menu(fb);

    fclose(fb);

}






