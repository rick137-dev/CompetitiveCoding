
/*
ID: caiulor1
LANG: C
PROG: ride
*/

#include <stdio.h>
#include <stdlib.h>

int product(char a[8])
{
    int i;
    int f = 1;

    for (i = 0; i <= strlen(a); i++)
    {
        if (a[i] > 0 && a[i] < 100)
        {
            f = (f * (a[i] - 64)) % 47;
        }
    }
    return f;
}

void main()
{
    FILE *fin = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");

    char input1[8];
    char input2[8];
    fgets(input1, 8, fin);
    fgets(input2, 8, fin);

    if ((product(input1) - product(input2)) % 47 == 0)
    {
        fprintf(fout, "%s", "GO\n");
    }
    else
    {
        fprintf(fout, "%s", "STAY\n");
    }

    fclose(fin);
    fclose(fout);
    exit(0);
}
