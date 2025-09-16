#include <vector>

/*
This Data Structure is the Disjoint Set, this specific implementation uses the size of the sets to determine the joins, another version
uses rank instead, which has the same time complexity but with a different meaning or objective in terms of set comparisons.
*/

using namespace std;
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
