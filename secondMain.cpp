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

using namespace std;

int main()
{
       int n, m;
       cin >> n >> m;

       int a, b;
       unordered_map<int, vector<int>> Alist;

       for (int i = 0; i < m; i++)
       {
              cin >> a >> b;
              Alist[a - 1].push_back(b - 1);
              Alist[b - 1].push_back(a - 1);
       }
       vector<int> previous(n, -1);

       return 0;
}
