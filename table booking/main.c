#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    setbuf(stdout,NULL);
    FILE *fpt; // File Pointer
    // Ask room
    // Check room is taken
    // Take bookingID from roomX.txt

    char bookingID[30], bookingTest[11],days[20], table[19],booking[20],FILENAME[10]="RoomX.txt";
    int day, time,i = 0,test = 0,fb,hb,room;


    printf("Please input your room number. 1-6:");
    scanf("%d",&room);

    while(room <0 || room > 6){
        printf("Try again that room is invalid:");
        scanf("%d",&room);
    }


    printf("Please enter your booking ID:\n");
    gets(bookingTest);
    fflush(stdin);

    FILENAME[4]='0' + room;

    fpt = fopen(FILENAME,"r"); // Openingfi1le.
    if (fpt == NULL){
        printf("oops can't open %s", FILENAME);
    }
    fscanf(fpt,"/n/n/n/n/n%s",&bookingID);
    test_results=strcmp(bookingTest,bookingID);
    if(test !=0){
        printf("Sorry BookingID aren't the same/n%s/n%s",bookingTest,bookingID);
        exit(1);
    }


    if (test == 0) {
        printf("\nYour booking ID is valid. continuing...");

        printf("\nwhat day would you like your reservation\n");
        fgets(days, sizeof(days), stdin);
        days[strcspn(days, "\n")] = '\0';
        // Remove newline character from input

        if (days[0] == 'm') {

            printf("you want a reservation on Monday");
            day = 1;
            strcpy(booking, "Monday");

        } else if (days[0] == 't' && days[1] == 'u') {

            printf("you want a reservation on Tuesday");
            day = 2;
            strcpy(booking, "Tuesday");

        } else if (days[0] == 'w') {

            printf("you want a reservation on Wednesday");
            day = 3;
            strcpy(booking, "Wednesday");

        } else if (days[0] == 't' && days[1] == 'h') {

            printf("you want a reservation on Thursday");
            day = 4;
            strcpy(booking, "Thursday");

        } else if (days[0] == 'f') {

            printf("you want a reservation on Friday");
            day = 5;
            strcpy(booking, "Friday");

        } else if (days[0] == 's' && days[1] == 'a') {

            printf("you want a reservation on Saturday");
            day = 6;
            strcpy(booking, "Saturday");

        } else if (days[0] == 's' && days[1] == 'u') {

            printf("you want a reservation on Sunday");
            day = 7;
            strcpy(booking, "Sunday");

        } else {

            printf("Invalid day input");
            return 1; // Exit the program if the day input is invalid
        }

        printf("thank you for selecting a day, what table would you like? \nEndor, Nanaboo, Tatooine \n");
        scanf("%d", &table);
        fflush(stdin);
        if(table[0]== 'e'){
            printf("you chose table Endor");
        }else if(table[0] == "n"){
            printf("you chose table Naboo");
        }else if(table[0]== "t"){
            printf("you chose table Tatooine");
        }

        printf("finally what time would you like for the reservation? 7pm or 9pm\n");
        scanf("%d", &time);
        fflush(stdin);
        printf("you chose %dpm",time);

        if(time != 0 && day != 0 && table != 0){
            //"you have booked your reservation on %c ", booking[20], table[10], time);
            printf("you have booked your reservation on ");
            puts(days);
            printf("you have chosen table");
            puts(table);
            printf("you reservation is at %d pm",time);


        }


    } else if(test > 0){
        printf("your booking ID is Invalid exiting code...");
        return  0;
    }else{
        printf("error: 01");
    }
}
