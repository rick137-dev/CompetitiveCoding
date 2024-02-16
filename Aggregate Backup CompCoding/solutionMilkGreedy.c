
/*
ID: caiulor1
LANG: C
PROG: milk
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// main idea is to sort for price and max until we reach the required amount

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n, int arr2[])
{
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swap(&arr2[j], &arr2[j + 1]);

                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

void main()
{
    FILE *fin = fopen("milkin.txt", "r");
    FILE *fout = fopen("milkout.txt", "w");
    char buff[15];

    int TotalWanted, M;

    fscanf(fin, "%d %d\n", &TotalWanted, &M);

    int prices[M];
    int amounts[M];

    for (int i = 0; i < M; i++)
    {
        fscanf(fin, "%d %d", &prices[i], &amounts[i]);
    }
    bubbleSort(prices, M, amounts);

    int currentAmount = 0;
    int totalCost = 0;
    int i = 0;
    int tempAmount;

    while (currentAmount < TotalWanted)
    {
        for (int j = 0; j <= amounts[i]; j++)
        {
            if (currentAmount + j <= TotalWanted)
            {
                tempAmount = j;
            }
        }
        currentAmount = currentAmount + tempAmount;
        totalCost = totalCost + prices[i] * tempAmount;
        i++;
    }
    fprintf(fout, "%d\n", totalCost);

    fclose(fin);
    fclose(fout);
}
