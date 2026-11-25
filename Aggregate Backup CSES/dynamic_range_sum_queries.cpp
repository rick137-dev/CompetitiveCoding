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
#include <bit>

using namespace std;
int mod = 1e9 + 7;

// Problem : https://cses.fi/problemset/task/1648/

// This is a classic application of the Fenwick Tree data structure, since we need to efficiently update and calculate range sums on a fixed length array. Another viable data structure would have been a Segment Tree

class FenwickTree
{
public:
    vector<long long> tree;
    FenwickTree(vector<long long> nums)
    {
        tree.resize(nums.size() + 1);

        for (long long i = 1; i < tree.size(); i++)
        {
            tree[i] += nums[i - 1];

            int parent = i + (i & -i);

            if (parent < tree.size())
            {
                tree[parent] += tree[i];
            }
        }
    }

    void update(long long index, long long numToReplace)
    {
        long long oldValue = sum(index) - sum(index - 1);
        long long delta = numToReplace - oldValue;

        while (index < tree.size())
        {
            tree[index] += delta;
            index += (index & -index);
        }
    }

    long long sum(long long index)
    {
        long long currSum = 0;

        while (index > 0)
        {
            currSum += tree[index];
            index -= (index & -index);
        }

        return currSum;
    }
};

main()
{
    long long n, q;
    cin >> n >> q;
    vector<long long> nums(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    long long a, b, c;
    FenwickTree *myTree = new FenwickTree(nums);

    for (int i = 0; i < q; i++)
    {
        cin >> a >> b >> c;

        if (a == 1)
        {
            myTree->update(b, c);
        }
        else
        {
            cout << myTree->sum(c) - myTree->sum(b - 1) << "\n";
        }
    }

    return 0;
}
