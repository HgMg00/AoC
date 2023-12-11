/*Get idea from
    https://github.com/vss2sn/advent_of_code/blob/master/2023/cpp/day_08b.cpp
*/

#include <bits/stdc++.h>

using namespace std;

string command;

vector<string> node_A;

map<string, pair<string, string>> nodes;

void get_nodes()
{
    string s;
    getline(cin, s);
    while (getline(cin, s))
    {
        int start = 0;
        int end = s.find(' ');
        string node = s.substr(start, end - start);

        if (node[node.length() - 1] == 'A')
        {
            node_A.emplace_back(node);
        }

        start = s.find('(');
        end = s.find(',');
        string L_node = s.substr(start + 1, end - start - 1);
        start = end + 2;
        string R_node = s.substr(start, s.length() - start - 1);
        nodes[node] = make_pair(L_node, R_node);
    }
}

long long int next_node(string s)
{
    long long int num = 0;

    for (int i = 0; i < command.length(); i++)
    {

        if (s[s.length() - 1] == 'Z')
            break;

        if (command[i] == 'R')
        {
            s = nodes[s].second;
        }
        else
        {
            s = nodes[s].first;
        }
        num++;

        if (i == command.length() - 1)
            i = -1;
    }
    return num;
}

long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    getline(cin, command);

    get_nodes();

    long long int count = 1;

    for (auto &&i : node_A)
    {
        count = count / gcd(count, next_node(i)) * next_node(i);
    }

    cout << count;
}