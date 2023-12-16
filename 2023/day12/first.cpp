/*
Get idea from
https://github.com/maksverver/AdventOfCode/blob/master/2023/day12/solve-dp.py
*/

#include <bits/stdc++.h>
using namespace std;

int solution(string symbol, vector<int> nums)
{
    vector<int> max_hashes(symbol.size() + 1);

    for (int i = 0; i < symbol.size(); i++)
    {
        if (symbol[i] != '.')
            max_hashes[i + 1] = max_hashes[i] + 1;
    }

    vector<vector<int>> dp;
    dp.resize(nums.size() + 1, vector<int>(symbol.size() + 1));

    dp[0][0] = 1;

    for (int i = 0; i < symbol.size(); i++)
    {
        if (symbol[i] == '#')
            break;

        dp[0][i + 1] = 1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < symbol.size(); j++)
        {
            if (symbol[j] != '#')
            {
                int n;
                if (nums[i] <= max_hashes[j] && dp[i][j - nums[i]])
                {
                    n = dp[i][j - nums[i]];
                }
                else
                    n = 0;

                dp[i + 1][j + 1] = dp[i + 1][j] + n;
            }
        }
    }

    return dp[nums.size()][symbol.size()];
}

int main()
{
    string s;
    long long int sum;
    while (getline(cin, s))
    {
        int end = s.find(' ');
        string num = s.substr(end + 1, s.length() - end);
        s = s.substr(0, end);
        vector<int> n;
        for (auto &&i : num)
        {
            int start = num.find(',');
            if (start < 0)
                start = num.length();
            n.emplace_back(stoi(num.substr(0, start)));
            num = num.erase(0, start + 1);
            if (num.length() == 0)
                break;
        }

        sum += solution(s + '.', n);
    }

    cout << sum;
}