
/*
ID: caiulor1
LANG: C++
PROG: combo
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

void convert(int N, vector<int> &lock)
{
    for (int i = 0; i < 3; i++)
    {

        lock[i] = ((lock[i] - 1 + N) % N) + 1;
    }
}

int main()
{
    ifstream inputFile("barn1in.txt");
    ofstream outputFile("barn1out.txt");
    int N;
    inputFile >> N;
    vector<int> Lock1;
    vector<int> Lock2;

    int a, b, c;
    inputFile >> a >> b >> c;
    Lock1 = {a, b, c};

    inputFile >> a >> b >> c;
    Lock2 = {a, b, c};

    set<vector<int>> combinations;

    vector<int> tempLock;
    for (int i = -2; i <= 2; i++)
    {
        for (int j = -2; j <= 2; j++)
        {
            for (int k = -2; k <= 2; k++)
            {
                tempLock = {Lock1[0] + i, Lock1[1] + j, Lock1[2] + k};
                convert(N, tempLock);
                combinations.insert(tempLock);

                tempLock = {Lock2[0] + i, Lock2[1] + j, Lock2[2] + k};
                convert(N, tempLock);
                combinations.insert(tempLock);
            }
        }
    }
    outputFile << combinations.size();

    inputFile.close();
    outputFile.close();

    return 0;
}
