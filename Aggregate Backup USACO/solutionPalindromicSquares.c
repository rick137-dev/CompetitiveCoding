
/*
ID: caiulor1
LANG: C
PROG: palsquare
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char convertNumber(int a)
{
    switch (a)
    {
    case 0:
        return '0';
        break;
    case 1:
        return '1';
        break;
    case 2:
        return '2';
        break;
    case 3:
        return '3';
        break;
    case 4:
        return '4';
        break;
    case 5:
        return '5';
        break;
    case 6:
        return '6';
        break;
    case 7:
        return '7';
        break;
    case 8:
        return '8';
        break;
    case 9:
        return '9';
        break;
    case 10:
        return 'A';
        break;
    case 11:
        return 'B';
        break;
    case 12:
        return 'C';
        break;
    case 13:
        return 'D';
        break;
    case 14:
        return 'E';
        break;
    case 15:
        return 'F';
        break;
    case 16:
        return 'G';
        break;
    case 17:
        return 'H';
        break;
    case 18:
        return 'I';
        break;
    case 19:
        return 'J';
        break;
    }
}

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

// returns array, a (base10) transformed to base b
int transform(int a, int base, int *array)
{
    int tempArray[50];
    int start = 0;
    int temp = a;
    while (temp > 0)
    {
        tempArray[start] = temp % base;
        temp = temp / base;
        start++;
    }
    for (int i = 0; i < start; i++)
    {
        array[start - i - 1] = tempArray[i];
    }

    return start;
}

void main()
{

    FILE *fin = fopen("palsquare.in", "r");
    FILE *fout = fopen("palsquare.out", "w");

    int Base;
    fscanf(fin, "%d", &Base);
    int tempNumber[50];
    int start;

    for (int N = 1; N <= 300; N++)
    {
        if (checkPalindromeBase(N * N, Base))
        {
            start = transform(N, Base, tempNumber);
            for (int i = 0; i < start; i++)
            {
                fprintf(fout, "%c", convertNumber(tempNumber[i]));
            }
            fprintf(fout, " ");
            start = transform(N * N, Base, tempNumber);
            for (int i = 0; i < start; i++)
            {
                fprintf(fout, "%c", convertNumber(tempNumber[i]));
            }
            fprintf(fout, "\n");
        }
    }

    fclose(fin);
    fclose(fout);
}
