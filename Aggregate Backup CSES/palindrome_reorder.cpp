#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    string input;
    cin >> input;
    vector<int> freq(26, 0);
    bool seenOdd = false;
    char odd;
    for (int i = 0; i < input.length(); i++)
    {
        freq[input[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2 == 1)
        {
            if (seenOdd)
            {
                cout << "NO SOLUTION";
                return 0;
            }
            else
            {
                seenOdd = true;
                odd = i + 'A';
            }
        }
    }
    string result = "";
    for (int i = 0; i < 26; i++)
    {
        for (int f = 0; f < freq[i] / 2; f++)
        {
            result.push_back(i + 'A');
        }
    }
    string helper = result;
    reverse(helper.begin(), helper.end());
    if (seenOdd)
    {
        result.push_back(odd);
    }
    result += helper;
    cout << result;
    return 0;
}
