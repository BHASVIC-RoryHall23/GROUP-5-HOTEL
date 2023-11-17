#include <stdio.h>
#include <stdlib.h>

int RoomPrice (int DayRateB, int StayLengthB, int AgeB);
int BoardPrice (int BoardRateB,int NumGuestsB, int NumOfChildrenB, int StayLengthB);

int main() {
    FILE *filepointer;

    int DayRateA, BoardRateA = 20, room, StayLengthA = 4, Age = 66, NumOfChildrenA = 2, NumGuestsA = 4, DailyNp = 1;
    char Data[100], Name[20], NumGuest[20], BoardType[20]="HB", StayLength[20], DailyNP[20], ID[20];
    printf("Please enter your room number: ");
    fflush(stdin);
    scanf("%d", &room);

    switch(room)
    {
        case 1:
            DayRateA = 100;
            //filepointer = fopen("Room1.txt", "r");
            break;
        case 2:
            DayRateA = 100;
            //filepointer = fopen("Room2.txt", "r");
            break;
        case 3:
            DayRateA = 85;
            //filepointer = fopen("Room3.txt", "r");
            break;
        case 4:
            DayRateA = 75;
            //filepointer = fopen("Room4.txt", "r");
            break;
        case 5:
            DayRateA = 75;
            //filepointer = fopen("Room5.txt", "r");
            break;
        case 6:
            DayRateA = 50;
            //filepointer = fopen("Room6.txt", "r");
            break;
        default:
            printf("ERROR");
            break;
    }
    /*/
    switch (BoardType)
    {
        case BoardType == "FB":
            BoardRateA = 20;
            break;
        case BoardType == "HB":
            BoardRateA = 15;
            break;
        case BoardType == "BB":
            BoardRateA = 5;
            break;
        default:
            printf("board type not recognised");
            break;
    }
/*/
    //fscanf("%s", &Data);
    float roomcost = RoomPrice(DayRateA, StayLengthA, Age);
    float boardcost = BoardPrice(BoardRateA, NumGuestsA, NumOfChildrenA, StayLengthA);

    printf("\n%.2f", roomcost);
    printf("\n%.2f", boardcost);

    float total = roomcost + boardcost;
    if (DailyNp == 1)
    {
        printf("\nTotal Bill: %.2f",total + 5.5);
    }
    else
    {
        printf("\nTotal Bill: %.2f", total);
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