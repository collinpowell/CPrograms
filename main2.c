#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define numberOfSeats 18
#define credentials 4

#define seatNumber 0
#define firstName 1
#define lastName 2
#define password 3

typedef enum { false, true } bool;

void displayAvailableSeats(int *seats);
void viewAllReservations(char ***reservations);
//void viewMyReservation(char password[],char reservations[][][]);
//struct ReservationModel enterPersonalInformation(int *seats);
//struct ReservationModel selectSeat(int *seats,char reservations[][][]);
//bool checkValidity(struct ReservationModel model);

int main(){
	char reservations[numberOfSeats][credentials][20];
	
	int i,j,k;
	for(i=0;i<numberOfSeats;i++){
		for(j=0;j<credentials;j++){
			strcpy(reservations[i][j], "Jump");
		}
	}
	
	viewAllReservations(reservations);
}

void displayAvailableSeats(int *seats){
	int i;
	for(i = 0;i<numberOfSeats;i++){
		if(seats[i] != 0){
			printf("Seat %d is available\n",seats[i]);
		}
	}
}


void viewAllReservations(char ***reservations){
	int i;
	printf("All reservations\n");
	bool entered;
	entered= false;
	printf("S/N      First Name    Last Name    SeatNumber\n");
	char values[20];
	for (i = 0; i < numberOfSeats; i++) {
		//strcpy(values, reservations[i][seatNumber]);

		if(values){
			entered = true;
			//printf("%s", values);
			//printf("%s       %s            %s            %s\n",i+1,reservations[i][firstName],reservations[i][lastName],reservations[i][seatNumber]);
		}	
	          
    }
	if(!entered){
		printf("No reservations\n");
       
	} 
}
