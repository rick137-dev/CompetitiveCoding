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

long mod = (1e9) + 7;

// Fibonacci using binary matrix exponentiation

vector<vector<long>> multiply(vector<vector<long>> a, vector<vector<long>> b)
{
    return {
        {(a[0][0] % mod * b[0][0] % mod + a[0][1] % mod * b[1][0] % mod) % mod, (a[0][0] % mod * b[0][1] % mod + a[0][1] % mod * b[1][1] % mod) % mod},
        {(a[1][0] % mod * b[0][0] % mod + a[1][1] % mod * b[1][0] % mod) % mod, (a[1][0] % mod * b[0][1] % mod + a[1][1] % mod * b[1][1] % mod) % mod}};
}

vector<vector<long>> raisePower(vector<vector<long>> A, long long power)
{
    vector<vector<long>> base = A;
    vector<vector<long>> I = {{1, 0}, {0, 1}};
    while (power > 0)
    {
        if (power % 2 == 1)
        {
            I = multiply(base, I);
        }
        base = multiply(base, base);
        power = power / 2;
    }

    return I;
}

long findVal(vector<vector<long>> A)
{
    return (A[0][1]) % mod;
}

int main()
{
    long long N;
    cin >> N;
    if (N == 0)
    {
        cout << 0;
        return 0;
    }

    vector<vector<long>> M = {{1, 1}, {1, 0}};
    cout << findVal(raisePower(M, N));
    return 0;
}