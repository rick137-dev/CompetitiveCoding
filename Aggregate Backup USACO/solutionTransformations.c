
/*
ID: caiulor1
LANG: C
PROG: transform
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int checkSameMatrix(int N, int matrix1[N][N], int matrix2[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int checkReflection(int N, int matrix1[N][N], int matrix2[N][N])
{
    int tempo;
    int max = N / 2;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < max; j++)
        {
            tempo = matrix1[i][j];
            matrix1[i][j] = matrix1[i][N - 1 - j];
            matrix1[i][N - 1 - j] = tempo;
        }
    }
    return checkSameMatrix(N, matrix1, matrix2);
}

int checkRotation(int N, int matrix1[N][N], int matrix2[N][N])
{
    int tempMatrix[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tempMatrix[i][j] = matrix1[N - 1 - j][i];
        }
    }
    if (checkSameMatrix(N, tempMatrix, matrix2) == 1)
    {
        return 1;
    }
    else
    {
        int tempMatrix2[N][N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                tempMatrix2[i][j] = tempMatrix[N - 1 - j][i];
            }
        }
        if (checkSameMatrix(N, tempMatrix2, matrix2))
        {
            return 2;
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    tempMatrix[i][j] = tempMatrix2[N - 1 - j][i];
                }
            }

            if (checkSameMatrix(N, tempMatrix, matrix2))
            {
                return 3;
            }
        }
    }
    return 0;
}

void main()
{

    FILE *fin = fopen("transform.in", "r");
    FILE *fout = fopen("transform.out", "w");

    char temp;
    int N;
    temp = fgetc(fin);
    N = atoi(&temp);
    int i = 0;
    char buffer[40];
    int container[2 * N][2 * N];
    int j;
    char comp = *"@";
    fgets(buffer, 40, fin);
    for (i = 0; i < 2 * N; i++)
    {
        fgets(buffer, 40, fin);
        for (j = 0; j < N; j++)
        {
            if (buffer[j] == comp)
            {
                container[i][j] = 1;
            }
            else
            {
                container[i][j] = 0;
            }
        }
    }

    int first[N][N];
    int second[N][N];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            first[i][j] = container[i][j];
        }
    }
    for (i = N; i < 2 * N; i++)
    {
        for (j = 0; j < N; j++)
        {
            second[i - N][j] = container[i][j];
        }
    }

    int final;
    if (checkRotation(N, first, second) != 0)
    {
        final = checkRotation(N, first, second);
    }
    else if (checkReflection(N, first, second) != 0)
    {
        final = 4;
    }
    else if (checkSameMatrix(N, first, second) != 0)
    {
        final = 6;
    }
    else
    {

        if (checkRotation(N, first, second) != 0)
        {
            final = 5;
        }
        else
        {
            final = 7;
        }
    }

    fprintf(fout, "%d\n", final);

    fclose(fin);
    fclose(fout);
}
