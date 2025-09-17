
#include <vector>

using namespace std;

class StaticMinimumRangeQuery
{
private:
    vector<int> numbers;
    vector<vector<int>> MinimumRange;
    vector<int> log_2;

public:
    StaticMinimumRangeQuery(vector<int> inputNums)
    {
        numbers = inputNums;
        generateMinimumRange();
    }

    void generateMinimumRange()
    {
        int size = numbers.size();

        log_2.assign(size + 1, 0);
        for (int i = 2; i <= size; ++i)
            log_2[i] = log_2[i / 2] + 1;

        int max_pow = log_2[size];
        MinimumRange.resize(size);

        for (int i = 0; i < size; i++)
        {
            MinimumRange[i].resize(max_pow + 1);
        }

        for (int start = 0; start < size; start++)
        {
            MinimumRange[start][0] = numbers[start];
        }

        for (int k = 1; k <= max_pow; ++k)
        {
            int length = 1 << k;
            int half = 1 << (k - 1);

            for (int i = 0; i + length <= size; ++i)
            {
                MinimumRange[i][k] = min(MinimumRange[i][k - 1], MinimumRange[i + half][k - 1]);
            }
        }
    }

    int getMinimum(int a, int b)
    {
        if (b < a)
        {
            swap(a, b);
        }
        int length = b - a + 1;
        int k = log_2[length];
        return min(MinimumRange[a][k], MinimumRange[b - (1 << k) + 1][k]);
    }
};