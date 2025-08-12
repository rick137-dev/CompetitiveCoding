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

/*
Simple dfs on graph, with directed graphs we can use DP by saving status of explored non-cycle-containing parts of the graph,
keeping the algorithm O(n)
*/

bool explore(vector<vector<int>> &Alist, int currNode, vector<int> &currExplore, vector<int> &node_status)
{
    if (node_status[currNode] == 2)
    {
        return false;
    }
    if (node_status[currNode] == 1)
    {
        vector<int> temp = {currNode};
        for (int i = currExplore.size() - 1; i >= 0; i--)
        {
            temp.push_back(currExplore[i]);
            if (currExplore[i] == temp[0])
                break;
        }
        reverse(temp.begin(), temp.end());
        currExplore = temp;
        return true;
    }

    node_status[currNode] = 1;
    currExplore.push_back(currNode);

    for (int next : Alist[currNode])
    {
        if (explore(Alist, next, currExplore, node_status))
        {
            return true;
        }
    }

    currExplore.pop_back();
    node_status[currNode] = 2;
    return false;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> node_status(n, -1); //-1 unexplored, 1 exploring, 2 explored false
    vector<vector<int>> Alist(n);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        Alist[a].push_back(b);
    }

    vector<int> currentExplore;
    for (int i = 0; i < n; i++)
    {
        if (explore(Alist, i, currentExplore, node_status))
        {
            cout << currentExplore.size() << "\n";
            for (int i = 0; i < currentExplore.size(); i++)
            {
                cout << currentExplore[i] + 1 << " ";
            }

            return 0;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}