#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mdays[][12] =
{
    { 31,28,31,30,31,30,31,31,30,31,30,31 },
    { 31,29,31,30,31,30,31,31,30,31,30,31 }
};

int isLeapYear(int y)
{
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

int dayOfYear(int y, int m, int d)
{
    int days=d;
    for (int i = 1; i < m; i++)
        days += mdays[isLeapYear(y)][i-1];
    

    return days;
}


int main(void)
{
    int year, month, day;
    int retry;
    do {
        printf("year :  "); scanf("%d", &year);
        printf("month :  "); scanf("%d", &month);
        printf("day :  "); scanf("%d", &day);

        int days = dayOfYear(year, month, day);

        printf("%d년의 %d일째입니다.\n", year, days);
        printf("다시 할까요 ?(1-yes, 0-no) : "); scanf("%d", &retry);
    } while (retry != 0);
    

    return 0;
}