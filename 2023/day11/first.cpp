#include <bits/stdc++.h>

using namespace std;
vector<string> original;

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
            vector<string>::iterator it = original.begin();
            string row(original[i].length(),'.');
            original.insert(it + i, row);
            i++;
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
            for (int i = 0; i < original.size(); i++)
            {
                original[i].insert(original[i].begin()+j,'.');
            }
            j++;
        }
    }


    for (int i = 0; i < original.size(); i++)
    {
        for (int j = 0; j < original[i].length(); j++)
        {
            if (original[i][j]=='#')
                input.emplace_back(make_pair(i,j));
        }
        
    }
    
    return input;
}

int main()
{
    vector<pair<int, int>> galaxyes = get_input();

    long long int sum = 0;

    for (int i = 0; i < galaxyes.size(); i++)
    {
        for (int j = i + 1; j < galaxyes.size(); j++)
        {
            int l = abs(galaxyes[j].first - galaxyes[i].first);
            int c = abs(galaxyes[j].second - galaxyes[i].second);

            sum += l + c;
        }
    }

    cout << sum;
}