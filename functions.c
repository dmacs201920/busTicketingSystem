//****************************************************************************************************************************************************************    

// Functions used in Project
#include"header.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//****************************************************************************************************************************************************************    


/*typedef struct passenger     //structure for passenger
  {
  char name[50];
  char sex;
  int age;
  char source[15];
  char dest[30];
  int busn;
  int seat_no;
  char bty;


  }pass;

  typedef struct     //structure for time
  {
  int Hr,Min;
  }time;

  typedef struct seato
  {
  pass p1;

  }seat;

  typedef struct bus    //structure for bus
  {
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
 */

//****************************************************************************************************************************************************************    

//ADMIN LOGIN FUNCTION

void aLogin(FILE *fb)
{
   int l1,l2;
   char user_name[20];
   char password[20];
   int cnt=4;


    while(1)
    {
	getchar();
	printf("Enter Admin name:");
	fgets(user_name,20,stdin);

	l1=strlen(user_name);
	if(user_name[l1-1]=='\n')
		user_name[l1-1]='\0';
	
	printf("\nEnter Password:");
	fgets(password,20,stdin);

	l2=strlen(password);
	if(password[l2-1]=='\n')
		password[l2-1]='\0';

puts(user_name);

	if(strcmp(user_name,"Swami999")==0)
	{
	    if(strcmp(password,"999Swami")==0)
	    {
		printf("Login Successful!! \n\n");
		admenu(fb);
		return;
	    }
	}

	else
	{
	    printf("LOGIN Unsuccessful!!\n\n");
	    cnt--;

	    if(cnt==0)
	    {
		printf("PROGRAM EXITING!!\n\n");
		exit(0);
	    }
	    printf("Number of chances left for login :%d \n\n",cnt);
	}
    }
	   
}

//****************************************************************************************************************************************************************    
//****************************************************************************************************************************************************************    

// PASSENGER LOGIN FUNCTION

void pLogin(FILE *fb)
{
    int l1,l2;
    char user_name[20];
    char password[20];
    int cnt=4;

    while(1)  
    {
	getchar();
	printf("Enter Passenger name:");
	fgets(user_name,20,stdin);

	l1=strlen(user_name);
	if(user_name[l1-1]=='\n')
		user_name[l1-1]='\0';
	
	printf("\nEnter Password:");
	fgets(password,20,stdin);

	l2=strlen(password);
	if(password[l2-1]=='\n')
		password[l2-1]='\0';

	if(strcmp(user_name,"dharshan123")==0)
	{
	    if(strcmp(password,"123dharshan")==0)
	    {
		printf("Login Succesful!! \n");
		pmenu(fb);
		return;
	    }
	}

	else  if(strcmp(user_name,"ashvanth333")==0)
	{  

	    if(strcmp(password,"333ashvanth")==0)
	    {
		printf("Login Successful!! \n");
		pmenu(fb);
		return;
	    }
	}

	else
	{
	    printf("LOGIN Unsuccessful!!\n");
	    cnt--;

	    if(cnt==0)
	    {
		printf("PROGRAM EXITING!!\n");
		exit(0);
	    }
	    printf("Number of chances left for login :%d \n",cnt);
    	}
    }
	  
	
}

//****************************************************************************************************************************************************************    
//****************************************************************************************************************************************************************    

//PRINT LINE FUNCTION

void printline()
{
    int a;
    for(a=0;a<84;a++)
	printf("$$");
    printf("\n");
}

//****************************************************************************************************************************************************************    
//****************************************************************************************************************************************************************    

//COVER PAGE FUNCTION

void COVER()
{
    printf(" ________________________________________________________________________________________\n");
    printf("|                           Om     Sri    Sai     Ram                                    |\n");
    printf("|                                                                                        |\n");
    printf("|                                                                                        |\n");
    printf("|                                                                                        |\n");
    printf("|                                BHAGYALAKSHMI                                           |\n");
    printf("|                                                                                        |\n");
    printf("|                                                                                        |\n");
    printf("|                   BUS            TICKETING           SYSTEM                            |\n");
    printf("|                                                                                        |\n");
    printf("|                                                                                        |\n");
    printf("|                                                                                        |\n");
    printf("|                                                                                        |\n");
    printf("|                                                       By:                              |\n");
    printf("|                                                          G.S.K.Ashvanth                |\n");
    printf("|                                                              173233                    |\n");
    printf("|                                                          III B.Sc (MATHS)              |\n");
    printf("|________________________________________________________________________________________|\n");
    printline();

}

