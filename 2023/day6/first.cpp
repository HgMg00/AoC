#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll> get_input()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    ss >> s;
    vector<ll> value;
    while (ss >> s)
    {
        value.push_back(stoi(s));
    }
    return value;
}

int main()
{
    vector<ll> times = get_input();
    vector<ll> records = get_input();

    ll mul = 1;

    for (int i = 0; i < times.size(); i++)
    {
        ll count = 0;
        
        for (int j = 1; j < times[i]/2; j++)
        {
            if ((j * (times[i] - j)) > records[i]){
                count=times[i]-j+1-j;
                break;
            }
        }
        mul *= count;
    }

    cout << mul;
}