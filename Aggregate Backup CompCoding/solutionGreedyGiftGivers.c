
/*
ID: caiulor1
LANG: C
PROG: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char names[][30], char name[], int numNames)
{
    int i;
    for (i = 0; i < numNames; i++)
    {

        if (strcmp(names[i], name) == 0)
        {

            return i;
        }
    }
    return -1;
}

void main()
{

    FILE *fin = fopen("gift1.in", "r");
    FILE *fout = fopen("gift1.out", "w");

    int NP;
    char NPC[10];
    fgets(NPC, 10, fin);
    NP = atoi(NPC);
    int listMoney[NP];
    for (int i = 0; i < NP; i++)
    {
        listMoney[i] = 0;
    }

    char listNames[NP][30];

    for (int i = 0; i < NP; i++)
    {
        fgets(listNames[i], 30, fin);
        strtok(listNames[i], "\n");
    }

    char buff[30];
    int amount, numP;

    int step = 1;
    int toGive;

    do
    {

        fgets(buff, 30, fin);
        strtok(buff, "\n");
        fscanf(fin, "%d %d\n", &amount, &numP);
        if (numP != 0)
        {
            toGive = amount - (amount % numP);
            listMoney[find(listNames, buff, NP)] = listMoney[find(listNames, buff, NP)] - toGive;

            toGive = toGive / numP;

            for (int i = 0; i < numP; i++)
            {
                fgets(buff, 30, fin);
                strtok(buff, "\n");
                listMoney[find(listNames, buff, NP)] = listMoney[find(listNames, buff, NP)] + toGive;
            }
        }
        step++;
    } while (step <= NP);

    for (int i = 0; i < NP; i++)
    {

        fprintf(fout, "%s %d\n", listNames[i], listMoney[i]);
    }

    fclose(fin);
    fclose(fout);
}
