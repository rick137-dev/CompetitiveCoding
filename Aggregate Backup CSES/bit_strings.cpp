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

long mod = 1e9 + 7;

// Problem : https://cses.fi/problemset/task/1617

long long power(int N)
{
    long long result = 1;
    long long base = 2;
    while (N > 0)
    {
        if (N % 2 == 1)
        {
            result = ((result % mod) * (base % mod)) % mod;
        }
        base = ((base % mod) * (base % mod)) % mod;
        N = N / 2;
    }
    return result % mod;
}
int main()
{
    int N;
    cin >> N;
    long long test = power(N);
    cout << test;
    return 0;
}