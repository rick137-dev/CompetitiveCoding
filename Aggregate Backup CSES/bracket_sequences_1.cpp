#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <climits>
#include <stack>
#include <map>
#include <cmath>

using namespace std;
int mod = 1e9 + 7;

// Problem : https://cses.fi/problemset/task/2064

/*
Simple solution to finding nth Catalan number, using multiplicative formula. Since mod is larger than all n we don't have issues
with invertibility % mod.
For the division by an expression mod P, we use Fermat's Little theorem: x^-1 = x^(p-2) mod p, which I calculate using binary
exponentiation.
*/

long long exponentiate(long long base, int power)
{

    long long result = 1;

    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result = ((result % mod) * (base % mod)) % mod;
        }
        power = power / 2;
        base = ((base % mod) * (base % mod)) % mod;
    }
    return result % mod;
}

int main()
{

    int N;
    cin >> N;
    if (N % 2 == 1)
    {
        cout << 0;
        return 0;
    }
    N = N / 2;
    if (N == 0 || N == 1)
    {
        cout << 1;
        return 0;
    }

    long long current = 1;

    for (int step = 0; step < N; step++)
    {
        current = ((current % mod) * 2LL * (2LL * (step) + 1LL)) % mod;
        long long inv = exponentiate(step + 2LL, mod - 2);
        current = ((current % mod) * (inv % mod)) % mod;
    }

    cout << current;

    return 0;
}