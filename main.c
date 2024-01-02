
/*
ID: caiulor1
LANG: C
PROG:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main()
{

    FILE *fin = fopen("transformIN.txt", "r");
    FILE *fout = fopen("transformOUT.txt", "w");

    fclose(fin);
    fclose(fout);
}
