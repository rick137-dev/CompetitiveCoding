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

// The naming convention here is successor even if we are axtually calculating predecessors.

int successor(int i, int k, vector<vector<int>> &succ)
{
    int v = i;
    for (int temp = 0; temp < succ.size(); temp++)
    {
        if ((k >> temp) & 1)
        {
            v = succ[temp][v];
        }
        if (v == -1)
            break;
    }
    return v;
}

int main()
{

    int n, q;
    cin >> n >> q;
    vector<int> parents(n);
    parents[0] = -1;
    int parent;
    for (int i = 1; i < n; i++)
    {
        cin >> parent;
        parent--;
        parents[i] = parent;
    }

    int LOG = ceil(log2(n)) + 1;

    vector<vector<int>> succ(LOG, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
        succ[0][i] = parents[i];
    }

    for (int k = 1; k < LOG; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (succ[k - 1][i] != -1)
            {
                succ[k][i] = succ[k - 1][succ[k - 1][i]];
            }
        }
    }

    int a, b, answer;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        answer = successor(a - 1, b, succ);
        if (answer == -1)
        {
            cout << answer << "\n";
        }
        else
        {
            cout << answer + 1 << "\n";
        }
    }

    return 0;
}
