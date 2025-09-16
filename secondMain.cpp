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

class StaticMinimumRangeQuery
{
private:
    vector<int> numbers;
    vector<vector<int>> MinimumRange;

public:
    StaticMinimumRangeQuery(vector<int> inputNums)
    {
        numbers = inputNums;
        generateMinimumRange();
    }

    void generateMinimumRange()
    {
    }

    int getMinimum(int a, int b)
    {
        return MinimumRange[a][b];
    }
};

int main()
{

    return 0;
}