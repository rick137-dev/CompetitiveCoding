#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Problem : https://cses.fi/problemset/task/1146

long long func(long long N)
{
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;
    if (N == 2)
        return 2;
    long long temp = 1;
    long long k = 0;

    while (temp * 2 <= N)
    {
        temp = temp << 1;
        k++;
    }
    return func(N - temp) + k * (temp / 2) + 1 + N - temp;
}

int main()
{
    long long N;
    cin >> N;
    cout << func(N);
    return 0;
}