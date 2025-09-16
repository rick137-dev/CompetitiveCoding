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

long outer_mod = 1e9 + 7;

// Problem : https://cses.fi/problemset/task/1712

// Here I use binary exponentiation again, in tandem with Fermat's little theorem to make it efficient
long long power(int a, long N, long mod)
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
    int a, b, c;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;
        long pow = power(b, c, outer_mod - 1); // Here I use Fermat's little theorem since mod is prime
        cout << power(a, pow, outer_mod) << "\n";
    }
    return 0;
}