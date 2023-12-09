#include <bits/stdc++.h>
using namespace std;

#define ll long long int

string get_input()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    ss >> s;
    string value = "";
    while (ss >> s)
    {
        value += s;
    }
    return value;
}

int main()
{
    ll time = stoll(get_input());
    ll record = stoll(get_input());

    ll count = 0;

    for (int j = 1; j < time / 2; j++)
    {
        if ((j * (time - j)) > record)
        {
            count = time - j + 1 - j;
            break;
        }
    }
    cout << count;
}