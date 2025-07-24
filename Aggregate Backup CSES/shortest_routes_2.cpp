
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

int main()
{
    // Main idea here is simply to use Floyd Warshall algorithm. If n is large and the graph is sparse, Dijkstra's started from each query could be faster
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> distance(n, vector<long long>(n, LLONG_MAX));

    int a, b, weight;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> weight;
        a--;
        b--;
        // This is to protect against non simple graphs, where there may be more than 1 edge between the same pair of nodes
        distance[a][b] = min(distance[a][b], (long long)weight);
        distance[b][a] = min(distance[b][a], (long long)weight);
    }
    for (int i = 0; i < n; i++)
    {
        distance[i][i] = 0;
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            if (distance[i][k] == LLONG_MAX)
                continue;
            for (int j = 0; j < n; ++j)
            {
                if (distance[k][j] == LLONG_MAX)
                    continue;
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    long long temp_dist;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        temp_dist = distance[a][b];
        if (temp_dist == LLONG_MAX)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << temp_dist << "\n";
        }
    }

    return 0;
}