//****************************************************************************************************************************************************************    
//****************************************************************************************************************************************************************    

//LOGIN MENU

void menu(FILE *fb)
{
    int i,n,j;
    printf("\n");
lmenu:
    printf("       LOGIN          :\n\n");
    printf("1.PASSENGER\n");
    printf("2.ADMIN\n");
    printf("0.EXIT\n");
    printf("Choose your option[1/2]:");
    scanf("%d",&i);

    if(i>2 || i<0)
    {
	printf("wrong option!!\n");
	goto lmenu;
    }

    switch(i)
    {
	case 1: 
	    pLogin(fb);
	    break;

	case 2:
	    aLogin(fb);
	    break;

	case 0:
	    exit(-1);

	default:
	    break;

    }
    printline();
}

//****************************************************************************************************************************************************************    
//****************************************************************************************************************************************************************    

//ADMIN MENU

void admenu(FILE *fb)
{
    int i,j,n;
    printf("\n\n");

admenu:
    printf("     ADMIN MENU   :\n");
    printf("--------------------\n\n");
    printf("1.CREATE BUS\n");
    printf("2.DELETE BUS\n");
    printf("3.MODIFY BUS\n");
    printf("4.DISPLAY BUS\n");
    printf("5.PASSENGER LIST\n");
    printf("Choose your option[1/2/3/4/5]:");
    scanf("%d",&i);

    if(i>5 || i<1)
    {
	printf("wrong option!!\n");
	goto admenu;
    }

    switch(i)
    {
	case 1: 
	       printf("Enter the no. of BUSES to be CREATED :\n");
	       scanf("%d",&n);

	       for(j=0;j<n;j++)

		newbus(fb);

	        break;


	case 2: 
	       delete_bus(fb);
	       break;

	case 3: 
	       modify_bus(fb);
	       break;

	case 4:
	       display_bus_list(fb);

	case 5: 
	       display_passenger_list(fb);

       default:
	      break;
    } 

yesno: printf("Do you want to continue??\n");
       printf("1 for YES\n");
       printf("2 for NO\n");
       scanf("%d",&j);

       if(j!=1 && j!=2)
	   goto yesno;

       else if(j==1)
	   goto admenu;

       else
       {
	   printf("\n\nSIGNING OUT AS ADMIN!!\n");
	   menu(fb);
       }

       printline();
}

//****************************************************************************************************************************************************************    
//****************************************************************************************************************************************************************

//PASSENGER MENU

