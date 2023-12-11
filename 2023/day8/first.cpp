#include <bits/stdc++.h>
using namespace std;

map<string, pair<string, string>> get_nodes()
{
    string s;
    map<string, pair<string, string>> nodes;
    
    getline(cin, s);
    while (getline(cin, s))
    {
        int start = 0;
        int end = s.find(' ');
        string node = s.substr(start, end - start);
        start = s.find('(');
        end = s.find(',');
        string L_node = s.substr(start + 1, end - start - 1);
        start = end + 2;
        string R_node = s.substr(start, s.length() - start - 1);
        nodes[node] = make_pair(L_node, R_node);
    }

    return nodes;
}

int main()
{
    string s;
    getline(cin, s);

    map<string, pair<string, string>> nodes = get_nodes();

    int count = 0;
    string current_node = "AAA";
    
        for (int i=0;i<s.length();i++)
        {
            if (current_node =="ZZZ")
                break;

            if (s[i] == 'R')
                current_node = nodes[current_node].second;
            else
                current_node = nodes[current_node].first;
            
            if(i == s.length()-1)
                i=-1;

            count++;

        }
    

    cout << count;
}