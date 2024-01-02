
/*
ID: caiulor1
LANG: C
PROG: dualpal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPalindromeBase(int a, int base)
{

    int vector[80];
    for (int t = 0; t < 80; t++)
    {
        vector[t] = 0;
    }
    int temp = a;
    int i = 0;
    while (temp > 0)
    {
        vector[i] = temp % base;
        temp = temp / base;
        i++;
    }

    int x = 49;
    while (vector[x] == 0)
    {
        x--;
    }

    i = 0;
    int j = x;
    while (j > i)
    {
        if (vector[i] != vector[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int checkPalindromeTotal(int a)
{
    int total = 0;
    int base = 10;

    while (base >= 2)
    {
        if (a % base != 0)
        {
            total = total + checkPalindromeBase(a, base);
        }
        base--;
        if (total >= 2)
        {
            return 1;
        }
    }

    if (total < 2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void main()
{

    FILE *fin = fopen("dualpal.in", "r");
    FILE *fout = fopen("dualpal.out", "w");

    int N, S;
    fscanf(fin, "%d %d", &N, &S);

    int start = S + 1;
    int found = 0;
    int founds[N];
    int i = 0;

    while (found <= N)
    {
        if (checkPalindromeTotal(start) == 1)
        {
            found++;
            founds[i] = start;
            i++;
        }
        start++;
    }

    for (i = 0; i < N; i++)
    {
        fprintf(fout, "%d\n", founds[i]);
    }

    fclose(fin);
    fclose(fout);
}
