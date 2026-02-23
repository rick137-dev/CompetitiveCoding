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

const long long mod = 1e9 + 7;

/*
2D Recursive solution
This is the recursive version, uses a large amount of memory and has a larger constant factor in the asymptotic time complexity.
It returns twice the number required, and when dividing one must use the modular inverse of 2 mod P instead of just standard division

*/
long long numSums(long long number, long long currentSum, vector<vector<long long>> &dp)
{
    if (currentSum < 0)
        return 0;
    if (currentSum == 0)
        return 1;
    if (number <= 0)
    {
        if (currentSum == 0)
            return 1;
        return 0;
    }
    if (dp[number][currentSum] != -1)
        return dp[number][currentSum];

    return dp[number][currentSum] = (numSums(number - 1, currentSum, dp) % mod + numSums(number - 1, currentSum - number, dp) % mod) % mod;
}

// 2D Iterative version
long long numSums2DIterative(long long N, long long target)
{
    vector<vector<long long>> dp(N + 1, vector<long long>(target + 1, 0));

    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int sum = 0; sum <= target; sum++)
        {

            dp[i][sum] = dp[i - 1][sum];

            if (sum - i >= 0)
            {
                dp[i][sum] = (dp[i][sum] + dp[i - 1][sum - i]) % mod;
            }
        }
    }

    return dp[N][target];
}

// 1D Iterative Solution
long long numSums(long long number, long long target)
{
    vector<long long> current(target + 1, 0);
    vector<long long> prev(target + 1, 0);
    prev[0] = 1;

    for (long long num = 1; num <= number; num++)
    {
        for (long long temp = 0; temp <= target; temp++)
        {
            current[temp] = prev[temp] % mod;
            if (temp - num >= 0)
            {
                current[temp] = (current[temp] % mod + prev[temp - num] % mod) % mod;
            }
        }
        swap(current, prev);
    }

    return prev[target];
}

int main()
{

    long long n;
    cin >> n;

    long long target = n * (n + 1);
    target = target / 2;

    if (target % 2 == 1)
    {
        cout << 0;
        return 0;
    }

    target = target / 2;

    const long long inverse_of_2 = 500000004; // used for the final division by 2 step

    cout << (1LL * numSums(n, target) * inverse_of_2 % mod) << endl;

    return 0;
}