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

struct DisjointSet
{
    vector<int> parent;
    vector<int> size;
    int number_distinct_sets;
    int largest_set_size;

    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n);
        number_distinct_sets = n;
        largest_set_size = 1;

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
            return parent[x] = find(parent[x]);
        return x;
    }

    void join(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        number_distinct_sets--;

        if (size[x] < size[y])
        {
            parent[x] = y;
            size[y] += size[x];
            largest_set_size = max(largest_set_size, size[y]);
        }
        else
        {
            parent[y] = x;
            size[x] += size[y];
            largest_set_size = max(largest_set_size, size[x]);
        }
    }

    int getNumberSets()
    {
        return number_distinct_sets;
    }
    int getLargestSize()
    {
        return largest_set_size;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    DisjointSet myDSU(n);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        myDSU.join(a, b);
        cout << myDSU.getNumberSets() << " " << myDSU.getLargestSize() << "\n";
    }

    return 0;
}