/*
Student name: Matthew Hall
PantherID: 6327302
Date: 9/11/2022
Class: COP4338

I affirm that I wrote this program myself without any help from any other people or sources from the internet.
This program is solely my work and no one elses.

Program Discription:

This program called "planeseats" is designed to assign plane seats to users that request them.
Their are four first class ticket and 8 economy. Upon request the program will assign you a ticket
is the specified area, unless thhe seats are sold out. At which it will prompt you to answer whether 
you would like to be assigned to a different section.

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
This variable assigns a constant value to the number of available seats,
it is used to constuct the boolean array.
*/
const int numOfSeats = 12;

/*
This function I created is checked after each iteration of the while loop, to see
if all of the plane seats have been filled. The function is called at the end 
of the while loop, and iterates through the boolean array. Each time a seat is purchased,
the index for the seat is set to true.
*/
int openSeats (const bool planeSeats[numOfSeats]) {
    int seatOpen = 0;
    for (int i = 0; i < numOfSeats; i++) {
        if (planeSeats[i] == false) {
            ++seatOpen;
        }
    }
    if (seatOpen > 0) {
        return true;
    } else {
        return false;
    }
}


int main() {

    bool planeSeats[numOfSeats]; //creation of the boolean array
    int userSelection; //user selection 1, 2, or 3 each number is assigned with a different result
    char seatsOutUserSelection[3]; //char array for users response "yes" or "no"
    int firstClassSeats = 4; 
    int economySeats = 8; 
    for (int i = 0; i < numOfSeats; i++) {
        planeSeats[i] = false; //this creates the boolean array of false values, meaning empty seats
    }   

    bool areSeatsOpen = openSeats(planeSeats); //intialization of the funtion call to the boolean value

    while (areSeatsOpen == true) {
        printf("Please type 1 for \"first class\"\nPlease type 2 for \"economy\"\nPlease type 0 to quit\n");
        printf("Enter Selection: ");
        scanf("%d", &userSelection); //scans users input for seat selection or quit

        /*
            The logic below checks for first class or 1, if there are available seats then
            it will assign them to it and print a boarding pass. If the seats are sold out, but
            some are still available in economy then it will ask the user "yes" or "no". If
            "yes" it will assign the user to a seat in economy, and if "no" then it will end
            the program and return 0.
        */        
        if (userSelection == 1) {
            if (firstClassSeats > 0) {
                firstClassSeats -= 1;
                planeSeats[firstClassSeats] = true;
                printf("\nYou are assigned seat %d in first class. Enjoy your flight. \n\n", firstClassSeats + 1);
            } else if ((firstClassSeats == 0) && (economySeats != 0)) {
                printf("\nCurrently there are no more tickets available in first class. Would you like to fly economy?\nPlease enter \"yes\" or \"no\": ");
                scanf("%s", seatsOutUserSelection);
                if (strcmp(seatsOutUserSelection, "yes") == 0) {
                    userSelection = 2;
                }
                else if (strcmp(seatsOutUserSelection, "no") == 0) {
                    printf("\nWe apologize for the inconvenience, the next flight out is tomorrow at 9am.");
                    userSelection = 0;
                }
            }
        }
        /*
            The logic below checks for economy seats or 2, if there are available seats then
            it will assign them to it and print a boarding pass. If the seats are sold out, but
            some are still available in first class then it will ask the user "yes" or "no". If
            "yes" it will assign the user to a seat in first class, and if "no" then it will end
            the program and return 0.
        */
        if (userSelection == 2) {
            if (economySeats > 0) {
                economySeats -= 1;
                planeSeats[economySeats + 4] = true;
                printf("\nYou are assigned seat %d in economy class. Enjoy your flight. \n\n", economySeats + 1);
            } if ((economySeats == 0) && (firstClassSeats != 0)) {
                printf("\nCurrently there are no more tickets available in economy class. Would you like to fly first class?\nPlease enter \"yes\" or \"no\": ");
                scanf("%s", seatsOutUserSelection);
                if (strcmp(seatsOutUserSelection, "yes") == 0) {
                    firstClassSeats -= 1;
                    planeSeats[firstClassSeats] = true;
                    printf("\nYou are assigned seat %d in first class. Enjoy your flight. \n\n", firstClassSeats + 1);
                    userSelection = 1;
                }
                else if (strcmp(seatsOutUserSelection, "no") == 0) {
                    printf("\nWe apologize for the inconvenience, the next flight out is tomorrow at 9am.");
                    userSelection = 0;
                }
            }
        }
        //if the user voluntarily selects 0 or inputs "no" then this will print
        if (userSelection == 0) {
            printf("\nHave a nice day.\n");
            return 0;
        }

        areSeatsOpen = openSeats(planeSeats); //very important to call the function after each iteration
    }

    // this will only print if all of the tickets are sold out
    printf("We're sorry but all of the seats are full. The next flight out is tomorrow at 9am.\nHave a good night.\n"); 

    return 0;
}
