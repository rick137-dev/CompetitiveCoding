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

// Couse Schedule solved through Khan's Algorithm, a BFS based approach to Topological Sort
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> requirements;
    vector<int> inCount(n, 0);
    int a, b;
    vector<vector<int>> Alist(n);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        Alist[a].push_back(b);
        inCount[b]++;
    }

    vector<int> order;
    queue<int> myQueue;
    for (int i = 0; i < n; i++)
    {
        if (inCount[i] == 0)
        {
            myQueue.push(i);
            inCount[i] = -1;
        }
    }

    while (!myQueue.empty())
    {
        int temp = myQueue.front();
        myQueue.pop();
        order.push_back(temp);
        for (int next : Alist[temp])
        {
            inCount[next]--;
            if (inCount[next] == 0)
            {
                myQueue.push(next);
                inCount[next] = -1;
            }
        }
    }

    if (order.size() != n)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (int node : order)
        {
            cout << node + 1 << " ";
        }
    }
    return 0;
}