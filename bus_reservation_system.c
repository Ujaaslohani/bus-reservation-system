#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SEAT 50
#define MAX_NAME 50
#define BUS_NO 5
struct Details
{
char firstname[MAX_NAME];
char lastname[MAX_NAME];
char phNo[10];
int Booked;
} Bus[BUS_NO][MAX_SEAT];
void NewBooking(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, 
int bustype);
void seatInquiry(struct Details Buses[BUS_NO][MAX_SEAT], int bustype);
void seatInfo(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, int
bustype);
void cancelSeat(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, 
int bustype);
// Function to check if phone number is valid or not.
int check_phone(char str[])
{
if (strlen(str) != 10)
{
return 0;
}
else
{
int i;
for (i = 0; i < 10; i++)
{
if (str[i] < '0' || str[i] > '9')
{
return 0;
}
}
return 1;
}
}

// Function to check if Name is valid or not.
int check_name(char *str)
{
int i;
for (i = 0; i < strlen(str); i++)
{
if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 
'Z'))
{
continue;
}
else
{
return 0;
}
}
return 1;
}
// Function to reserve a new seat.
void NewBooking(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, 
int bustype)
{
int i, seat;
system("cls");
if (Buses[bustype][seatNumber].Booked == 1)
{
system("cls");
 printf("This seat is already booked by %s %s\n",
Buses[bustype][seatNumber].firstname, 
Buses[bustype][seatNumber].lastname);
printf("Do you want to book another seat (Y/N): ");
char ans;
scanf("%s", &ans);
if (ans == 'Y' || ans == 'y')
{
printf("Enter Seat Number : ");
scanf("%d", &seat);
NewBooking(Bus, seat, bustype);
}
}
else
{

Buses[bustype][seatNumber].Booked = 1;
printf("Enter your first name : ");
while (1)
{
int valid_first_name;
scanf("%s", &Buses[bustype][seatNumber].firstname);
valid_first_name = check_name(Buses[bustype][seatNumber]
.firstname);
if (valid_first_name == 1)
{
break;
}
else
{
printf("First name is invalid!!\n\nPlease enter a valid first name: ");
}
}
printf("Enter yout last name : ");
while (1)
{
int valid_last_name;
scanf("%s", &Buses[bustype][seatNumber].lastname);
valid_last_name = check_name(Buses[bustype][seatNumber]
.lastname);
if (valid_last_name == 1)
{
break;
}
else
{
printf("Last name is invalid!!\n\nPlease enter a valid last name: ");
}
}
printf("Enter Passenger Phone Number : ");
while (1)
{
int valid_phone;
scanf("%10s", &Buses[bustype][seatNumber].phNo);

valid_phone = check_phone(Buses[bustype][seatNumber].phNo);
if (valid_phone == 1)
{
break;
}
else
{
printf("Invalid Phone Nmber!!\n\nPlease enter a valid  Phone Number: ");
}
}
system("cls");
printf("\nDear\n %s %s Your ticket has been successfully booked...\n The Ticket is Booked for the selected seat number of the selected bus \n*** Happy Journey ***\n", 
 Buses[bustype][seatNumber].firstname, 
 Buses[bustype][seatNumber].lastname);
}
}
// Function to know about seat vacancies.
void seatInquiry(struct Details Buses[BUS_NO][MAX_SEAT], int bustype)
{
int i;
system("cls");
printf("Vacant Seats : \n");
for (i = 0; i < 50; i++)
{
if (Buses[bustype][i].Booked != 1)
{
printf("%d ", i + 1);
}
}
printf("\n");
printf("Already Booked Seats : \n");
for (i = 0; i < 50; i++)
{
if (Buses[bustype][i].Booked == 1)
{
printf("%d ", i + 1);
}
}
}

// Function to check if seat is reserved or not.
void seatInfo(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, int
bustype)
{
system("cls");
if (Buses[bustype][seatNumber].Booked == 1)
{
printf("Entered Seat Number %d of selected Bus is already BOOKED", seatNumber + 1);
}
else
{
printf("Entered Seat Number %d of selected Bus is available!!!\n", 
seatNumber + 1);
printf("Do you want to Book ? (Y/N): ");
char ans2;
scanf("%s", &ans2);
if (ans2 == 'Y' || ans2 == 'y')
{
NewBooking(Bus, seatNumber, bustype);
}
}
}
// Function to cancel the reserved seat.
void cancelSeat(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, 
int bustype)
{
if (Buses[bustype][seatNumber].Booked != 1)
{
system("cls");
printf("This seat is not booked yet!!!");
}
else
{
Buses[bustype][seatNumber].Booked = 0;
Buses[bustype][seatNumber].firstname == NULL;
Buses[bustype][seatNumber].lastname == NULL;
system("cls");
printf("** Ticket Cancellation Successfull ***\n");
printf("* Thank You, Visit Again * \n");
}
}

// The Main Function
int main()
{
int seatNumber, bustype, userid, pass;
int choice;
system("cls");
start:
printf("\n\n\n \t\t***Enter the USERID and PASSWORD to access the BUS RESERVATION SYSTEM*** \n");
printf("\n\n\t\t USERID : ");
scanf("%d", &userid);
printf("\n\t\t PASSWORD : ");
scanf("%d", &pass);
system("cls");
if (userid == 124628 && pass == 9999)
{
while (choice != 5)
{
printf("\n\n** Welcome to Bus reservation system **");
printf("\n\n1. New Booking \n2. Knowing vacancies \n3. Ticket Information \n4. Cancel your ticket \n5. Exit");
printf("\n\nWhat do you want?? Choose (1-5): ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("\n\nFor New Registration.....\n");
printf("Choose Bus type :\n1. BUS_AC-1\t2. BUS_AC2\t3.BUS_LOCAL-1\t4. BUS_LOCAL-2\t5. BUS_SLEEPER\n");
scanf("%d", &bustype);
bustype = bustype - 1;
printf("Enter Seat Number (1-50): ");
scanf("%d", &seatNumber);
seatNumber = seatNumber - 1;
NewBooking(Bus, seatNumber, bustype);
break;
case 2:

printf("Choose Bus type :\n1. BUS_AC-1\t2. BUS_AC2\t3.BUS_LOCAL-1\t4. BUS_LOCAL-2\t5. BUS_SLEEPER\n");
scanf("%d", &bustype);
bustype = bustype - 1;
seatInquiry(Bus, bustype);
break;
case 3:
printf("For Seat Inquiry...\n");
printf("Choose Bus type :\n1. BUS_AC-1\t2. BUS_AC2\t3.BUS_LOCAL-1\t4. BUS_LOCAL-2\t5. BUS_SLEEPER\n");
scanf("%d", &bustype);
bustype = bustype - 1;
printf("Enter Seat Number (1-50) : ");
scanf("%d", &seatNumber);
seatNumber = seatNumber - 1;
seatInfo(Bus, seatNumber, bustype);
break;
case 4:
printf("For Cancelling reservation...\n");
printf("Choose Bus type :\n1. BUS_AC-1\t2. BUS_AC2\t3.BUS_LOCAL-1\t4. BUS_LOCAL-2\t5. BUS_SLEEPER\n");
scanf("%d", &bustype);
bustype = bustype - 1;
printf("Enter Seat Number (1-50) : ");
scanf("%d", &seatNumber);
seatNumber = seatNumber - 1;
cancelSeat(Bus, seatNumber, bustype);
break;
default:
printf("Program closed by User.");
break;
}
}
}
else
{
printf("USERID or PASSWORD is Incorrect.\n TRY AGAIN!!\n");
goto start;
}
return 0;
}