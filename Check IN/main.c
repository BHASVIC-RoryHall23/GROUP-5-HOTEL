#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int is_empty_file(FILE *fp);
int boarding(int board);

int main() {
    setbuf(stdout,NULL);

    FILE *fpt; // File Pointer
    srand(time(NULL)); // Random number

    int NumGuests, BoardType, StayLength, DailyNP, room, RandomNumber,BookedRooms[7];
    char Name[127], sName[127], BookingID[33],FILENAME[10]="Room0.txt";



    // Getting info from client.
    printf("Please input your first name:"); scanf("%s",Name);
    printf("Please input your second name:"); scanf("%s",sName);
    printf("Please input Number of Guests staying:"); scanf("%d",&NumGuests);
    printf("Please input Lenght of stay:"); scanf("%d",&StayLength);

    // Validating NumGuests.
    while (NumGuests >4 || NumGuests < 1){
        printf("Four or below please try again:"); scanf("%d",&NumGuests);
    }

    printf("Please input your BoardType (FB, HB, B&B) (1,2,3):"); scanf("%d",&BoardType);

    // Validating BoardType
    while( BoardType != 1 && BoardType != 2 && BoardType != 3 ){
        printf("Please input 1,2,3 For Fullbooking, halfBooking and Bread and breakfast:");scanf("%d",&BoardType);
    }

    printf("Please input if you want with Daily NewsPaper, 0 for no, 1 for yes:"); scanf("%d",&DailyNP);

    while( DailyNP != 1 && DailyNP != 0 ){
        printf("Please input 0 or 1 not anything else. Try again:");scanf("%d",&DailyNP);
    }

    // Checking if rooms are free.

    int empty = 1; // -1 means that no rooms are free.#
    for(int x=0;x<6;x++){


        FILENAME[4]='0' + x+1;

        fpt = fopen(FILENAME,"r"); // Opening each fi1le.
        if (fpt == NULL){
            printf("oops can't open %s", FILENAME);
        }
        room = is_empty_file( fpt);

        //printf("Room flag = %d", room);

        if(room==1){ // If its 1 then its open.

            room = x+1; // Changing to show that a room is free, making it x to show which room is free.

            switch(room){ // Printing out the rooms open and their cost.
                case 1:
                    printf("Room 1 is open and costs $100.\n");
                    BookedRooms[0] = 1;empty = 0;
                    break;

                case 2:
                    printf("Room 2 is open and costs $100.\n");
                    BookedRooms[1] = 1;empty = 0;
                    break;

                case 3:
                    printf("Room 3 is open and costs $85.\n");
                    BookedRooms[2] = 1;empty = 0;
                    break;

                case 4:
                    printf("Room 4 is open and costs $75.\n");
                    BookedRooms[3] = 1;empty = 0;
                    break;

                case 5:
                    printf("Room 5 is open and costs $75.\n");
                    BookedRooms[4] = 1;empty = 0;
                    break;

                case 6:
                    printf("Room 6 is open and costs $50.\n");
                    BookedRooms[5] = 1;
                    empty = 0;
                    break;
                default:
                    printf("ERROR CODE 101");
            }
        }


        fclose(fpt);// Closing file.
    }
    // I.e. room =-1 for closed and room = the room number if open.
    if (empty == 1){
        printf("Sorry No rooms available!");
        exit(1);
    }

    // Picking a room.

    printf("Which room do you want?");
    scanf("%d",&room);

    while(BookedRooms[room-1] != 1){
        printf("Please input a valid room, That room is booked:");
        scanf("%d",&room);
    }


    // Making Booking ID.

    // Creating random number.
    RandomNumber = rand()%10; // Random number between 1-10;

    //strcpy(BookingID, strcat(SecondName,itoa(RandomNumber)));
    sprintf(BookingID, "%s%d",sName, RandomNumber);



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
            fprintf(fpt,"Name: %s\n",Name);
            fprintf(fpt,"No. Guests: %d\n",NumGuests);
            fprintf(fpt,"BoardType: %d\n",BoardType);
            fprintf(fpt,"StayLength: %d\n",StayLength);
            fprintf(fpt,"Daily Newspaper: %d\n",DailyNP);
            fprintf(fpt,"BookingID: %s\n",BookingID);

            printf("Added to book!");
            fclose(fpt);
            break;

        case 2:
            fpt = fopen("Room2.txt","w+");

            fprintf(fpt,"Name: %s\n",Name);
            fprintf(fpt,"No. Guests: %d\n",NumGuests);
            fprintf(fpt,"BoardType: %d\n",BoardType);
            fprintf(fpt,"StayLength: %d\n",StayLength);
            fprintf(fpt,"Daily Newspaper: %d\n",DailyNP);
            fprintf(fpt,"BookingID: %s\n",BookingID);

            printf("Added to book!");
            fclose(fpt);
            break;

        case 3:
            fpt = fopen("Room3.txt","w+");

            fprintf(fpt,"Name: %s\n",Name);
            fprintf(fpt,"No. Guests: %d\n",NumGuests);
            fprintf(fpt,"BoardType: %d\n",BoardType);
            fprintf(fpt,"StayLength: %d\n",StayLength);
            fprintf(fpt,"Daily Newspaper: %d\n",DailyNP);
            fprintf(fpt,"BookingID: %s\n",BookingID);

            printf("Added to book!");
            fclose(fpt);
            break;

        case 4:
            fpt = fopen("Room4.txt","w+");

            fprintf(fpt,"Name: %s\n",Name);
            fprintf(fpt,"No. Guests: %d\n",NumGuests);
            fprintf(fpt,"BoardType: %d\n",BoardType);
            fprintf(fpt,"StayLength: %d\n",StayLength);
            fprintf(fpt,"Daily Newspaper: %d\n",DailyNP);
            fprintf(fpt,"BookingID: %s\n",BookingID);

            printf("Added to book!");
            fclose(fpt);
            break;

        case 5:
            fpt = fopen("Room5.txt","w+");

            fprintf(fpt,"Name: %s\n",Name);
            fprintf(fpt,"No. Guests: %d\n",NumGuests);
            fprintf(fpt,"BoardType: %d\n",BoardType);
            fprintf(fpt,"StayLength: %d\n",StayLength);
            fprintf(fpt,"Daily Newspaper: %d\n",DailyNP);
            fprintf(fpt,"BookingID: %s\n",BookingID);

            printf("Added to book!");
            fclose(fpt);
            break;

        case 6:
            fpt = fopen("Room6.txt","w+");

            fprintf(fpt,"Name: %s\n",Name);
            fprintf(fpt,"No. Guests: %d\n",NumGuests);
            fprintf(fpt,"BoardType: %d\n",BoardType);
            fprintf(fpt,"StayLength: %d\n",StayLength);
            fprintf(fpt,"Daily Newspaper: %d\n",DailyNP);
            fprintf(fpt,"BookingID: %s\n",BookingID);

            printf("Added to book!");
            fclose(fpt);
            break;

    }
   // printf("Done writing!");


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

int boarding(int board){
    char x[3];
    if(board == 1){
        x[0] = 'F';
        x[1] = 'B';
        return *x;
    }
    else if(board == 2){
        x[0] = 'H';
        x[1] = 'B';
        return *x;
    }
    else if(board == 3){
        x[0] = 'B';
        x[1] = 'B';
        return *x;
    }
    else{
        printf("ERROR - B_TYPE");
        return 0;
    }
}