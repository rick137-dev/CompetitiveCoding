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

// Standard DFS approach plus a few notes to remember the size of each room

vector<vector<int>> nextSteps(int a)
{
    vector<vector<int>> steps;

    if (!(a & 1))
    {
        steps.push_back({0, -1});
    }

    if (!(a & (1 << 1)))
    {
        steps.push_back({-1, 0});
    }

    if (!(a & (1 << 2)))
    {
        steps.push_back({0, 1});
    }

    if (!(a & (1 << 3)))
    {
        steps.push_back({1, 0});
    }

    return steps;
}

int explore(vector<vector<int>> &castle, int curr_i, int curr_j, int &rooms)
{
    vector<vector<int>> next_steps = nextSteps(castle[curr_i][curr_j]);
    int totalSize = 1;
    castle[curr_i][curr_j] = -rooms;

    for (auto steps : next_steps)
    {
        int next_i = curr_i + steps[0];
        int next_j = curr_j + steps[1];

        if (castle[next_i][next_j] >= 0)
        {
            totalSize += explore(castle, next_i, next_j, rooms);
        }
    }
    return totalSize;
}

int findBiggestRoom(vector<vector<int>> &castle, vector<int> &sizes)
{
    int maxSize = 1;
    for (int i = 0; i < castle.size(); i++)
    {
        for (int j = 0; j < castle[0].size(); j++)
        {
            maxSize = max(maxSize, sizes[abs(castle[i][j])]);
        }
    }
    return maxSize;
}

int destroyWall(vector<vector<int>> &castle, vector<int> &sizes, vector<vector<int>> &optimals)
{
    int maxSize = 1;
    vector<vector<int>> nextSteps = {{-1, 0}, {0, 1}}; // ordered based on sort priority, only North and East

    for (int i = 0; i < castle.size(); i++)
    {
        for (int j = 0; j < castle[0].size(); j++)
        {
            for (int k = 0; k < nextSteps.size(); k++)
            {
                int next_i = i + nextSteps[k][0];
                int next_j = j + nextSteps[k][1];

                if (next_i >= 0 && next_i < castle.size() && next_j >= 0 && next_j < castle[0].size() && castle[next_i][next_j] != castle[i][j])
                {
                    int tempSize = sizes[abs(castle[i][j])] + sizes[abs(castle[next_i][next_j])];
                    if (tempSize == maxSize)
                    {
                        optimals.push_back({i, j, k});
                    }
                    else if (tempSize > maxSize)
                    {
                        maxSize = tempSize;
                        optimals.clear();
                        optimals.push_back({i, j, k});
                    }
                }
            }
        }
    }
    return maxSize;
}

int main()
{

    int M, N;
    cin >> M >> N;
    vector<vector<int>> castle(N, vector<int>(M));
    vector<int> roomSizes;
    roomSizes.push_back(0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> castle[i][j];
        }
    }

    int numRooms = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (castle[i][j] >= 0)
            {
                numRooms++;
                roomSizes.push_back(explore(castle, i, j, numRooms));
            }
        }
    }

    vector<vector<int>> optimals;

    cout << numRooms << "\n";
    cout << findBiggestRoom(castle, roomSizes) << "\n";
    cout << destroyWall(castle, roomSizes, optimals) << "\n";

    sort(optimals.begin(), optimals.end(), [](vector<int> &a, vector<int> &b)
         {
             if (a[1] != b[1])
                 return a[1] < b[1]; 
             if (a[0] != b[0])
                 return a[0] > b[0]; 
             return a[2] < b[2]; });

    cout << optimals[0][0] + 1 << " " << optimals[0][1] + 1 << " ";
    if (optimals[0][2] == 0)
    {
        cout << "N\n";
    }
    else
    {
        cout << "E\n";
    }
}
