
/*
ID: caiulor1
LANG: C
PROG: beads
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkAll(char necklace[], int N)
{
    char currentColor = necklace[0];
    for (int i = 0; i < N; i++)
    {
        if (necklace[i] != currentColor)
        {
            return 0;
        }
    }
    return 1;
}

char colorRight(char necklace[], int currentPosition, int N)
{
    int i = currentPosition;
    char currentColor = 'w';
    while (currentColor == necklace[i])
    {
        i++;
        if (i == N)
        {
            i = 0;
        }
    }
    return necklace[i];
}

char colorLeft(char necklace[], int currentPosition, int N)
{
    int i = currentPosition;
    char currentColor = 'w';
    while (currentColor == necklace[i])
    {
        i--;
        if (i == -1)
        {
            i = N - 1;
        }
    }
    return necklace[i];
}

int check(char necklace[], int currentPosition, int N)
{
    if (checkAll(necklace, N) == 1)
    {
        return N;
    }

    int i = currentPosition;
    int number = 0;
    int totalChecks = 0;
    char currentColor;
    if (necklace[currentPosition] == 'w')
    {
        currentColor = colorRight(necklace, currentPosition, N);
    }
    else
    {
        currentColor = necklace[currentPosition];
    }
    // checkright

    while (necklace[i] == currentColor || necklace[i] == 'w')
    {
        if (totalChecks >= N + 1)
        {
            return number;
        }

        number++;
        totalChecks++;
        i++;
        if (i == N)
        {
            i = 0;
        }
    }

    // checkleft
    if (currentPosition == 0)
    {
        currentPosition = N - 1;
    }
    else
    {
        currentPosition = currentPosition - 1;
    }

    if (necklace[currentPosition] == 'w')
    {
        currentColor = colorLeft(necklace, currentPosition, N);
    }
    else
    {
        currentColor = necklace[currentPosition];
    }
    totalChecks = 0;
    i = currentPosition;
    while (necklace[i] == currentColor || necklace[i] == 'w')
    {
        if (totalChecks >= N)
        {
            return number;
        }
        number++;
        totalChecks++;
        i--;
        if (i == -1)
        {
            i = N - 1;
        }
    }

    return number;
}

void main()
{

    FILE *fin = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");
    int N;
    char buff[15];
    fgets(buff, 15, fin);
    N = atoi(buff);
    int i = 0;
    char necklace[N + 1];
    while (i < N)
    {
        necklace[i] = fgetc(fin);
        i++;
    }

    int max = 0;
    int temp;
    for (int i = 0; i < N; i++)
    {
        temp = check(necklace, i, N);
        if ((temp > max) && temp <= N)
        {
            max = temp;
        }
    }

    fprintf(fout, "%d\n", max);

    fclose(fin);
    fclose(fout);
}
