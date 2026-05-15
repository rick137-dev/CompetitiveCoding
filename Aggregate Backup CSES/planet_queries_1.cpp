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
// Problem : https://cses.fi/problemset/task/1750/

// Solution using standard Binary Lifting
int findPlanet(int x, int k, vector<vector<int>> &binaryTeleport)
{
    for (int jump = 0; jump <= 30; jump++)
    {
        if (k & (1 << jump))
        {
            x = binaryTeleport[x][jump];
        }
    }

    return x;
}

int main()
{
    // Makes IO faster, sometimes causes TLE if not used
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    int LOG = 30; // This is 30 since k is at most 10^9

    vector<vector<int>> binaryTeleport(n, vector<int>(LOG + 1));
    vector<int> teleporters(n);

    for (int i = 0; i < n; i++)
    {
        int planet;
        cin >> planet;
        teleporters[i] = planet - 1;
    }

    for (int jump = 0; jump <= LOG; jump++)
    {
        for (int i = 0; i < n; i++)
        {

            if (jump == 0)
            {
                binaryTeleport[i][0] = teleporters[i];
            }
            else
            {
                binaryTeleport[i][jump] = binaryTeleport[binaryTeleport[i][jump - 1]][jump - 1];
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int planet, distance;
        cin >> planet >> distance;
        cout << findPlanet(planet - 1, distance, binaryTeleport) + 1 << "\n";
    }

    return 0;
}
