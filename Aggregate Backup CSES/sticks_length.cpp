#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

// it can be proven that the number x which minimizes the sum of the absolute values of (x-array[i]) is the Median of the array

int main()
{
    int N;
    cin >> N;
    vector<long long> array(N);
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }
    sort(array.begin(), array.end());

    long long median;

    if (N % 2 == 0)
    {
        median = (array[N / 2] + array[(N / 2) - 1]) / 2;
    }
    else
    {
        median = array[N / 2];
    }
    long long total = 0;
    for (int i = 0; i < N; i++)
    {
        total += abs(array[i] - median);
    }
    cout << total;

    return 0;
}