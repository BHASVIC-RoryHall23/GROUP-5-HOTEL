#include <stdio.h>
#include <string.h>


int main() {

    char bookingID[11] = "1234567890", bookingTest[11];
    int test = 0,fb,hb;
    char days[20], table[10];
    int day, time;
    int i = 0;

    printf("Please enter your booking ID:\n");
    gets(bookingTest);
    fflush(stdin);

    test = strcmp(bookingTest,bookingID);

    if (test == 0){
        printf("\nyour booking ID is valid. continuing...");

        printf("\nwhat day would you like your reservation(dont capitalise)\n");
        gets(days);
        fflush(stdin);
        if(days[0] == 'm'){
            printf("you want a reservation on Monday");
            day = 1;
        }else if(days[0]=='t' && days[1] == 'u'){
            printf("you want a reservation on Tuesday");
            day = 2;
        }else if(days[0]=='w'){
            printf("you want a reservation on Wednesday");
            day = 3;
        }else if(days[0]=='t' && days[1]== 'h'){
            printf("you want a reservation on Thursday");
            day = 4;
        }else if(days[0]=='f'){
            printf("you want a reservation on Friday");
            day = 5;
        }else if(days[0]=='s' && days[1]=='a'){
            printf("you want a reservation on Saturday");
            day = 6;
        }else if(days[0]=='s'&&days[1]=='u'){
            printf("you want a reservation on Sunday");
            day = 7;
        }

        printf("thank you for selecting a day, what table would you like? \nEndor, Nanaboo, Tatooine ");
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

    } else if(test > 0){
        printf("your booking ID is Invalid exiting code...");
        return  0;
    }else{
        printf("error: 01");
    }
}
