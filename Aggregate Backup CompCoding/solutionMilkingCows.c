
/*
ID: caiulor1
LANG: C
PROG: milk2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n, int arr2[])
{
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swap(&arr2[j], &arr2[j + 1]);

                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

void main()
{
    FILE *fin = fopen("milk2IN.txt", "r");
    FILE *fout = fopen("milk2OUT.txt", "w");

    int n;
    char buf[500];
    fgets(buf, 500, fin);
    n = atoi(buf);
    if (n == 1)
    {
        int i = 0;
        int times[2 * n];

        while (fgets(buf, 500, fin))
        {
            sscanf(buf, "%d %d\n", &times[i], &times[i + 1]);
            i = i + 2;
        }

        fprintf(fout, "%d %d\n", times[1] - times[0], 0);
    }
    else
    {

        int times[2 * n];
        int type[2 * n]; // 1=start, 0=end

        int i = 0;

        while (fgets(buf, 500, fin))
        {
            sscanf(buf, "%d %d\n", &times[i], &times[i + 1]);
            type[i] = 1;
            type[i + 1] = 0;
            i = i + 2;
        }

        bubbleSort(times, 2 * n, type);

        int j;
        int lastLowTime;

        int largestInactiveTime = 0;
        int largestActiveTime = 0;
        int currentSetting = 1;
        int lastHighTime = times[0];
        int lastSetting = 1;

        int temp;
        for (i = 1; i < 2 * n; i++)
        {

            if (type[i] == 1)
            {
                lastSetting = currentSetting;
                currentSetting++;
            }
            else if (type[i] == 0)
            {
                lastSetting = currentSetting;
                currentSetting--;
            }

            if (lastSetting == 0 && currentSetting == 1 && times[i] != times[i - 1])
            {
                lastHighTime = times[i];
            }

            if (currentSetting == 0)
            {
                temp = times[i] - lastHighTime;

                if (temp > largestActiveTime)
                {
                    largestActiveTime = temp;
                }
            }
            if (currentSetting == 0 && type[i] == 0 && lastSetting == 1)
            {
                lastLowTime = times[i];
            }
            if (currentSetting == 1 && lastSetting == 0 && type[i - 1] == 0)
            {
                temp = times[i] - lastLowTime;

                if (temp > largestInactiveTime)
                {
                    largestInactiveTime = temp;
                }
            }
        }
        fprintf(fout, "%d %d\n", largestActiveTime, largestInactiveTime);
    }

    fclose(fin);
    fclose(fout);
}
