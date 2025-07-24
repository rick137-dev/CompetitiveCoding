
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

vector<pair<int, int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

int main()
{
    // Main idea is simply to BFS from the end point to all the possible start points, which will give the shortest path to each
    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, -1));
    board[0][0] = 0;
    queue<pair<int, int>> myQueue;
    myQueue.push({0, 0});

    int distance = 0;

    while (!myQueue.empty())
    {
        distance++;
        int size = myQueue.size();
        for (int i = 0; i < size; i++)
        {
            auto [x, y] = myQueue.front();
            myQueue.pop();

            for (auto [dx, dy] : directions)
            {
                int ux = x + dx;
                int uy = y + dy;
                if (ux >= 0 && ux < N && uy >= 0 && uy < N && board[ux][uy] == -1)
                {
                    board[ux][uy] = distance;
                    myQueue.push({ux, uy});
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}