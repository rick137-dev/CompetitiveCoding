#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Problem : https://cses.fi/problemset/task/1192

static vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(vector<string> &grid, int i, int j)
{
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].length() || grid[i][j] == '#')
        return;

    grid[i][j] = '#';

    for (const auto &[dx, dy] : directions)
    {
        dfs(grid, i + dy, j + dx);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    string temp;

    int total_rooms = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                total_rooms++;
                dfs(grid, i, j);
            }
        }
    }

    cout << total_rooms;
    return 0;
}