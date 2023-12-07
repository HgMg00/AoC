#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s)
{
    stringstream ss(s);
    vector<string> nums;
    string word;
    while (ss >> word)
    {
        nums.push_back(word);
    }
    return nums;
}

int main()
{
    string s;
    vector<string> win_nums;
    vector<string> nums;
    int sum = 0;
    while (getline(cin,s))
    {
        int colon = s.find(':');
        int vertcal_bar = s.find('|');
        int count = 0;
        win_nums = split(s.substr(colon + 1, vertcal_bar - colon-1));
        nums = split(s.substr(vertcal_bar + 1, s.length() - vertcal_bar + 1));

        for (int i = 0; i < nums.size(); i++)
        {
            for (auto &&j : win_nums)
            {
                if (j == nums[i])
                {
                    count++;
                }
            }
        }
        sum += pow(2, count - 1);
    }
    cout << sum << endl;
}