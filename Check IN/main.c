#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int is_empty_file(FILE *fp);

int main() {


    FILE *fpt; // File Pointer
    srand(time(NULL)); // Random number

    int NumGuests, BoardType, StayLength, DailyNP, room, RandomNumber,flag;
    char Name[30], BookingID[33],FILENAME[9]="Room0.txt", SecondName[20];



    // Getting info from client.
    printf("Please input your name:"); scanf("%s",*Name); printf("\n");
    printf("Please input Number of Guests staying:"); scanf("%d",&NumGuests); printf("\n");
    printf("Please input your BoardType (FB, HB, B&B) (1,2,3):"); scanf("%d",&BoardType); printf("\n");
    printf("Please input if you want with Daily NewsPaper, 0 for no, 1 for yes:"); scanf("%d",&DailyNP); printf("\n");


    // Checking if rooms are free.

    room = -1; // -1 means that no rooms are free.#
    for(int x=0;x<6;x++){


        FILENAME[4]='0' + x+1;

        fpt = fopen(FILENAME,"r"); // Opening each fi1le.
        room = is_empty_file( fpt);

        if(room==1){ // If its 1 then its open.

            room = x+1; // Changing to show that a room is free, making it x to show which room is free.

            switch(room){ // Printing out the rooms open and their cost.
                case 1:
                    printf("Room 1 is open and costs $100.\n");
                    break;

                case 2:
                    printf("Room 2 is open and costs $100.\n");
                    break;

                case 3:
                    printf("Room 3 is open and costs $85.\n");
                    break;

                case 4:
                    printf("Room 4 is open and costs $75.\n");
                    break;

                case 5:
                    printf("Room 5 is open and costs $75.\n");
                    break;

                case 6:
                    printf("Room 6 is open and costs $50.\n");
                    break;

            }
        }


        fclose(fpt);// Closing file.
    }
    // I.e. room =-1 for closed and room = the room number if open.
    if (room == -1){
        printf("Sorry No rooms available!");
    }

    // Picking a room.

    printf("Which room do you want?");
    scanf("%d",room);


    // Making Booking ID.
    // Using in the format of FIRSTNAME SECONDMENT

    for(int x=0;x<strlen(Name);x++){ // Finding the gap in between the first and second names i.e. Barron Green
        if(Name[x] == ' ') {
            flag=x; // Saving where the gap is.
            break; // Moving out of the for loop.
        }
    }
    for(int x=flag;x<strlen(Name);x++){
        SecondName[x] = Name[x]; // Coping the second name into the variable.
    }

    // Creating random number.
    RandomNumber = rand()%10; // Random number between 1-10;

    //strcpy(BookingID, strcat(SecondName,itoa(RandomNumber)));
    sprintf(BookingID, "%s%d",SecondName, RandomNumber);



    // Storing data.
    /*
     * NAME
     * NUM GUESTS
     * BOARD TYPE
     * STAY LENGTH
     * DAILY NS
     * BOOKING ID
     */
    switch(room){
        case 1:
            fpt = fopen("Room1.txt","w+");
            fprintf(fpt,"%s,%d,%d,%d,%s",Name,NumGuests,BoardType,StayLength,DailyNP,BookingID);
            fclose(fpt);
            break;
        case 2:
            fpt = fopen("Room2.txt","w+");
            fprintf(fpt,"%s,%d,%d,%d,%s",Name,NumGuests,BoardType,StayLength,DailyNP,BookingID);
            fclose(fpt);
            break;
        case 3:
            fpt = fopen("Room3.txt","w+");
            fprintf(fpt,"%s,%d,%d,%d,%s",Name,NumGuests,BoardType,StayLength,DailyNP,BookingID);
            fclose(fpt);
            break;
        case 4:
            fpt = fopen("Room4.txt","w+");
            fprintf(fpt,"%s,%d,%d,%d,%s",Name,NumGuests,BoardType,StayLength,DailyNP,BookingID);
            fclose(fpt);
            break;
        case 5:
            fpt = fopen("Room5.txt","w+");
            fprintf(fpt,"%s,%d,%d,%d,%s",Name,NumGuests,BoardType,StayLength,DailyNP,BookingID);
            fclose(fpt);
            break;
        case 6:
            fpt = fopen("Room6.txt","w+");
            fprintf(fpt,"%s,%d,%d,%d,%s",Name,NumGuests,BoardType,StayLength,DailyNP,BookingID);
            fclose(fpt);
            break;

    }
    printf("Done writting!");


    return 0;
}

int is_empty_file(FILE *fp) {
    int c = getc(fp);
    if (c == EOF){
        return 1;
    }
    ungetc(c, fp);
    return 0;
}
