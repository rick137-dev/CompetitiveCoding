
/*
ID: caiulor1
LANG: C
PROG: namenum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int checkAlphabet(int N, char buf)
{
    int final = 0;
    switch (N)
    {
    case 2:
        if ((buf == 'A' || buf == 'B' || buf == 'C'))
        {
            final = 1;
        }
        break;
    case 3:
        if ((buf == 'D' || buf == 'E' || buf == 'F'))
        {
            final = 1;
        }

        break;

    case 4:
        if ((buf == 'G' || buf == 'H' || buf == 'I'))
        {
            final = 1;
        }
        break;

    case 5:
        if ((buf == 'J' || buf == 'K' || buf == 'L'))
        {
            final = 1;
        }
        break;

    case 6:
        if ((buf == 'M' || buf == 'N' || buf == 'O'))
        {
            final = 1;
        }
        break;

    case 7:
        if ((buf == 'P' || buf == 'R' || buf == 'S'))
        {
            final = 1;
        }
        break;

    case 8:
        if ((buf == 'T' || buf == 'U' || buf == 'V'))
        {
            final = 1;
        }
        break;

    case 9:
        if ((buf == 'W' || buf == 'X' || buf == 'Y'))
        {
            final = 1;
        }
        break;

    default:
        final = 0;
        break;
    }
    return final;
}
char firstChar(char *buf)
{
    return buf[0];
}

int howLong(long long int a)
{
    int x = 0;
    while (a > 0)
    {
        x++;
        a = a / (long long)10;
    }
    return x;
}

int checkWord(long long int N, char *buffer)
{

    int len = howLong(N);
    int vector[len];
    if (strlen(buffer) == len)
    {

        for (int x = len - 1; x >= 0; x--)
        {
            vector[x] = N % 10;

            N = N / (long long)10;
        }

        for (int i = 0; i < len; i++)
        {

            if (checkAlphabet(vector[i], buffer[i]) == 0)
            {

                return 0;
            }
        }
        return 1;
    }
    else
    {

        return 0;
    }
}

void main()
{
    FILE *fin = fopen("namenumIN.txt", "r");
    FILE *fout = fopen("namenumOUT.txt", "w");
    FILE *dict = fopen("dict.txt", "r");

    char buffer[100];
    fgets(buffer, 13, fin);
    int N = strlen(buffer);

    long long int num = atoll(buffer);

    printf("%lld", num);

    int length = howLong(num);

    char word[100];
    char words[1000][100];
    int i = 0;

    while (fscanf(dict, "%s\n", word) == 1)
    {

        if ((checkWord(num, word) == 1))
        {

            strcpy(words[i], word);

            i++;
        }
    }
    if (i == 0)
    {
        fprintf(fout, "%s\n", "NONE");
    }
    else
    {
        for (int j = 0; j < i; j++)
        {
            fprintf(fout, "%s\n", words[j]);
        }
    }

    fclose(dict);
    fclose(fin);
    fclose(fout);
}
