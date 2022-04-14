#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define numberOfSeats 18

struct ReservationModel
{
   int seatNumber;
   char firstName[20];
   char lastName[20];
   char password[20];
}; 
typedef enum { false, true } bool;
struct ReservationModel reservations[numberOfSeats];

// function declaration
int passval(const char pw[]);
void displayAvailableSeats(int *seats);
void viewAllReservations(struct ReservationModel reservations[]);
void viewMyReservation(char password[],struct ReservationModel reservations[]);
struct ReservationModel enterPersonalInformation(int *seats);
struct ReservationModel selectSeat(int *seats,struct ReservationModel);
bool checkValidity(struct ReservationModel model);


int main() {
	int userSelection;
	int seats[numberOfSeats];
	int reservationsNum = 0;
	
	int i;
	for(i = 0;i<numberOfSeats;i++){
		seats[i] = i+1;
	}
	
	printf("Seat Reservation System (Console Application)\n");
	
	do {
   		printf("\n***********Main Menu**************\n");
   		printf("1 - View available seats\n");
   		printf("2 - Reserve a seat\n");
   		printf("3 - View my reservation\n");
   		printf("4 - View all reservations\n");
   		printf("0 - Quit\n\nSelect Your Option: ");

   		scanf("%d", &userSelection);
   		
   		switch(userSelection){
			case 0:
				break;
			case 1:
				displayAvailableSeats(seats);
				break;
			case 2:
				;
				struct ReservationModel m;			
				 m= enterPersonalInformation(seats);		
				if(m.seatNumber == 0){
					userSelection = 0;
					break;
				}else if(m.seatNumber < 0){
					userSelection = 10;
					break;
				}else{
					reservations[reservationsNum] = m;
					reservationsNum++;
				}
				//reservationModel = enterPersonalInformation(seats);
				break;
			case 3:
				printf("Input you reservation password: ");
				char passInput[20];
				scanf("%s",&passInput);
				viewMyReservation(passInput,reservations);
				break;
			case 4:
				viewAllReservations(reservations);
				break;
			default:
				printf("Invalid Input, Select a valid option");
				break;
		}
   		
	} while(userSelection != 0);
	
	return 0;
}

void displayAvailableSeats(int *seats){
	int i;
	for(i = 0;i<numberOfSeats;i++){
		if(seats[i] != 0){
			printf("Seat %d is available\n",seats[i]);
		}
	}
}


struct ReservationModel selectSeat(int *seats,struct ReservationModel model){
	printf("Select a seat\n\n");
	displayAvailableSeats(seats);
	
	bool found = false;
	printf("Input a seat number or Input 0 to exit: ");
	scanf("%d",&model.seatNumber);
	int i ;
	 for (i = 0; i < numberOfSeats; i++) {
        if (seats[i] == model.seatNumber) {
            seats[i] = 0;
        }        
        
        if (model.seatNumber == seats[i]) {
            found = true;
        }
    }

    if (found) {
        model.seatNumber = -1;
    }

    return model;
}

bool checkValidity(struct ReservationModel model){
	if(strcmp(model.firstName,"") == 0){
		printf("Invalid Name! \n");
		return false;
	}else if(strcmp(model.lastName,"") == 0){
		printf("Invalid Name!\n");
		return false;
	}else if(passval(model.password) == 0){
		printf("Invalid Password password must contain Upper case letters, Lower case letters, Special symbols, Numbers !\n\n");
		return false;
	}else{

	
	return true;	}
}

int passval(const char pw[])
{
    size_t x;
    unsigned char c; /* making this unsigned is important:
        char may be negative and passing it to isupper(), etc. may invoke undefined behavior */
    int upperExists = 0, lowerExists = 0, numberExists = 0;

    for (x = 0; pw[x] != '\0'; x++) {
        /* fetch the character */
        c = pw[x];
        /* raise flags when the character is required kind */
        upperExists = upperExists || isupper(c);
        lowerExists = lowerExists || islower(c);
        numberExists = numberExists || isdigit(c);
    }

    /* check if all of required flags are raised */
    return upperExists && lowerExists && numberExists;
}

struct ReservationModel enterPersonalInformation(int *seats){
	struct ReservationModel model;

	
		do{
			
			printf("Enter Your First Name: ");
			scanf("%s",&model.firstName);
			printf("Enter Your Last Name: ");
			scanf("%s",&model.lastName);
			printf("Enter Your Password: ");
			scanf("%s",&model.password);
					
		}while(!checkValidity(model));
	
	return selectSeat(seats,model);
}


void viewAllReservations(struct ReservationModel reservations[]){
	int i;
	printf("All reservations\n");
	bool entered;
	entered= false;
		printf("S/N      First Name    Last Name    SeatNumber\n");
		 
	for (i = 0; i < numberOfSeats; i++) {
		if(reservations[i].seatNumber){
			entered = true;
			printf("%d       %s            %s            %d\n",i+1,reservations[i].firstName,reservations[i].lastName,reservations[i].seatNumber);
        
		}
	          
    }
    	if(!entered){
			printf("No reservations\n");
           
		} 

        //System.out.println(reservationModels.size() + " Reservation(s) available");
}

void viewMyReservation(char password[],struct ReservationModel reservations[]){
	 bool found = false;
	 int i;
	
    for (i = 0; i < numberOfSeats; i++) {
        if (strcmp(password, reservations[i].password) == 0) {
            printf("Your reservation\n");
           	printf("%s %s\n",reservations[i].firstName,reservations[i].lastName);
        	printf("Reserved Seat number %d\n",reservations[i].seatNumber);
        	
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Reservation with such password not found!!\n");
    }	
}
