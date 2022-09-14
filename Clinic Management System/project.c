/*
                                     Clinic Management System
                          
                          Created By : Abdelrahman Adam 

                          Description : Clinic Management System using Linked List

                            GitHub    : https://github.com/adm201168/C---Codes.git
                            
                            E-Mail    : adm201168@gmail.com
*/

#include"STD_TYPE.h"
#include<stdlib.h>
#include<stdio.h>
typedef struct patient data;
 struct patient 
{
    u8 name[50]; 
    u8 age;
    u8 gender[30];
    u16 ID;
    u8 Res;
    data *next;
};
u8 flag=0;  
data *head=NULL;
 data *ptr=NULL;
 data *ID_found=NULL;
 u8 slots[][60]={"2pm to 2:30pm", "2:30pm to 3pm" ,"3pm to 3:30pm" ,"4pm to 4:30pm" ,"4:30pm to 5pm"};
 u8 check_slot[5]={0};
u8 i,ch;
u16 id;
void admin_mode();              //To Enter The Admin Mode
void user_mode();               //To Enter The User Mode
void add (u16 id1);             //To Add New Patient Record
void edit (u16 id1);           //To Edit Patient Record
void reservation(u16 id1);     //To Book a Date
void cancel_res(u16 id1);      //To Cancel The Booking
void all_res();                //To Display All Resevations
void display_info(u16 id1);    //To Display The Patient Information
data *check_ID(u16 id1);       //To check if The ID Exicting


void main()
{
    u16 passw;
    for(;;)
    {
        
    printf("\nPlease Enter The Mode :\n\n\n\t\t1-Admin Mode\n\n\t\t2-User Mode\n\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
    printf("\nPlease enter The Password :  ");
    scanf("%d",&passw);
    for(i=0 ; i<2 ; i++){
    if(passw == 1234 )
    {
        admin_mode();
        break;
    }
    else
    { 
        printf("\n Wrong Password\n");
        printf("\nPlease enter The Password Correctly :  ");
        scanf("%d",&passw);
    }
    }
    break;

    case 2:
    user_mode();
    break;
    
    default:
        printf("\nWrong Choice\n");
        break;
    }
}}

      /*Functions*/
   //////////////////

 /*Admin Mode Function*/
void admin_mode()
{
    
    printf("\n\n\t\tPlease Enter the correct Number \n\t\t1. Add new patient record:\n\t\t2. Edit patient record\n\t\t3. Reserve a slot with the doctor\n\t\t4. Cancel reservation\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:            //Add new patient
    printf("\nPlease enter the ID :  ");
    scanf("%d",&id);
    getchar();
    add(id);
    break;

    case 2:           //Edit patient record
    printf("\nPlease enter the ID :  ");
    scanf("%d",&id);
    getchar();
    edit(id);
    break;
    
    case 3:           //Reserve a slot with the doctor
    printf("\nPlease enter the ID :  ");
    scanf("%d",&id);
    reservation(id);
    break;
    case 4:          //Cancel reservation
    printf("\nPlease enter the ID :  ");
    scanf("%d",&id);
    cancel_res(id);
    break;
    default:
        printf("\nWrong Choice\n");
        break;
    }
}
/*End of Admin mode function*/
//////////////////////////////

/*User mode function*/
void user_mode()
{
    printf("\n\n\t\tPlease Enter the correct Number \n\t\t1. View patient record\n\t\t2. View Todays Reservations\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:         //View patient record
    printf("\nPlease enter the ID :  ");
    scanf("%d",&id);
        display_info(id);
    break;

    case 2:          //View Todays Reservations
    all_res();
    break;

    default:
        printf("\nWrong Choice\n");
        break;
    }
}
/*End of User mode function*/


/*Add patient Function*/
void add (u16 id1)
{         
      if(check_ID(id1) != 0)     //to check if the ID already exist
      {
        printf("\n\tThe ID Already Exist\n\n");
      }
else{
 data *temp=(data*)malloc( sizeof(data));
printf("\n\tplease Enter The patient Name :   ");
fgets(temp->name ,50 ,stdin);
printf("\n\tplease Enter The patient Age  :   ");
scanf("%d",&temp->age);
printf("\n\tplease Enter The patient Gender Male(M) or Female(F) :   ");
scanf("%s",temp->gender);
temp->ID = id1;
temp->Res=5;
temp->next=head;    //point it to old first node
head=temp;          //point first to new first node
}}
/*END of Add patient Function*/
///////////////////////////////

