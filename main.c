
/*
ID: caiulor1
LANG: C
PROG: milk2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int findFirstInactive(int *vector, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (vector[i] == 0)
        {
            return i;
        }
    }
}

void main()
{
    FILE *fin = fopen("milk2IN.txt", "r");
    FILE *fout = fopen("milk2OUT.txt", "w");

    int n;
    char buf[100];
    fgets(buf, 100, fin);
    n = atoi(buf);

    int times[2 * n];
    int type[2 * n]; // 1=start, 0=end

    int i = 0;

    while (fgets(buf, 100, fin))
    {
        sscanf(buf, "%d %d\n", &times[i], &times[i + 1]);
        type[i] = 1;
        type[i + 1] = 0;
        i = i + 2;
    }
    // Bubble Sort
    {
        int j;

        int temp1, temp2;
        for (i = 0; i < 2 * n; i++)
        {

            for (j = 0; j < i; j++)
            {
                if (times[i] > times[i + 1])
                {
                    temp1 = times[i];
                    times[i] = times[i + 1];
                    times[i + 1] = temp1;

                    temp2 = type[i];
                    type[i] = type[i + 1];
                    type[i + 1] = temp2;
                }
            }
        }
    }

    int largestActiveTime = 0;
    int largestInactiveTime = 0;
    int currentActiveTime = times[0];
    int currentInactiveTime;
    int currentActivity = 1;
    int lastCurrentActivity;
    int lastActiveTime = times[0];
    int lastInactiveTime = times[findFirstInactive(type, n)];
    int temp;

    for (i = 1; i < 2 * n; i++)
    {
        printf("%d %d %d %d\n", currentActiveTime, lastActiveTime, currentInactiveTime, lastInactiveTime);

        if (type[i] == 1)
        {
            lastCurrentActivity = currentActivity;
            currentActivity++;
        }
        else
        {
            lastCurrentActivity = currentActivity;
            currentActivity--;
        }

        if (currentActivity > 0 && lastCurrentActivity > 0) // continues being active
        {                                                   // both active
            currentActiveTime = times[i];
            temp = times[i] - lastActiveTime;
            if (temp > largestActiveTime)
            {
                largestActiveTime = temp;
            }
        }

        else if (currentActivity > 0 && lastCurrentActivity == 0)
        { // was inactive, now active

            currentActiveTime = times[i];
            currentInactiveTime = times[i];
            temp = currentInactiveTime - lastInactiveTime;
            lastInactiveTime = currentInactiveTime;
            if (temp > largestInactiveTime)
            {
                largestInactiveTime = temp;
            }
        }

        else if (currentActivity == 0 && lastCurrentActivity > 0)
        { // was active, now inactive
            currentInactiveTime = times[i];
            currentActiveTime = times[i];
            temp = currentActiveTime - lastActiveTime;
            if (temp > largestActiveTime)
            {
                largestActiveTime = temp;
            }
            lastActiveTime = currentActiveTime;
        }
    }

    printf("%d %d\n", largestActiveTime, largestInactiveTime);

    fclose(fin);
    fclose(fout);
}
