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
 * @brief count how many characters are different.
 * @param [in] a first string
 * @param [in] b second string
 * @return int number of times
 */
int oneSmudge(string a, string b)
{
    int count = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
            count++;
    }
    return count;
}

/**
 * @brief Calculate the number of rows when the pattern reflects across the horizontal
 * @param [in] i The position of the line
 * @param [in] j The position corresponding to the line during reflection
 * @param [in] pattern
 * @return int Reflection line position
 */
int horizontal(int i, int j, vector<string> pattern)
{
    int start=i;
    int smudge=0;
    while (i >= 0 && j<pattern.size())
    {
        smudge+=oneSmudge(pattern[i--],pattern[j++]);

        if (smudge >1)
            return 0;
    }
    if (smudge==1)
        return start+1;

    return 0;
}

/**
 * @brief solution : Search from the inside out, making sure Smudge equals 1.
 *      Get idea from
 *      https://github.com/maksverver/AdventOfCode/blob/master/2023/13.py
 * @param [in] pattern
 */
void solution(vector<string> pattern)
{
    vector<string> exchanged= exchange(pattern);
    for (int i = 0; i < pattern.size()-1;i++)
    {
        sum+=horizontal(i,i+1,pattern)*100;
    }

    for (int i = 0; i < exchanged.size()-1;i++)
    {
        sum+=horizontal(i,i+1,exchanged);
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