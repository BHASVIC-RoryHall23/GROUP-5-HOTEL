#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_empty_file(FILE *fp);
int RoomPrice (int DayRateB, int StayLengthB, int AgeB);
int BoardPrice (int BoardRateB,int NumGuestsB, int NumOfChildrenB, int StayLengthB);
int CHECK_IN();
int TABLE();
int CHECK_OUT();

int main() {

    setbuf(stdout,NULL);

    int file;

    printf("Hello Welcome to KASHYYYK hotel!\n");

    while (free){
        printf("\nWhat do you want to do?");
        printf("\n(1) For Check In.\n(2) For Table Booking.\n(3) For Check Out!\nENTER 0 FOR QUIT.\n");
        scanf("%d",&file);

        if(file == 1){
            CHECK_IN();
        }
        else if(file==2){
            TABLE();
        }
        else if(file==3){
            CHECK_OUT();
        }
        else if(file==0){
            exit(1);
        }
        else{
            printf("Failed Please try again.");
        }
    }

}

int CHECK_IN() {
    setbuf(stdout,NULL);

    FILE *fpt; // File Pointer
    srand(time(NULL)); // Random number

    int NumGuests, BoardType, StayLength, DailyNP, room, RandomNumber,BookedRooms[7],NumChildren;
    char Name[127], sName[127], BookingID[33],FILENAME[10]="Room0.txt",DOB[11];



    // Getting info from client.
    printf("Please input your first name:"); scanf("%s",Name);
    printf("Please input your second name:"); scanf("%s",sName);
    printf("Please enter your Data of Birth in the form xx/xx/xxxx:"); scanf("%s",DOB);
    printf("Please input Number of Guests staying:"); scanf("%d",&NumGuests);

    // Validating NumGuests.
    fflush(stdin);
    while (NumGuests >4 || NumGuests < 1){
        printf("Four or below please try again:"); scanf("%d",&NumGuests);fflush(stdin);
    }

    printf("Please input Number of Children staying:"); scanf("%d",&NumChildren);

    while(NumChildren>=NumGuests || NumChildren <0){
        printf("Please input Number of Children staying:"); scanf("%d",&NumChildren);
    }

    printf("Please input Length of stay in days:"); scanf("%d",&StayLength);
    fflush(stdin);
    printf("Please input your BoardType (FB, HB, B&B) (1,2,3):"); scanf("%d",&BoardType);

    // Validating BoardType
    fflush(stdin);
    while( BoardType != 1 && BoardType != 2 && BoardType != 3 ){
        printf("Please input 1,2,3 For Fullbooking, halfBooking and Bread and breakfast:");scanf("%d",&BoardType);
        fflush(stdin);
    }

    printf("Please input if you want with Daily NewsPaper, 0 for no, 1 for yes:"); scanf("%d",&DailyNP);

    fflush(stdin);
    while( DailyNP != 1 && DailyNP != 0 ){
        printf("Please input 0 or 1 not anything else. Try again:");scanf("%d",&DailyNP);
        fflush(stdin);
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
        return 0;
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
            fprintf(fpt,"%s\n",Name);
            fprintf(fpt,"%s\n",DOB);
            fprintf(fpt,"%d\n",NumGuests);
            fprintf(fpt,"%d\n",NumChildren);
            fprintf(fpt,"%d\n",BoardType);
            fprintf(fpt,"%d\n",StayLength);
            fprintf(fpt,"%d\n",DailyNP);
            fprintf(fpt,"%s\n",BookingID);

            printf("Added to book!\n");
            fclose(fpt);
            break;

        case 2:
            fpt = fopen("Room2.txt","w+");

            fprintf(fpt,"%s\n",Name);
            fprintf(fpt,"%s\n",DOB);
            fprintf(fpt,"%d\n",NumGuests);
            fprintf(fpt,"%d\n",NumChildren);
            fprintf(fpt,"%d\n",BoardType);
            fprintf(fpt,"%d\n",StayLength);
            fprintf(fpt,"%d\n",DailyNP);
            fprintf(fpt,"%s\n",BookingID);

            printf("Added to book!\n");
            fclose(fpt);
            break;

        case 3:
            fpt = fopen("Room3.txt","w+");

            fprintf(fpt,"%s\n",Name);
            fprintf(fpt,"%s\n",DOB);
            fprintf(fpt,"%d\n",NumGuests);
            fprintf(fpt,"%d\n",NumChildren);
            fprintf(fpt,"%d\n",BoardType);
            fprintf(fpt,"%d\n",StayLength);
            fprintf(fpt,"%d\n",DailyNP);
            fprintf(fpt,"%s\n",BookingID);

            printf("Added to book!\n");
            fclose(fpt);
            break;

        case 4:
            fpt = fopen("Room4.txt","w+");

            fprintf(fpt,"%s\n",Name);
            fprintf(fpt,"%s\n",DOB);
            fprintf(fpt,"%d\n",NumGuests);
            fprintf(fpt,"%d\n",NumChildren);
            fprintf(fpt,"%d\n",BoardType);
            fprintf(fpt,"%d\n",StayLength);
            fprintf(fpt,"%d\n",DailyNP);
            fprintf(fpt,"%s\n",BookingID);

            printf("Added to book!\n");
            fclose(fpt);
            break;

        case 5:
            fpt = fopen("Room5.txt","w+");
            fprintf(fpt,"%s\n",Name);
            fprintf(fpt,"%s\n",DOB);
            fprintf(fpt,"%d\n",NumGuests);
            fprintf(fpt,"%d\n",NumChildren);
            fprintf(fpt,"%d\n",BoardType);
            fprintf(fpt,"%d\n",StayLength);
            fprintf(fpt,"%d\n",DailyNP);
            fprintf(fpt,"%s\n",BookingID);

            printf("Added to book!\n");
            fclose(fpt);
            break;

        case 6:
            fpt = fopen("Room6.txt","w+");

            fprintf(fpt,"%s\n",Name);
            fprintf(fpt,"%s\n",DOB);
            fprintf(fpt,"%d\n",NumGuests);
            fprintf(fpt,"%d\n",NumChildren);
            fprintf(fpt,"%d\n",BoardType);
            fprintf(fpt,"%d\n",StayLength);
            fprintf(fpt,"%d\n",DailyNP);
            fprintf(fpt,"%s\n",BookingID);

            printf("Added to book!\n");
            fclose(fpt);
            break;

    }
    // printf("Done writing!");

    printf("Your BookingID is %s",BookingID);
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

int TABLE() {

    setbuf(stdout,NULL);
    FILE *fpt; // File Pointer
    // Ask room
    // Check room is taken
    // Take bookingID from roomX.txt

    char bookingID[30], bookingTest[30],days[20], table[19],booking[20],FILENAME[10]="RoomX.txt",flag[127];
    int day, time,i = 0,test = 0,fb,hb,room;


    printf("Please input your room number. 1-6:");
    scanf("%d",&room);

    while(room <0 || room > 6){
        printf("Try again that room is invalid:");
        scanf("%d",&room);
    }


    printf("Please enter your booking ID:");
    scanf("%s",bookingTest);
    fflush(stdin);

    FILENAME[4]='0' + room;

    fpt = fopen(FILENAME,"r"); // Openingfi1le.
    if (fpt == NULL){
        printf("oops can't open %s", FILENAME);
    }
    // Name, DOB, N. guests, N. Children, BOARDTYPE, Stay length, Dailynp, BoardID
    fscanf(fpt,"%s%s%s%s%s%s%s%s",flag,flag,flag,flag,flag,flag,flag,bookingID);
    test=strcmp(bookingTest,bookingID);

    if(test !=0){
        printf("Sorry BookingID aren't the same\n%s\n%s",bookingTest,bookingID);
        return 0;
    }


    if (test == 0) {
        printf("\nYour booking ID is valid. continuing...");

        printf("\nwhat day would you like your reservation.\n");
        fgets(days, sizeof(days), stdin);
        days[strcspn(days, "\n")] = '\0';
        // Remove newline character from input

        days[0] = tolower(days[0]);

        if (days[0] == 'm') {
            printf("You want a reservation on Monday");
            day = 1;
            strcpy(booking, "Monday");

        } else if (days[0] == 't' && days[1] == 'u') {

            printf("You want a reservation on Tuesday");
            day = 2;
            strcpy(booking, "Tuesday");

        } else if (days[0] == 'w') {

            printf("You want a reservation on Wednesday");
            day = 3;
            strcpy(booking, "Wednesday");

        } else if (days[0] == 't' && days[1] == 'h') {

            printf("You want a reservation on Thursday");
            day = 4;
            strcpy(booking, "Thursday");

        } else if (days[0] == 'f') {

            printf("You want a reservation on Friday");
            day = 5;
            strcpy(booking, "Friday");

        } else if (days[0] == 's' && days[1] == 'a') {

            printf("You want a reservation on Saturday");
            day = 6;
            strcpy(booking, "Saturday");

        } else if (days[0] == 's' && days[1] == 'u') {

            printf("You want a reservation on Sunday");
            day = 7;
            strcpy(booking, "Sunday");

        } else {

            printf("Invalid day input\n");
            return 1; // Exit the program if the day input is invalid
        }

        printf("\nThank you for selecting a day, what table would you like? \nEndor, Nanaboo, Tatooine \n");
        scanf("%d", &table);
        fflush(stdin);
        if(table[0]== 'e'){
            printf("You chose table Endor");
        }else if("n" == table[0]){
            printf("You chose table Naboo");
        }else if("t" == table[0]){
            printf("You chose table Tatooine");
        }

        printf("Finally what time would you like for the reservation? 7pm or 9pm\n");
        scanf("%d", &time);
        fflush(stdin);
        printf("you chose %dpm",time);

        if(time != 0 && day != 0 && table != 0){
            //"you have booked your reservation on %c ", booking[20], table[10], time);
            printf("You have booked your reservation on ");
            puts(days);
            printf("You have chosen table");
            puts(table);
            printf("You reservation is at %d pm",time);


        }


    } else if(test > 0){
        printf("your booking ID is Invalid exiting code...");
        return  0;
    }else{
        printf("error: 01");
    }
}

int CHECK_OUT() {
    FILE *filepointer;

    int DayRateA, BoardRateA, room, StayLengthA, Age, NumOfChildrenA, NumGuestsA, DailyNp,BoardingType;
    char DOB[11],year[5],name[127];
    // BoardingType Is stored as 1,2,3 For fullbook halfbook and bed&breakfast.


    // Age form DOB



    printf("Please enter your room number: ");    scanf("%d", &room);
    fflush(stdin);

    switch(room)
    {
        case 1:
            DayRateA = 100;
            filepointer = fopen("Room1.txt", "r");
            if (filepointer == NULL){
                printf("oops can't open");
            }
            fscanf(filepointer,"%s%s%d%d%d%d%d",&name,&DOB,&NumGuestsA,&NumOfChildrenA,&BoardingType,&StayLengthA,&DailyNp);
            fclose(filepointer);
            filepointer = fopen("Room1.txt", "w+");
            fclose(filepointer);
            break;
        case 2:
            DayRateA = 100;
            filepointer = fopen("Room2.txt", "r");
            if (filepointer == NULL){
                printf("oops can't open");
            }
            fscanf(filepointer,"%s%s%d%d%d%d%d",&name,&DOB,&NumGuestsA,&NumOfChildrenA,&BoardingType,&StayLengthA,&DailyNp);
            fclose(filepointer);
            filepointer = fopen("Room2.txt", "w+");
            fclose(filepointer);
            break;
        case 3:
            DayRateA = 85;
            filepointer = fopen("Room3.txt","r");
            if (filepointer == NULL){
                printf("oops can't open");
            }
            fscanf(filepointer,"%s%s%d%d%d%d%d",&name,&DOB,&NumGuestsA,&NumOfChildrenA,&BoardingType,&StayLengthA,&DailyNp);
            fclose(filepointer);
            filepointer = fopen("Room3.txt", "w+");
            fclose(filepointer);
            break;
        case 4:
            DayRateA = 75;
            filepointer = fopen("Room4.txt", "r");
            if (filepointer == NULL){
                printf("oops can't open");
            }
            fscanf(filepointer,"%s%s%d%d%d%d%d",&name,&DOB,&NumGuestsA,&NumOfChildrenA,&BoardingType,&StayLengthA,&DailyNp);
            fclose(filepointer);
            filepointer = fopen("Room4.txt", "w+");
            fclose(filepointer);
            break;
        case 5:
            DayRateA = 75;
            filepointer = fopen("Room5.txt", "r");
            if (filepointer == NULL){
                printf("oops can't open");
            }
            fscanf(filepointer,"%s%s%d%d%d%d%d",&name,&DOB,&NumGuestsA,&NumOfChildrenA,&BoardingType,&StayLengthA,&DailyNp);
            fclose(filepointer);
            filepointer = fopen("Room5.txt", "w+");
            fclose(filepointer);
            break;
        case 6:
            DayRateA = 50;
            filepointer = fopen("Room6.txt", "r");
            if (filepointer == NULL){
                printf("oops can't open");
            }
            fscanf(filepointer,"%s%s%d%d%d%d%d",&name,&DOB,&NumGuestsA,&NumOfChildrenA,&BoardingType,&StayLengthA,&DailyNp);
            fclose(filepointer);
            filepointer = fopen("Room6.txt", "w+");
            fclose(filepointer);
            break;
        default:
            printf("ERROR");
            break;
    }

    // WORK OUT AGE FROM DOB
    for(int x=0;x<5;x++){
        year[x] = DOB[x+6];
    }
    // Now you got a string of the year i.e. 2000
    Age = 2023-atoi(year);



    float roomcost = RoomPrice(DayRateA, StayLengthA, Age);
    float boardcost = BoardPrice(BoardRateA, NumGuestsA, NumOfChildrenA, StayLengthA);

    printf("\n%.2f", roomcost);
    printf("\n%.2f", boardcost);

    float total = roomcost + boardcost;
    if (DailyNp == 1)
    {
        printf("\nTotal Bill: %.2f\n",total + 5.5);
    }
    else
    {
        printf("\nTotal Bill: %.2f\n", total);
    }

}

int RoomPrice(int DayRateB, int StayLengthB, int AgeB)
{
    int RoomTotal;
    RoomTotal = DayRateB * StayLengthB;
    if (AgeB > 65)
    {
        RoomTotal = RoomTotal * 0.9;
    }
    return RoomTotal;
}

int BoardPrice(int BoardRateB,int NumGuestsB, int NumOfChildrenB, int StayLengthB)
{
    int BoardTotal = 0;
    for (int i=0;i<(NumGuestsB-NumOfChildrenB);i++)
    {
        BoardTotal = BoardTotal+BoardRateB;
    }
    for (int i=0;i<NumOfChildrenB;i++)
    {
        BoardTotal = BoardTotal+(BoardRateB*0.5);
    }
    BoardTotal = BoardTotal * StayLengthB;
    return BoardTotal;
}
