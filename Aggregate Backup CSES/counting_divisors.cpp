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

// Problem : https://cses.fi/problemset/task/1713/

/*
This solution constructs a list of primes less than the maximum value of x, 10^6, using the Sieve of Eratosthenes. Then to calculate the
number of divisors we use the formula utilizing the prime factorization of x. To do this we calculate for each prime that divides x
the power of that prime that such that prime^power divides x. We use that to calculate the final value of number of divisors.
*/

int primePower(int &x, int p) // x is passed by reference to make numDivisors work later on, to make sure it works in the edge case when x is prime
{
    if (x == 0)
    {
        return 0;
    }
    if (x == 1)
        return 0;

    int power = 0;

    while (x % p == 0)
    {
        x = x / p;
        power++;
    }

    return power;
}

int numDivisors(int x, vector<int> &primes)
{
    if (x == 0)
    {
        return 0;
    }
    if (x == 1)
        return 1;

    int total = 1;

    for (int i = 0; i < primes.size() && 1LL * primes[i] * primes[i] <= x; i++) // 1LL for overflow prevention
    {
        if (x % primes[i] == 0)
        {
            total = total * (1 + primePower(x, primes[i]));
        }
    }
    if (x > 1)
        total *= 2;
    return total;
}

int main()
{
    int M = 1e6 + 1;
    vector<int> nums(M);
    for (int i = 0; i < M; i++)
    {
        nums[i] = 1;
    }

    for (int i = 2; i * i < M; i++)
    {
        if (nums[i] == 1)
        {
            for (int j = i * i; j < M; j = j + i)
            {
                nums[j] = 0;
            }
        }
    }

    nums[1] = 0;
    nums[0] = 0;

    vector<int> primes;
    for (int i = 2; i < M; i++)
    {
        if (nums[i] == 1)
        {
            primes.push_back(i);
        }
    }

    int n;
    cin >> n;
    int x;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cout << numDivisors(x, primes) << "\n";
    }

    return 0;
}