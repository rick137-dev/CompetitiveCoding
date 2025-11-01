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

// Problem : https://cses.fi/problemset/task/3112/

// This is a simple binary search problem, this is an interactive problem so the program judge takes in program output and gives input repeatedly.
int main()
{

    int left = 1;
    int right = 1e9;
    int mid;
    string answer;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        cout << "? " << mid << "\n";
        cin >> answer;

        if (answer == "YES")
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << "! " << left << "\n";

    return 0;
}