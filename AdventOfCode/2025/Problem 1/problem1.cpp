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

int main()
{
    ifstream file("Competitive Coding\\AdventOfCode\\2025\\Problem 1\\input.txt");

    string line;
    int total = 0;
    int position = 50;

    while (std::getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        char direction = line[0];
        int value = std::stoi(line.substr(1));

        if (direction == 'R')
        {
            position += value;
        }
        else
        {
            position = position - value;
        }
        position = (position + 100) % 100;

        if (position == 0)
        {
            total++;
        }
    }

    cout << total;
}
