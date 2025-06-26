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

using namespace std;

int main()
{

    int N;
    cin >> N;
    vector<int> array(N);
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }
    stack<pair<int, int>> myStack;
    vector<int> result(N);

    for (int i = 0; i < N; i++)
    {
        while (!myStack.empty() && myStack.top().second >= array[i])
        {
            myStack.pop();
        }
        if (myStack.empty())
        {
            result[i] = 0;
        }
        else
        {
            result[i] = myStack.top().first + 1;
        }

        myStack.push({i, array[i]});
    }
    for (int i = 0; i < N; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}