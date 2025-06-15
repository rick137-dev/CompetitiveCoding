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

using namespace std;

// Utilized bfs for graph traversal, using # as visited and pointers to previous nodes to reconstruct the path string to B node if reachable
struct Node
{

    int posy;
    int posx;
    char next_step;
    int prev; // pointer to previous node in queue
};

bool canVisit(vector<string> &grid, int i, int j)
{
    return !(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '#' || grid[i][j] == 'A');
}

bool bfs(vector<string> &grid, int i, int j, string &best_path)
{
    vector<Node> nodes;
    queue<int> q;

    nodes.push_back({i, j, 0, -1});
    q.push(0);
    grid[i][j] = '#';

    while (!q.empty())
    {
        int idx = q.front();
        q.pop();

        int y = nodes[idx].posy;
        int x = nodes[idx].posx;

        if (grid[y][x] == 'B')
        {
            string path;
            for (int at = idx; nodes[at].prev != -1; at = nodes[at].prev)
            {
                path.push_back(nodes[at].next_step);
            }

            reverse(path.begin(), path.end());
            best_path = path;
            return true;
        }

        // right
        if (canVisit(grid, y, x + 1))
        {
            if (grid[y][x + 1] != 'B')
            {
                grid[y][x + 1] = '#';
            }
            nodes.push_back({y, x + 1, 'R', idx});
            q.push(nodes.size() - 1);
        }

        // left
        if (canVisit(grid, y, x - 1))
        {

            if (grid[y][x - 1] != 'B')
            {
                grid[y][x - 1] = '#';
            }
            nodes.push_back({y, x - 1, 'L', idx});
            q.push(nodes.size() - 1);
        }

        // up
        if (canVisit(grid, y - 1, x))
        {

            if (grid[y - 1][x] != 'B')
            {
                grid[y - 1][x] = '#';
            }
            nodes.push_back({y - 1, x, 'U', idx});
            q.push(nodes.size() - 1);
        }

        // down
        if (canVisit(grid, y + 1, x))
        {
            if (grid[y + 1][x] != 'B')
            {
                grid[y + 1][x] = '#';
            }
            nodes.push_back({y + 1, x, 'D', idx});
            q.push(nodes.size() - 1);
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    string best_path;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {

                if (bfs(grid, i, j, best_path))
                {
                    cout << "YES\n";
                    cout << best_path.length() << "\n";
                    cout << best_path;
                }
                else
                {
                    cout << "NO";
                }

                return 0;
            }
        }
    }

    return 0;
}