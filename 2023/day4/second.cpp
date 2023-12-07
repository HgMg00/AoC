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

int num_copies(vector<string> win_nums, vector<string> nums)
{
    int count = 0;
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
    return count;
}
int main()
{
    string s;
    vector<string> win_nums;
    vector<string> nums;
    map<int,int> num_cards;
    map<int, string> original_cards;
    int i = 1;
    while (getline(cin, s))
    {
        num_cards[i]=1;
        original_cards[i] = s;
        i++;
    }

    for (int i = 1; i <= original_cards.size(); i++)
    {
        s=original_cards[i];
        int colon = s.find(':');
        int vertcal_bar = s.find('|');
        int count = 0;
        win_nums = split(s.substr(colon + 1, vertcal_bar - colon - 1));
        nums = split(s.substr(vertcal_bar + 1, s.length() - vertcal_bar + 1));
        count = num_copies(win_nums, nums);


        for (int j = 0, k = i + 1; j < count; j++, k++)
        {
          
            num_cards[k]+=num_cards.find(i)->second;
        }
    }
    int sum=0;
    for (auto &&i : num_cards)
    {
        sum+=i.second;
    }
    

    cout << sum << endl;
}