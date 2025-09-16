#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Problem : https://cses.fi/problemset/task/1624

bool canPlace(vector<string> &board, int i, int j)
{

    for (int t = i - 1; t >= 0; t--)
    {
        if (board[t][j] == '#')
        {
            return false;
        }
    }

    int t = i - 1;
    int left = j - 1;
    int right = j + 1;

    while (t >= 0 && right < 8)
    {
        if (board[t][right] == '#')
            return false;
        t--;
        right++;
    }
    t = i - 1;
    while (t >= 0 && left >= 0)
    {
        if (board[t][left] == '#')
            return false;
        t--;
        left--;
    }

    return true;
}

void backtrack(vector<string> &board, int row, int &combinations)
{
    if (row == 8)
    {
        combinations++;
        return;
    }
    for (int j = 0; j < 8; j++)
    {
        if (board[row][j] == '.' && canPlace(board, row, j))
        {
            board[row][j] = '#';
            backtrack(board, row + 1, combinations);
            board[row][j] = '.';
        }
    }
}
int main()
{

    vector<string> board(8, "");
    for (int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }

    int combinations = 0;
    backtrack(board, 0, combinations);
    cout << combinations;
    return 0;
}
