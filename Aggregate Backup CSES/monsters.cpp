
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

// Problem : https://cses.fi/problemset/task/1194

vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

/*
The main idea behind this solution is multi-source BFS, running a BFS from both every monster and the player,
and check if the player can reach a border
*/

int main()
{

    int m, n;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    vector<vector<pair<int, int>>> previous(n, vector<pair<int, int>>(m));

    queue<pair<int, int>> playerQueue;
    queue<pair<int, int>> monsterQueue;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'A')
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    cout << "YES\n";
                    cout << 0;
                    return 0;
                }
                previous[i][j] = {-1, -1};
                playerQueue.push({i, j});
            }
            if (board[i][j] == 'M')
            {
                monsterQueue.push({i, j});
            }
        }
    }

    int size;

    while (!playerQueue.empty()) // I only check playerQueue in case monsters have fully finished exploring but not player
    {

        size = monsterQueue.size();
        for (int i = 0; i < size; i++)
        {
            pair<int, int> temp = monsterQueue.front();
            monsterQueue.pop();
            int x = temp.first;
            int y = temp.second;
            for (auto [dx, dy] : directions)
            {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != '#' && board[nx][ny] != 'M')
                {
                    board[nx][ny] = 'M';
                    monsterQueue.push({nx, ny});
                }
            }
        }

        size = playerQueue.size();

        for (int i = 0; i < size; i++)
        {
            pair<int, int> temp = playerQueue.front();
            playerQueue.pop();

            int x = temp.first;
            int y = temp.second;
            for (auto [dx, dy] : directions)
            {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    if (board[nx][ny] == '.')
                    {
                        board[nx][ny] = 'A';
                        previous[nx][ny] = {x, y};
                        playerQueue.push({nx, ny});
                    }
                }
                else
                {
                    cout << "YES\n";

                    vector<pair<int, int>> path;
                    int curr_x = x;
                    int curr_y = y;

                    while (curr_x != -1 && curr_y != -1)
                    {
                        path.push_back({curr_x, curr_y});
                        pair<int, int> prev = previous[curr_x][curr_y];
                        curr_x = prev.first;
                        curr_y = prev.second;
                    }

                    reverse(path.begin(), path.end());

                    cout << path.size() - 1 << "\n";

                    for (int i = 1; i < path.size(); i++)
                    {
                        int dx = path[i].first - path[i - 1].first;
                        int dy = path[i].second - path[i - 1].second;
                        if (dx == 1 && dy == 0)
                            cout << 'D';
                        else if (dx == -1 && dy == 0)
                            cout << 'U';
                        else if (dx == 0 && dy == 1)
                            cout << 'R';
                        else if (dx == 0 && dy == -1)
                            cout << 'L';
                    }
                    return 0;

                    return 0;
                }
            }
        }
    }

    cout << "NO";
    return 0;
}