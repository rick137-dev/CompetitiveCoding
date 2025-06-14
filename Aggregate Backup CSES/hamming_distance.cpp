#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int hamming(int a, int b)
{
    int c = a ^ b;
    return __builtin_popcount(c);
}

int getNumber(const string &s)
{
    int result = 0;
    for (char c : s)
    {
        result <<= 1;
        if (c == '1')
            result |= 1;
    }
    return result;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> inputs(N);
    string temp;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        inputs[i] = getNumber(temp);
    }

    int min_hamming = K;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            min_hamming = min(min_hamming, hamming(inputs[i], inputs[j]));
        }
    }
    cout << min_hamming;
    return 0;
}
