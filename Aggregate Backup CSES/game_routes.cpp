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

// Problem : https://cses.fi/problemset/task/1681

int mod = 1e9 + 7;

long long dfs(int currentNode, vector<vector<int>> &Alist, vector<long long> &ways)
{
    if (ways[currentNode] != -1)
        return ways[currentNode];
    long long total = 0;

    for (int next : Alist[currentNode])
    {
        total = total % mod + dfs(next, Alist, ways) % mod;
    }

    return ways[currentNode] = total % mod;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    vector<long long> ways(n, -1);
    vector<vector<int>> Alist(n);
    ways[n - 1] = 1;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        Alist[a].push_back(b);
    }

    cout << dfs(0, Alist, ways);

    return 0;
}