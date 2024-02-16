
/*
ID: caiulor1
LANG: C
PROG: milk
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main()
{
    FILE *fin = fopen("milkin.txt", "r");
    FILE *fout = fopen("milkout.txt", "w");

    fclose(fin);
    fclose(fout);
}
