#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;
void backtrack(unordered_set<string> &permutations, string &current, int index)
{
    if (index == current.size())
    {
        permutations.insert(current);
        return;
    }

    for (int i = index; i < current.size(); i++)
    {

        swap(current[i], current[index]);
        backtrack(permutations, current, index + 1);
        swap(current[i], current[index]);
    }
}

int main()
{

    string input;
    cin >> input;
    unordered_set<string> permutations;
    backtrack(permutations, input, 0);
    cout << permutations.size() << "\n";
    vector<string> result;

    for (string perm : permutations)
    {
        result.push_back(perm);
    }
    sort(result.begin(), result.end());
    for (string perm : result)
    {
        cout << perm << "\n";
    }
    return 0;
}