void pmenu(FILE *fb)
{
    int i,j,n;
    printf("\n\n");

admenu:
    printf("    PASSENGER MENU   :\n");
    printf("--------------------\n\n");
    printf("1.TICKET BOOKING\n");
   // printf("2.TICKET CANCELLATION\n");
    printf("3.BUS DETAILS\n");
    printf("4.PRINT TICKET\n");
    printf("Choose your option[1/2/3]:");
    scanf("%d",&i);

    if(i>4 || i<1)
    {
	printf("wrong option!!\n");
	goto admenu;
    }

    switch(i)
    {
	case 1: 
	       ticket_reservation(fb);

	       break;


	    /* case 2: 
	       ticket_cancellation(fb);
	       break;*/

	case 3: 
	       display_bus_list(fb);

	       break;

	case 4:
	       print_ticket();
	       break;


       default:
	       break;
    } 

yesno: printf("Do you want to continue??\n");
       printf("1 for YES\n");
       printf("2 for NO\n");
       scanf("%d",&j);

       if(j!=1 && j!=2)
	   goto yesno;

       else if(j==1)
	   goto admenu;

       else
       {
	   printf("\n\nSIGNING OUT !!\n");
	   menu(fb);
       }

       printline();


}













       //****************************************************************************************************************************************************************    
       //**************************************************************************************************************************************************************** 

       //LEAP YEAR

       int leap(date *a)
       {
	   if((a->yyyy)>0)
	   {
	       if(((a->yyyy)%100)==0)
	       {
		   if(((a->yyyy)%400)==0)


		       return 1;

		   else


		       return 0;

	       }
	       else if(((a->yyyy)%4)==0)


		   return 1;

	       else


		   return 0;

	   }
	   else 
	       return -1;

       }

       //****************************************************************************************************************************************************************    
       //****************************************************************************************************************************************************************    

       //SEARCH FUNTION WITH RESPECT TO BUS NUMBER:

       int search(FILE *fb,int bno)
       {
	   unsigned flag=0;
	   rewind(fb);
	   bus b;
	   while(fread(&b,sizeof(bus),1,fb)==1)
	   {
	       if(bno==b.bnum)
	       {
		   flag=1;
		   break;
	       }
	   }

	   return flag;
       }

       //****************************************************************************************************************************************************************    
       //****************************************************************************************************************************************************************    

       //NEW-BUS-FUNCTION

       void newbus(FILE *fb)   
       {
	   bus b;
	   int flag,i,j,k,l,q;


	   fseek(fb,0,0);

date:   printf("\n Enter the day :");
	scanf("%d",&(b.d.dd));
	printf("\n");


	printf("Enter the month :");
	scanf("%d",&(b.d.mm));
	printf("\n");

	printf("Enter the year :");
	scanf("%d",&(b.d.yyyy));
	printf("\n");


	q=leap(&(b.d));

	if(((b.d.mm)>1)&&((b.d.mm)<=3)&&(((b.d.dd)>0)&&((b.d.dd)<=31))&&((b.d.yyyy)>2019)&&(b.d.yyyy<=2020)) 
	{
	    if((b.d.mm==2)&&((b.d.dd==31)||(b.d.dd==30)))
	    {
		printf("\n WRONG INPUT!!\n");
		goto date;
	    }

	    else
		goto bnum;

	}


	else 
	{
	    printf("\n WRONG INPUT!!\n");
	    goto date;
	}	

bnum:	printf("Enter the bus no.");
	scanf("%d",&b.bnum);
	getchar();
	printf("\n");

	flag=search(fb,b.bnum);

	if(flag==1)
	{
	    printf("ALREADY EXISTING!!\n");
	    printf("Enter new number..\n");
	    goto bnum;
	}

	else
	{  
btype:	    printf("A -- A/C SLEEPER\n");
	    printf("B -- NORMAL SLEEPER\n");
	    printf("C -- NORMAL SITTING\n");
	    printf("D -- A/C SITTING\n");
	    printf("Enter bus type:");
	    scanf("%c",&b.btype);
	    getchar();
	    printf("\n");

	    /*if(b.btype!='A' && b.btype!='B' &&  b.btype!='C' && b.btype!='D')
	      {
	      goto btype;
	      }*/



bname:
	    printf("ENTER bus name :");
	    fgets(b.bname,30,stdin);
	    // getchar();
	    printf("\n");

	    for(int i=0;i<13;i++)
	    {
		for (int j=0;j<4;j++)
		{
		    b.s[i][j].p1.pid=0;
		    b.s[i][j].p1.da.dd=b.s[i][j].p1.da.mm=b.s[i][j].p1.da.yyyy=-1;
		    strcpy(b.s[i][j].p1.name,"");
		    b.s[i][j].p1.sex='#';
		    b.s[i][j].p1.age=-1;
		    strcpy(b.s[i][j].p1.source,"");
		    strcpy(b.s[i][j].p1.dest,"");
		    b.s[i][j].p1.busn=-1;
		    b.s[i][j].p1.bty='#';
		    b.s[i][j].p1.seat_no=-1;
 		    b.s[i][j].p1.arr.Hr=b.s[i][j].p1.arr.Min=b.s[i][j].p1.dep.Hr=b.s[i][j].p1.dep.Min=-1;
		   // b.s[i][j].p1.row=i;
		   // b.s[i][j].p1.col=j;
		}
	    } 


destination:
	    printf("Enter the Destination:");
	    fgets(b.to,20,stdin);
	    //getchar();
	    printf("\n");


	    printf("Enter the Source:");
	    fgets(b.from,20,stdin);
	    //getchar();
	    printf("\n");


	    if(strcmp(b.to,b.from)==0)
	    {
		printf("INVALID\n");
		goto destination;
	    }


depart:
	    printf("Enter the departure time:");
	    scanf("%d:%d",&b.depart.Hr,&b.depart.Min);
	    getchar();
	    printf("\n");

	    if(b.depart.Hr>23 || b.depart.Hr<0 || b.depart.Min>59 || b.depart.Min<0)
		goto depart;

arrival:
	    printf("Enter te arrival time:");
	    scanf("%d:%d",&b.arrival.Hr,&b.arrival.Min);
	    getchar();
	    printf("\n");

	    if(b.arrival.Hr>23 || b.arrival.Hr<0 || b.arrival.Min>59 || b.arrival.Min<0)
	    {
		printf("WRONG INPUT\n");
		goto arrival;
	    }

	    if((b.depart.Hr<b.arrival.Hr)||((b.depart.Hr==b.arrival.Hr)&&(b.depart.Min<b.arrival.Min)))
	    {
		printf("Departure time cannot be less than Arrival time\n");
		goto depart;
	    }
	    getchar();

	    if((b.depart.Hr==b.arrival.Hr)&&(b.depart.Min==b.arrival.Min))
	    {
		printf("INVALID LOGIC..\n");
		goto depart;
	    }
             
fare:
	    printf("Enter the price of a ticket:");
	    scanf("%f",&b.fare);
	    printf("\n");

	    if(b.fare<0)
		goto fare;
	    getchar();


	    b.ticket_left=52;
	    printf("Tickets available:%d\n",b.ticket_left);         

	    fwrite(&b,sizeof(bus),1,fb);

	}


       }

       //****************************************************************************************************************************************************************    
       //****************************************************************************************************************************************************************    

       //DISPLAY BUS

       void display_bus_list(FILE *fb)
       {   
	   rewind(fb);
	   bus b1;
	   fread(&b1,sizeof(b1),1,fb);
	   while(!feof(fb))
	   { 
	       printline();
	       printf("\n\t\t");
	       puts(b1.bname);
	       printf("\n");

	       printf("     DATE        :%d/%d/%d\n",b1.d.dd,b1.d.mm,b1.d.yyyy);
	       printf("    BUS NO.      : %d\n\n",b1.bnum);
	       printf("   BUS TYPE      : %c\n\n",b1.btype);
	       printf(" ARRIVAL TIME    :%d:%d\n\n",b1.arrival.Hr,b1.arrival.Min);
	       printf("DEPARTURE TIME   :%d:%d\n\n",b1.depart.Hr,b1.depart.Min);
	       printf("  DESTINATION    :");
	       puts(b1.to);
	       printf("\n");
	       printf("    SOURCE       :");
	       puts(b1.from);
	       printf("\n");
	       printf("     FARE        :%f\n\n",b1.fare);
	       printf("TICKETS AVAILABLE:%d\n\n",b1.ticket_left);
	       printline();
	       fread(&b1,sizeof(b1),1,fb);

	   }
       }

       //****************************************************************************************************************************************************************    
       //****************************************************************************************************************************************************************    

       //DELETE BUS

       void delete_bus(FILE *fb)
       {
	   bus b;
	   int num,flag;

	   FILE *f;

	   printf("Enter the bus number to be DELETED:");
	   scanf("%d",&num);
	   getchar();
	   printf("\n");

	   flag=search(fb,num);

	   if(flag==1)
	   {
	       f=fopen("TEMP.txt","wb");
	       rewind(fb);
	       while(fread(&b,sizeof(bus),1,fb)==1)
	       {
		   if(num!=b.bnum)
		       fwrite(&b,sizeof(bus),1,f);

	       }

	       fclose(fb);
	       fclose(f);

	       remove("BUS.txt");
	       rename("TEMP.txt","BUS.txt");
	       printf("\nBus No. %d DELETED!!\n",num);
	       fb=fopen("BUS.txt","rb+");
	   }
       }

       //****************************************************************************************************************************************************************    
       //**************************************************************************************************************************************************************** 

       //UPDATE BUS


       void update_bus(FILE *fb,int num,int row,int col,seat **s1)
       {
	   rewind(fb);

	   bus b;

	   while(fread(&b,sizeof(bus),1,fb)==1)
	   {
	       if(num==b.bnum)
	       {
		   b.s[row][col]=s1[row][col];
		   --b.ticket_left;
		   fseek(fb,-sizeof(bus),1);
		   fwrite(&b,sizeof(bus),1,fb);
		   break;
	       }
	   }
       }



       //****************************************************************************************************************************************************************    
       //****************************************************************************************************************************************************************    

       //MODIFY BUS

       void modify_bus(FILE *fb)
       {
	   bus b;
	   int num,flag,q;

	   printf("Enter the bus number to be modified:");
	   scanf("%d",&num);
	   getchar();
	   printf("\n");

	   flag=search(fb,num);

	   if(flag==1)
	   {
	       fseek(fb,0,0);

date:   printf("\n Enter the day :");
	scanf("%d",&(b.d.dd));
	printf("\n");
	getchar();

	printf("\n Enter the month :");
	scanf("%d",&(b.d.mm));
	printf("\n");
	getchar();

	printf("\n Enter the year :");
	scanf("%d",&(b.d.yyyy));


	q=leap(&(b.d));

	if(((b.d.mm)>1)&&((b.d.mm)<=3)&&(((b.d.dd)>0)&&((b.d.dd)<=31))&&((b.d.yyyy)>2020)) 
	{
	    if((b.d.mm==2)&&((b.d.dd==31)||(b.d.dd==30)))
	    {
		printf("\n WRONG INPUT!!\n");
		goto date;
	    }	
	}

	if(((b.d.mm)>1)&&((b.d.mm)<=3)&&(((b.d.dd)>0)&&((b.d.dd)<=31))&&((b.d.yyyy)>2020))
	{
	    goto bnum;
	}


	else 
	{
	    printf("\n WRONG INPUT!!\n");
	    goto date;
	}	

bnum:	printf("Enter the bus no.");
	scanf("%d",&b.bnum);
	getchar();
	printf("\n");

	flag=search(fb,b.bnum);

	if(flag==1)
	{
	    printf("ALREADY EXISTING!!\n");
	    printf("Enter new number..\n");
	    goto bnum;
	}
	else
	{  
	    printf("A -- A/C SLEEPER\n");
	    printf("B -- NORMAL SLEEPER\n");
	    printf("C -- NORMAL SITTING\n");
	    printf("D -- A/C SITTING\n");
	    printf("Enter bus type:");
	    scanf("%c",&b.btype);
	    getchar();
	    printf("\n");
	    printf("ENTER bus name :");
	    fgets(b.bname,30,stdin);
	    printf("\n");

	    for(int i=0;i<13;i++)
	    {
		for (int j=0;j<4;j++)
		{
		    b.s[i][j].p1.pid=0;
		    b.s[i][j].p1.da.dd=b.s[i][j].p1.da.mm=b.s[i][j].p1.da.yyyy=-1;
		    strcpy(b.s[i][j].p1.name,"");
		    b.s[i][j].p1.sex='#';
		    b.s[i][j].p1.age=-1;
		    strcpy(b.s[i][j].p1.source,"");
		    strcpy(b.s[i][j].p1.dest,"");
		    b.s[i][j].p1.busn=-1;
		    b.s[i][j].p1.bty='#';
		    b.s[i][j].p1.seat_no=-1;
		    b.s[i][j].p1.arr.Hr=b.s[i][j].p1.arr.Min=b.s[i][j].p1.dep.Hr=b.s[i][j].p1.dep.Min=-1;
		   //b.s[i][j].p1.row=i;
		   //b.s[i][j].p1.col=j;

		}
	    } 
	    getchar();


destination:
	    printf("Enter the Destination:");
	    fgets(b.to,20,stdin);
	    printf("\n");


	    printf("Enter the Source:");
	    fgets(b.from,20,stdin);
	    getchar();
	    printf("\n");

	    if(strcmp(b.to,b.from)==0)
	    {
		printf("INVALID\n");
		goto destination;
	    }


depart:
	    printf("Enter the departure time:");
	    scanf("%d:%d",&b.depart.Hr,&b.depart.Min);
	    printf("\n");

	    if(b.depart.Hr>23 || b.depart.Hr<0 || b.depart.Min>59 || b.depart.Min<0)
		goto depart;

arrival:
	    printf("Enter te arrival time:");
	    scanf("%d:%d",&b.arrival.Hr,&b.arrival.Min);
	    getchar();
	    printf("\n");

	    if(b.arrival.Hr>23 || b.arrival.Hr<0 || b.arrival.Min>59 || b.arrival.Min<0)
		goto arrival;

fare:
	    printf("Enter the price of a ticket:");
	    scanf("%f",&b.fare);
	    printf("\n");

	    if(b.fare<0)
		goto fare;


	    b.ticket_left=52;
	    printf("Tickets available:%d\n",b.ticket_left);         

	    fwrite(&b,sizeof(bus),1,fb);
	}
	   }
       }

       //****************************************************************************************************************************************************************    
       //****************************************************************************************************************************************************************    


       /*void main()
	 {
	 FILE *fb;
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

	 newbus(fb);
	 display_bus_list(fb);
	 fclose(fb);
	 }*/

       //****************************************************************************************************************************************************************    
       //****************************************************************************************************************************************************************    

       //SEARCH DATE FUNCTION

       int search_date(FILE *fb,date d1)
       {

	   unsigned flag=0;
	   rewind(fb);

	   bus b;
	   while(fread(&b,sizeof(bus),1,fb)==1)
	   {
	       if((d1.dd==b.d.dd)&&(d1.mm==b.d.mm)&&(d1.yyyy==b.d.yyyy))
	       {
		   flag=1;
		   break;
	       }
	   }

	   return flag;
       }

       //****************************************************************************************************************************************************************    
       //****************************************************************************************************************************************************************    

       //SEARCH SOURCE AND DESTINATION

       int search_place(FILE *fb,char *sou,char *des)
       {
	   unsigned flag=0;

	   rewind(fb);
	   bus b;

	   while(fread(&b,sizeof(bus),1,fb)==1)
	   {
	       if(strcmp(sou,b.from)==0)
	       {
		   if(strcmp(des,b.to)==0)
		   {
		       flag=1;
		       break;
		   }

	       }
	   }

	   return flag;
       }

       //****************************************************************************************************************************************************************    
       //****************************************************************************************************************************************************************    

       //CONVERSION OF INTEGER TO STRING

       char *itoa(unsigned long int a)
       {
	   char *s;
	   int i=-1;
	   unsigned long int t=a;
	   while(t!=0)
	   {
	       t=t/10;
	       i++;
	   }
	   if(i==-1)
	   {
	       s=(char *)malloc(2);
	       s[0]='0';
	       s[1]='\0';
	       return s;
	   }
	   s=(char*)malloc(i);
	   while(a!=0)
	   {
	       t=a%10;
	       a=a/10;
	       s[i]=t+48;
	       i--;
	   }
	   return s;
       }


       //*****************************************************************************************************************************************************************    
       //*****************************************************************************************************************************************************************

       // FUNCTION FOR WHETHER THE SEAT NUMBER SPECIFIED IN THE BUS IS FREE OR NOT    

       int check_seat_free(bus b,int ro,int co)
       {
	   return b.s[ro][co].p1.busn==-1;
       }



       //****************************************************************************************************************************************************************    
       //*************************************************************************************************************************************************************** 

       //CALCULATING THE BOOKING CHARGES

       void bill(float p,int n)
       {

	   float price;

	   price=p*n;

	   printf("The GRAND TOTAL for booking %d tickets:  %f\n",n,price);

       }

       //****************************************************************************************************************************************************************    
       //***************************************************************************************************************************************************************  

       //TICKET RESERVATION

       void ticket_reservation(FILE *fb)
       {
	   int fl1,fl2,marker,busno,row,col,n,flag,q,ra;
	   float price;

	   char sou[20],des[20];

	   FILE *f,*temp;

	   bus b;
	   date d;

	   rewind(fb);


date:
	   printf("\n Enter the day :");
	   scanf("%d",&(d.dd));
	   printf("\n");
	   getchar();

	   printf("\n Enter the month :");
	   scanf("%d",&(d.mm));
	   printf("\n");
	   getchar();

	   printf("\n Enter the year :");
	   scanf("%d",&(d.yyyy));

	   q=leap(&d);

	   if(((d.mm)>1)&&((d.mm)<=3)&&(((d.dd)>0)&&((d.dd)<=31))&&((d.yyyy)>=2020)) 
	   {
	       if((d.mm==2)&&((d.dd==31)||(d.dd==30)))
	       {
		   printf("\n WRONG INPUT!!\n");
		   goto date;
	       }	
	   }

	   if(((d.mm)>1)&&((d.mm)<=3)&&(((d.dd)>0)&&((d.dd)<=31))&&((d.yyyy)>=2020))
	   {
	       goto dest;
	   }

	   else 
	   {
	       printf("\n WRONG INPUT!!\n");
	       goto date;

	   }	

dest:
	  // getchar();
	   printf("Enter the place of destination:");
 	   getchar();
	   fgets(des,20,stdin);
	   printf("\n");

	   printf("Enter the Source:");
	   fgets(sou,20,stdin);
	   getchar();
	   printf("\n");

	   if(strcmp(sou,des)==0)
	   {
	       printf("INVALID\n");
	       goto dest;
	   }

	   fl1=search_date(fb,d);
	   fl2=search_place(fb,sou,des);

	   if(fl1==0 && fl2==0 )
	   {
	       printf("No Buses available on %d/%d/%d  to ",d.dd,d.mm,d.yyyy);
	       printf("%s\n",des);
	       marker=0;
	   }

	   if(fl1==0 && fl2==1)
	   {
	       printf("Buses are available to ");
	       printf("%s",des);
	       printf(" but not on %d/%d/%d.\n",d.dd,d.mm,d.yyyy);
	       marker=1;
	   }

	   if(fl1==1 && fl2==0)
	   {
	       printf("Buses are not available to ");
	       printf("%s",des);
	       printf("\n");
	       marker=3;
	   }

	   if(fl1==1 && fl2==1)
	   {
	       temp=fopen("temp.txt","rb+");
	       if(temp==NULL)
	       {
		   temp=fopen("temp.txt","wb+");
		   if(temp==NULL)
		   {
		       printf("Error\n");
		       exit(0);
		   }
	       }

	       rewind(fb);

	       while(fread(&b,sizeof(bus),1,fb))
	       {

		   if((d.dd==b.d.dd)&&(d.mm=b.d.mm)&&(d.yyyy==b.d.yyyy))
		   {
		       if(strcmp(sou,b.from)==0)
		       {
			   if(strcmp(des,b.to)==0)
			   {
			       fwrite(&b,sizeof(bus),1,temp);
			   }
		       }
		   }
	       }

	       display_bus_list(temp);

	       printf("Choose your bus...\n");
	       printf("Enter the bus number:");
	       scanf("%d",&busno);

	       rewind(fb);

	       while(fread(&b,sizeof(bus),1,fb)==1)
	       {
		   if(b.bnum==busno)
		   {


			 printf("Enter the number of tickets to be booked:");
		         scanf("%d",&n);

		 	 price=b.fare;

		 // for(int i=1;i<=n;i++)

		 //{
		 //if(i==1)       
		       int i=1;
		 do

		 {
		    // srand((int)&ra);
row:		  printf("Enter the row number:");
		  scanf("%d",&row);

		  if(row>12 || row<0)
		  {
		     printf("invalid\n");
		     goto row;
		  }

column:		  printf("Enter the column number:");
		  scanf("%d",&col);

		  if(col>3 || col<0)
		  {
		     printf("invalid\n");
		     goto column;
		  }

		 flag=check_seat_free(b,row,col);

		 if(flag==0)
		 {
		     printf("Seat is not free\n");
		     printf("Choose another seat..\n");
		     goto row;
		 }

		     b.s[row][col].p1.pid=rand();

		   

		     printf("Enter the name of the passenger:");
		     getchar();
		     fgets(b.s[row][col].p1.name,50,stdin);
		     printf("\n");

		     printf("Enter the sex of the passenger:");
		     scanf("%c",&(b.s[row][col].p1.sex));
		     getchar();
		     printf("\n");

		     printf("Enter the age of the passenger:");
		     scanf("%d",&(b.s[row][col].p1.age));
		     getchar();
		     printf("\n");

		     strcpy(b.s[row][col].p1.source,b.from);
		     strcpy(b.s[row][col].p1.dest,b.to);

		     (b.s[row][col].p1.da.dd)=(b.d.dd);
		     (b.s[row][col].p1.da.mm)=(b.d.mm);
		     (b.s[row][col].p1.da.yyyy)=(b.d.yyyy);

		     (b.s[row][col].p1.busn)=(b.bnum);
		     (b.s[row][col].p1.bty)=(b.btype);
		     (b.s[row][col].p1.arr.Hr)=(b.arrival.Hr);
		     (b.s[row][col].p1.arr.Min)=(b.arrival.Min);
		     (b.s[row][col].p1.dep.Hr)=(b.depart.Hr);
 		     (b.s[row][col].p1.dep.Min)=(b.depart.Min);
		    
		    

		     switch(row)
		     {
			 case 0:
			     b.s[row][col].p1.seat_no=row+col+1;
			     break;

			 case 1:
			     b.s[row][col].p1.seat_no=row+col+4;
			     break;
			 case 2:
			     b.s[row][col].p1.seat_no=row+col+7;
			     break;
			 case 3:
			     b.s[row][col].p1.seat_no=row+col+10;
			     break;
			 case 4:
			     b.s[row][col].p1.seat_no=row+col+13;
			     break;

			 case 5:
			     b.s[row][col].p1.seat_no=row+col+16;
			     break;

			 case 6:
			     b.s[row][col].p1.seat_no=row+col+19;
			     break;
			 case 7:
			     b.s[row][col].p1.seat_no=row+col+22;
			     break;
			 case 8:
			     b.s[row][col].p1.seat_no=row+col+25;
			     break;
			 case 9:
			     b.s[row][col].p1.seat_no=row+col+28;
			     break;
			 case 10:
			     b.s[row][col].p1.seat_no=row+col+31;
			     break;
			 case 11:
			     b.s[row][col].p1.seat_no=row+col+34;
			     break;
			 case 12:
			     b.s[row][col].p1.seat_no=row+col+37;
			     break;
		     }
		     fseek(fb,-sizeof(bus),1);
		     fwrite(&b,sizeof(bus),1,fb);

                  
		     int le1;
		     le1=strlen(b.s[row][col].p1.name);

		     (b.s[row][col].p1.pid)=(b.s[row][col].p1.pid)+(b.s[row][col].p1.age)+(b.s[row][col].p1.busn*10000)+le1+(row*100)+col;

		     printf("Your passenger ID is :%lu",b.s[row][col].p1.pid);
		     printf("\n");

		     FILE *pas;

		     char s[40]="./Passenger_log/";

		     strcat(s,itoa(b.s[row][col].p1.pid));

		     pas=fopen(s,"rb+");
		     if(pas==NULL)
		     {
			 pas=fopen(s,"wb+");

			 if(pas==NULL)
			 {
			     printf("Error in opening the file\n");
			     exit(0);
			 }

		     }

		     fseek(pas,0,0);
		     fwrite(&b.s[row][col].p1,sizeof(pass),1,pas);
		     fclose(pas);
		     i++;


		     // update_bus(fb,b.bnum,row,col,b.s);



		 }while(i<=n);


	   bill(price,n);

	   printf("Your booking has been confirmed!!\n");
	   printf("Thanks for choosing our services\n");
	   printf("Have a GOOD & SAFE JOURNEY!!\n");

		   }
		   }


	       }
	   


	   exit(0);

       }



       //****************************************************************************************************************************************************************    
       //***************************************************************************************************************************************************************  

       //DISPLAY PASSENGER LIST

       void display_passenger_list(FILE *fb)
       {
	   bus b;

	   while(fread(&b,sizeof(bus),1,fb)==1)
	   {
	       for(int i=0;i<13;i++)
	       {
		   for(int j=0;((j<4)&&(b.s[i][j].p1.seat_no!=-1));j++)

		   {


		       printf(" DATE OF JOURNEY : %d/%d/%d\n",b.s[i][j].p1.da.dd,b.s[i][j].p1.da.mm,b.s[i][j].p1.da.yyyy);
		       getchar();
		       printf("      NAME        :");
		       puts(b.s[i][j].p1.name);
		       getchar();
		       printf("\n");

		       printf("      AGE         :%d\n",b.s[i][j].p1.age);
		       getchar();
		       printf("      SEX         :%c\n",b.s[i][j].p1.sex);
		       getchar();
		       printf("   BUS NUMBER     :%d\n",b.s[i][j].p1.busn);
		       getchar();
		       printline();

		   }
	       }
	   }
       }

       //****************************************************************************************************************************************************************    
       //***************************************************************************************************************************************************************  

       //PRINT TICKET

       void print_ticket()
       {  
	   pass p;

	   long int passid;
	   int a;
	   FILE *pas;
	   char s[40]="./Passenger_log/";

	   printf("Enter the passenger ID :");
	   scanf("%lu",&passid);

	   strcat(s,itoa(passid));

	   pas=fopen(s,"rb+");

	   while(!feof(pas))
	   {

	       printf(" _________________________________________________________________________________\n");
	       printf("|				      						|\n");
	       printf("|                                BUS TICKET                                      |\n");
	       printf("|                                                                                |\n");
	       printf("|            DATE    : %d/%d/%d                                                  |\n",p.da.dd,p.da.mm,p.da.yyyy);
	       printf("|                                                                                |\n");
	       printf("|        BUS NUMBER  :  %d                                            		|\n",p.busn);
	       printf("|                           		                                        |\n");
	       printf("|    PASSENGER NUMBER:  %lu  				                        |\n",p.pid);
	       printf("|                                                                                |\n");
	       printf("|    PASSENGER NAME  :  %s          			    		        |\n",p.name);
	       printf("|           AGE      :  %d                                                       |\n",p.age);
	       printf("|                                                                                |\n");
	       printf("|          SEX       :  %c                                                       |\n",p.sex);
	       printf("|                                                                                |\n");
	       printf("|       ARRIVAL TIME : %d:%d                                                     |\n",p.arr.Hr,p.arr.Min);
	       printf("|     DEPARTURE TIME : %d:%d                                                     |\n",p.dep.Hr,p.dep.Min);
	       printf("|                                                                                |\n");
	       printf("|      SEAT  NUMBER  : %d                                                        |\n",p.seat_no);
	       printf("|                                                       	                        |\n");
	       printf("|           HAVE      A     SAFE       AND     HAPPY        JOURNEY!!            |\n");
	       printf("|                                                                                |\n");
	       printf("|________________________________________________________________________________|\n");
	       printline();
	   }


       }











