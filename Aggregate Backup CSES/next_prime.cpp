
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

// Sieve methods are too memory intensive, used standard primality check with use of the fact that every prime >=3 is of the form 6k+-1, so we can skip some numbers in the division check

bool isPrime(long long x)
{
    if (x < 2)
        return false;
    if (x == 2 || x == 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;

    for (long long i = 5; i * i <= x; i += 6)
    {
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    }
    return true;
}

long nextPrime(long long x)
{
    long long start = x + 1;
    while (!isPrime(start))
    {
        start++;
    }
    return start;
}

int main()
{

    int t;
    cin >> t;

    long long temp;

    for (int i = 0; i < t; i++)
    {
        cin >> temp;
        cout << nextPrime(temp) << "\n";
    }

    return 0;
}
