#include <bits/stdc++.h>
using namespace std;

map<long long int, vector<long long int>> mapsNum;

vector<long long int> get_seeds()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<long long int> input;

    ss >> s;
    while (ss >> s)
    {
        
        input.push_back(stoll(s));
    }
    
    return input;
}

vector<long long int> get_nums(string s)
{
    stringstream ss(s);
    string num;
    vector<long long int> valors;
    ss >> num;
    ss >> num;
    while (ss >> num)
    {
        valors.push_back(stoll(num));
    }
    ss.str("");
    return valors;
}

void get_maps()
{
    vector<string> maps;
    maps.resize(7, "");
    string s;
    long long int i = 0;
    getline(cin, s);
    while (getline(cin, s))
    {
        if (s.length() == 0)
        {
            i++;
            getline(cin, s);
        }
        maps[i] = maps[i] + s + " ";
    }

    for (long long int i = 0; i < maps.size(); i++)
    {
        mapsNum[i] = get_nums(maps[i]);
    }
}

long long int ranges(vector<long long int> v,long long int seed)
{
    
    long long int source, destination, length;
    for (long long int i = 0; i < v.size(); i++)
    {
        if (i % 3 == 0)
            destination = v[i];
        if (i % 3 == 1)
            source = v[i];
        if (i % 3 == 2 )
        {
            length=v[i];
            if  (seed>=source && seed <= source+length){

                seed += destination - source;
                break;
            }
        }
    }
    return seed;
}

int main()
{
    vector<long long int> seeds = get_seeds();
    get_maps();
    vector<long long int> res;

    for (long long int i = 0; i < seeds.size(); i++)
    {
        long long int seed = seeds[i];
        for (long long int j = 0; j < mapsNum.size(); j++)
        {

            seed = ranges(mapsNum[j],seed);
 
        }

        res.push_back(seed);

    }
    sort(res.begin(),res.end());
    cout<<res[0];
}