#include <stdio.h>
#include <string.h>


int main() {

    char bookingID[11] = "1234567890", bookingTest[11];
    int test = 0,fb,hb;
    char days[10], day[8] = {1,1,1,1,1,1,1} ;//day ,tables, 7pm, 9pm
    int i = 0;

    printf("Please enter your booking ID:\n");
    gets(bookingTest);
    fflush(stdin);

    test = strcmp(bookingTest,bookingID);

    if (test == 0){
        printf("\nyour booking ID is valid. continuing...");

        printf("\nwhat day would you like your reservation\n");
        gets(days);
        if(days[1] == 'm'){

            printf("Monday");
        }

    } else if(test > 0){
        printf("your booking ID is Invalid exiting code...");
        return  0;
    }else{
        printf("error: 01");
    }
}
