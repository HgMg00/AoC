#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    long long sum = 0;
    int num = 0;
    while (getline(cin, s))
    {
        num++;
        int index = s.find(':');

        s = s.substr(index + 2, s.length());

        int valor;
        int key;
        bool check = true;
        map<string, int> lst;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ',')
                lst[s.substr(key, i - key)] = valor;

            if (isdigit(s[i]))
            {
                valor = s[i] - 48;
                if (isdigit(s[++i]))
                    valor = valor * 10 + s[i++] - 48;

                if (valor > 14)
                {
                    check = false;
                    break;
                }
                key = ++i;
            }

            if (s[i] == ';' || i == s.length() - 1)
            {
                lst[s.substr(key, i - key)] = valor;
                if (lst["red"] > 12 ||
                    lst["green"] > 13 ||
                    lst["blue"] > 14)
                {
                    check = false;
                    break;
                }

                lst.clear();
                s = s.substr(i + 1, s.length());
                i = 0;
            }
        }

        if (!check)
        {
            continue;
        }
        sum += num;
    }
    cout << sum;
}