#include <bits/stdc++.h>
using namespace std;

long long int solution(string symbol, vector<int> nums)
{
    vector<int> max_hashes(symbol.size() + 1);

    for (int i = 0; i < symbol.size(); i++)
    {
        if (symbol[i] != '.')
            max_hashes[i + 1] = max_hashes[i] + 1;
    }

    vector<vector<long long int>> dp;
    dp.resize(nums.size() + 1, vector<long long int>(symbol.size() + 1));

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
                long long int n;
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
    long long int sum = 0;
    while (getline(cin, s))
    {
        int end = s.find(' ');
        string numString = s.substr(end + 1, s.length() - end);

        s = s.substr(0, end);
        string symbol = s;
        for (int i = 0; i < 4; i++)
        {
            symbol.append("?" + s);
        }

        vector<int> n;

        for (auto &&i : numString)
        {
            int start = numString.find(',');
            if (start < 0)
                start = numString.length();
            n.emplace_back(stoi(numString.substr(0, start)));
            numString = numString.erase(0, start + 1);
            if (numString.length() == 0)
                break;
        }

        vector<int> nums = n;
        for (int i = 0; i < 4; i++)
        {
            nums.insert(nums.end(), n.begin(), n.end());
        }

    

        sum += solution(symbol+'.', nums);
    }

    cout << sum;
}