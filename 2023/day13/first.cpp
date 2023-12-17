#include <bits/stdc++.h>
using namespace std;

long long int sum = 0;

/**
 * @brief Convert N*M matrix to M*N matrix
 * @param [in] pattern original
 * @return vector<string> the pattern converted
 */
vector<string> exchange(vector<string> pattern)
{
    vector<string> exchanged;

    for (int i = 0; i < pattern[0].length(); i++)
    {
        string s;
        for (int j = 0; j < pattern.size(); j++)
        {
            s += pattern[j][i];
        }
        exchanged.emplace_back(s);
    }

    return exchanged;
}

/**
 * @brief Calculate the number of rows when the pattern reflects across the horizontal
 * @param [in] i The position of the first line
 * @param [in] j The position corresponding to the first line during reflection
 * @param [in] pattern
 * @return int Reflection line position
 */
int horizontal(int i, int j, vector<string> pattern)
{
    int middle = (j - i) % 2 == 0 ? (j - i) / 2 : (j - i) / 2 + 1;

    if (middle < 1)
        return 0;
    for (int k = 0; k < middle; k++)
    {
        if (pattern[i++] != pattern[j--] || i == j)
            return 0;
    }

    return i;
}

/**
 * @brief solution : Vertical and horizontal can be regarded as the same,
 *                  as long as the direction is reversed,
 *                  here the vertical is converted into horizontal,
 *                  because the horizontal is easy to calculate.
 * @param [in] pattern
 */
void solution(vector<string> pattern)
{
    vector<string> exchanged = exchange(pattern);

    int j = pattern.size() - 1;
    for (int i = 0; i < pattern.size(); i++)
    {
        sum += (horizontal(0, j - i, pattern) * 100);
        sum += (horizontal(i, j, pattern) * 100);
    }

    j = exchanged.size() - 1;
    for (int i = 0; i < exchanged.size(); i++)
    {
        sum += (horizontal(0, j - i, exchanged));
        sum += (horizontal(i, j, exchanged));
    }
}

int main()
{
    vector<vector<string>> pattern;
    string s;

    vector<string> block;
    while (getline(cin, s))
    {

        if (s.length() == 0)
        {
            pattern.emplace_back(block);
            block.clear();
            continue;
        }
        block.emplace_back(s);
    }
    pattern.emplace_back(block);

    for (auto &&i : pattern)
    {
        solution(i);
    }

    cout << sum;
}