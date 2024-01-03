
/*
ID: caiulor1
LANG: C
PROG: milk2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main()
{
    FILE *fin = fopen("milk2IN.txt", "r");
    FILE *fout = fopen("milk2OUT.txt", "w");

    int n;
    char buf[100];
    fgets(buf, 100, fin);
    n = atoi(buf);

    int starts[n];
    int ends[n];
    int i = 0;
    while (fgets(buf, 100, fin))
    {
        sscanf(buf, "%d %d\n", &starts[i], &ends[i]);
        i++;
    }

    fclose(fin);
    fclose(fout);
}
