
/*
ID: caiulor1
LANG: C
PROG: friday
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{

    FILE *fin = fopen("friday.in", "r");
    FILE *fout = fopen("friday.out", "w");
    char buff[20];
    fgets(buff, 20, fin);
    int N = atoi(buff);

    int WeekDay = 2;
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int Days[7] = {0, 0, 0, 0, 0, 0, 0};
    // Monday tuesday ..
    int day = 2;
    int year = 1900;
    int leap;
    // for each year, compute the number of days landed on the 13th for each month, one in each month, then find out what day it is of the week
    for (year = 1900; year <= 1900 + N - 1; year++)
    {
        leap = 0;
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        {
            leap = 1;
        }
        else if (year % 4 == 100 && year % 400 != 0)
        {
            leap = 0;
        }
        else if (year % 4 != 0)
        {
            leap = 0;
        }

        if (leap == 1)
        {
            months[1] = 29;
        }
        else
        {
            months[1] = 28;
        }

        for (int m = 0; m <= 11; m++)
        {
            day = day + 12; // 13th day
            day = day % 7;
            Days[day]++;
            day = day + months[m] - 12;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        fprintf(fout, "%d ", Days[i]);
    }
    fprintf(fout, "%d\n", Days[6]);

    fclose(fin);
    fclose(fout);
}
