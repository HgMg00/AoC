#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<ll>> get_input()
{
    string s;

    vector<vector<ll>> input;
    while (getline(cin, s))
    {
        stringstream ss(s);
        vector<ll> lst;
        while (ss >> s)
        {
            lst.emplace_back(stoll(s));
        }

        input.emplace_back(lst);
    }
    return input;
}

ll next_value(vector<ll> data)
{
    if (all_of(data.begin(), data.end(), [](int i)
               { return i == 0; }))
        return 0;

    vector<ll> next_level;
    for (int i = 1; i < data.size(); i++)
    {
        next_level.emplace_back(data[i] - data[i - 1]);
    }

    ll last_val = data[data.size() - 1];

    return last_val + next_value(next_level);
}

int main()
{
    vector<vector<ll>> dataset = get_input();

    ll sum = 0;

    for (auto &&i : dataset)
    {
        sum += next_value(i);
    }

    cout << sum << endl;
}