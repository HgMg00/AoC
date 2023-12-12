#include <bits/stdc++.h>

using namespace std;
vector<string> original;
vector<int> nothing_row;
vector<int> nothing_col;

vector<pair<int, int>> get_input()
{
    string s;
    vector<pair<int, int>> input;
    while (getline(cin, s))
    {
        original.emplace_back(s);
    }

    for (int i = 0; i < original.size(); i++)
    {
        if (original[i].find('#') == string::npos)
        {
            nothing_row.emplace_back(i);
        }
    }

    for (int j = 0; j < original[0].length(); j++)
    {
        bool check_vertical = false;
        for (int i = 0; i < original.size(); i++)
        {
            if (original[i][j] == '#')
            {
                check_vertical = 1;
                break;
            }
        }

        if (!check_vertical)
        {
            nothing_col.emplace_back(j);
        }
    }

    for (int i = 0; i < original.size(); i++)
    {
        for (int j = 0; j < original[i].length(); j++)
        {
            if (original[i][j] == '#')
                input.emplace_back(make_pair(i, j));
        }
    }

    return input;
}

int main()
{
    vector<pair<int, int>> galaxyes = get_input();

    long long int sum = 0;

    int times=1000000;

    for (int i = 0; i < galaxyes.size(); i++)
    {
        for (int j = i + 1; j < galaxyes.size(); j++)
        {
            int num_r_nothing = 0;
            for (auto &&row : nothing_row)
            {
                if (row > galaxyes[i].first && row < galaxyes[j].first)
                    num_r_nothing++;
            }

            int r = abs(galaxyes[j].first - galaxyes[i].first) + (num_r_nothing * (times - 1));

            int num_c_nothing = 0;
            for (auto &&col : nothing_col)
            {
                int min_col=min(galaxyes[i].second,galaxyes[j].second);
                int max_col=max(galaxyes[i].second,galaxyes[j].second);
                if (col > min_col && col < max_col)
                    num_c_nothing++;
            }

            int c = abs(galaxyes[j].second - galaxyes[i].second) + (num_c_nothing * (times - 1));

            sum += r + c;
        }
    }

    cout << sum;
}