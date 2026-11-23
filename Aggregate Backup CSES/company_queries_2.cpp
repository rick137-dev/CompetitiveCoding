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
#include <bit>

using namespace std;
int mod = 1e9 + 7;

// Problem : https://cses.fi/problemset/task/1688/

// The solution to this is to use Binary Lifting, along with a binary trick to find the optimal jump length given 2 nodes at the same depth to reach the node just before the LCA
// The required precomputation is the table for Binary Lifting and the depth of each node

int findDepth(int curr, vector<int> &prev, vector<int> &depth)
{
    if (depth[curr] != -1)
    {
        return depth[curr];
    }
    return depth[curr] = 1 + findDepth(prev[curr], prev, depth);
}

int jumpUp(int node, int jumpLength, vector<vector<int>> &previous)
{
    int currJump = 0;

    while (jumpLength > 0)
    {
        if (jumpLength & 1)
        {
            node = previous[node][currJump];
        }
        currJump++;
        jumpLength = jumpLength / 2;
    }
    return node;
}

int lowestCommonAncestor(int a, int b, vector<vector<int>> &previous, vector<int> &depth)
{
    if (depth[a] > depth[b])
    {
        return lowestCommonAncestor(b, a, previous, depth);
    }

    b = jumpUp(b, depth[b] - depth[a], previous);

    if (a == b)
        return a;

    int log = previous[0].size() - 1; // trick to get a large power of 2 so we can go donwwards from that

    while (log >= 0)
    {
        if (previous[a][log] != previous[b][log])
        {
            a = previous[a][log];
            b = previous[b][log];
        }
        log--;
    }

    return previous[a][0];
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> prev(n);
    prev[0] = 0;
    int next;
    for (int i = 1; i < n; i++)
    {
        cin >> next;
        next--;
        prev[i] = next;
    }

    vector<int> depth(n, -1);
    depth[0] = 0;
    for (int i = 1; i < n; i++)
    {
        findDepth(i, prev, depth);
    }

    int LOG = 32 - __builtin_clz(static_cast<unsigned>(n));
    vector<vector<int>> previous(n, vector<int>(LOG));

    for (int dist = 0; dist < LOG; dist++)
    {
        for (int i = 0; i < n; i++)
        {

            if (dist == 0)
            {
                previous[i][dist] = prev[i];
            }
            else
            {
                previous[i][dist] = previous[previous[i][dist - 1]][dist - 1];
            }
        }
    }

    int a, b;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        cout << lowestCommonAncestor(a, b, previous, depth) + 1 << "\n";
    }

    return 0;
}
