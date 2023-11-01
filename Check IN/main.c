#include <stdio.h>
#include <string.h>

int main() {


    FILE *fpt; // File Pointer
    fpt = fopen("C:\\Users\\roryh\\Desktop\\MAIN\\CS\\C code GH\\GROUP-5-HOTEL\\Check IN\\Data.csv","r");
    int test_num; char test_str; // TEST PURPOSE


    int NumGuests, BoardType, StayLength, DailyNP, cost, room;
    char Name[30], BookingID[33];

    /*
    // Getting info from client.
    printf("Please input your name:"); scanf("%s",*Name); printf("\n");
    printf("Please input Number of Guests staying:"); scanf("%d",&NumGuests); printf("\n");
    printf("Please input your BoardType (FB, HB, B&B) (1,2,3):"); scanf("%d",&BoardType); printf("\n");
    printf("Please input if you want with Daily NewsPaper, 0 for no, 1 for yes:"); scanf("%d",&DailyNP); printf("\n");
    */

    // Checking if any rooms are open.
    fscanf(fpt,"%d",&test_num);
    printf("%d",test_num);



    // Closing file
    fclose(fpt);






        return 0;
}