/*Edit patient Information Function*/
void edit (u16 id1)
{
     
      if(check_ID(id1) != 0)
      {
         ptr=check_ID(id1);  
       printf("\n\tplease Enter The patient Name :   ");
       fgets(ptr->name ,50 ,stdin);
       printf("\n\tplease Enter The patient Age  :   ");
       scanf("%d",&ptr->age);
       printf("\n\tplease Enter The patient Gender Male(M) or Female(F) :   ");
       scanf("%s",ptr->gender);
      }
else{
    printf("\n\tThe ID Incorrect\n\n");
    }
}
/*END of Edit patient Information Function*/
////////////////////////////////////////////

/*Check ID function*/
data *check_ID(u16 id1)
{
 data *search_id = head; //to check if the ID exist
    while(search_id != NULL) {        
      if(search_id->ID==id1)
      {
        return search_id;   //the id is found
      }
      search_id = search_id->next;
    }
    return 0; //the id is not found
}
/*End of Check ID function*/
////////////////////////////

/*Reservation Function*/
 void reservation(u16 id1)
 {
    u8 res_in;  
  flag=0;
  ID_found=check_ID(id1);
if ( check_ID(id1) == 0)
{
    printf("\n\tThe ID Incorrect\n\n");
}
else if (ID_found->Res != 5)
{
printf("\n\tThe ID Already has Reservation ");
}
else
{
for(i=0 ; i<5 ; i++)
{
    if(check_slot[i]==0)
    {
        printf("\n\t To Select %s Date Enter %d",slots[i],i+1);
        flag++;
    }
}
if(flag==0)
{
    printf("\n\n There is NO Available Slots ");
}
else
{
    flag=0;
    printf("\n Enter The Desired Slot Number : \n");
    scanf("%d",&res_in);
    if (res_in>=1 && res_in<=5)
    {
        for(i=0 ; i<5 ; i++)
        {
            if(check_slot[i]==res_in-1) 
            {
            flag++;
             break; 
            }
        }
        if(flag==0){
        ID_found->Res =res_in-1;
        check_slot[res_in-1]=1;
        printf("\n\t DONE , Thank you..");
        }
        else printf("\n\t Incorrect !! ");          //in case entered a number between 1 and 5 but it already reserved
    }
    else printf("\n\t Incorrect !! ");             //in case entered a number outside 1 and 5
}}}
/*END of reservation*/
//////////////////////

/*Cancel Reservation Function*/
void cancel_res(u16 id1)
{
    u8 res_in;
  ptr=head;   
 ID_found=check_ID(id1);
if ( ID_found == 0)
{
    printf("\n\tThe ID Incorrect\n\n");
}
else
{
    check_slot[ID_found->Res]=0;
    ID_found->Res=5;
     printf("\n\t DONE , Thank you..");
} }
/*END od Cancel Reservation Function*/
//////////////////////////////////////

/*Display Information function*/
void display_info(u16 id1)
{
ptr=head;  
 ID_found=check_ID(id1); 
if (ID_found == 0)
{
    printf("\n\tThe ID Incorrect\n\n");
}
else
{
    getchar();
    printf("\n\tName : %s",ID_found->name);
    printf("\n\tAge : %d",ID_found->age);
    printf("\n\tGender : %s",ID_found->gender);
    if(ID_found->Res == 5)
    {
        printf("\n\tReservation Date is : NO Dates ");
    }
    else printf("\n\tReservation Date is : %s",slots[ID_found->Res]);
}}
/*END of Display Information function*/
///////////////////////////////////////

/*Display All reservation Function*/
void all_res()
{
    flag=0;
    ptr=head;
    i=1;
    while (ptr!=NULL)
    {
       if(ptr->Res != 5)
    {
       printf("\n\t%d. The ID : %d has a Reservation at %s \n",i,ptr->ID,slots[ptr->Res]); 
       flag++;    
       i++;
    }
    ptr=ptr->next;
    }
    if(flag==0)
    printf("\n No Reservation Dates Until Now\n");
}
/*END of Display all reservations*/
///////////////////////////////////

