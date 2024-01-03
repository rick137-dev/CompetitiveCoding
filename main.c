
/*
ID: caiulor1
LANG: C
PROG: namenum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main()
{
    FILE *fin = fopen("namenumIN.txt", "r");
    FILE *fout = fopen("namenumOUT.txt", "w");

    fclose(fin);
    fclose(fout);
}
