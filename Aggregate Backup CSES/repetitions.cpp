
#include <iostream>

#include <string>
#include <vector>

using namespace std;

// Problem : https://cses.fi/problemset/task/1069

int main()
{
    string input;
    cin >> input;
    int max_len = 0;
    int curr_len = 1;
    char curr_char = input[0];

    for (int i = 1; i < input.length(); i++)
    {
        if (input[i] == curr_char)
        {
            curr_len++;
        }
        else
        {
            curr_char = input[i];
            max_len = max(max_len, curr_len);
            curr_len = 1;
        }
    }
    max_len = max(max_len, curr_len);

    cout << max_len << endl;
    return 0;
}
