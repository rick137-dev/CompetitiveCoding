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
// Problem : https://cses.fi/problemset/task/1095

// Solution is efficient binary exponentiation in logarithmic time
long long power(int a, int N)
{
    long long result = 1;
    long long base = a;
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
    int a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        cout << power(a, b) << "\n";
    }
    return 0;
}