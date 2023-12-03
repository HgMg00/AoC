#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    long long sum = 0;

    while (getline(cin, s))
    {

        int index = s.find(':');

        s = s.substr(index + 2, s.length());

        int valor;
        int key;
        map<string, int> lst;

        auto cmp = [](const int a, const int b)
        { return a > b ? a : b; };

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ',')
            {
                lst[s.substr(key, i - key)] = cmp(lst[s.substr(key, i - key)], valor);
            }
            if (isdigit(s[i]))
            {
                valor = s[i] - 48;
                if (isdigit(s[++i]))
                    valor = valor * 10 + s[i++] - 48;
                key = ++i;
            }

            if (s[i] == ';')
            {
                lst[s.substr(key, i - key)] = cmp(lst[s.substr(key, i - key)], valor);

                s = s.substr(i + 1, s.length());
                i = 0;
            }

            if (i == s.length() - 1)
            {
                lst[s.substr(key, i - key + 1)] = cmp(lst[s.substr(key, i - key+1)], valor);
            }
        }

        int power = 1;

        for (auto &&i : lst)
        {
            power *= i.second;
        }
        sum += power;
    }
    cout << sum;
}