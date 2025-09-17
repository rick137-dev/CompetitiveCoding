
#include <vector>

using namespace std;

class StaticMaximumRangeQuery
{
private:
    vector<int> numbers;
    vector<vector<int>> MaximumRange;
    vector<int> log_2;

public:
    StaticMaximumRangeQuery(vector<int> inputNums)
    {
        numbers = inputNums;
        generateMaximumRange();
    }

    void generateMaximumRange()
    {
        int size = numbers.size();

        log_2.assign(size + 1, 0);
        for (int i = 2; i <= size; ++i)
            log_2[i] = log_2[i / 2] + 1;

        int max_pow = log_2[size];
        MaximumRange.resize(size);

        for (int i = 0; i < size; i++)
        {
            MaximumRange[i].resize(max_pow + 1);
        }

        for (int start = 0; start < size; start++)
        {
            MaximumRange[start][0] = numbers[start];
        }

        for (int k = 1; k <= max_pow; ++k)
        {
            int length = 1 << k;
            int half = 1 << (k - 1);

            for (int i = 0; i + length <= size; ++i)
            {
                MaximumRange[i][k] = max(MaximumRange[i][k - 1], MaximumRange[i + half][k - 1]);
            }
        }
    }

    int getMaximum(int a, int b)
    {
        if (b < a)
        {
            swap(a, b);
        }
        int length = b - a + 1;
        int k = log_2[length];
        return max(MaximumRange[a][k], MaximumRange[b - (1 << k) + 1][k]);
    }
};