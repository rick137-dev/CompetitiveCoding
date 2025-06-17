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

// Solution using standard straight-line analytic geometry

int main()
{
       int t;
       cin >> t;
       long x1, y1, x2, y2, x3, y3;
       long result;

       for (int i = 0; i < t; i++)
       {
              cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
              result = (x2 - x1) * y3 - ((y2 - y1) * x3 + (x2 - x1) * y1 - (y2 - y1) * x1);
              if (result == 0)
              {
                     cout << "TOUCH\n";
              }
              else if (result > 0)
              {
                     cout << "LEFT\n";
              }
              else
              {
                     cout << "RIGHT\n";
              }
       }
       return 0;
}