#include <bits/stdc++.h>
using namespace std;
map<string,int> m ={
    {"one",1},
    {"two",2},
    {"three",3},
    {"four",4},
    {"five",5},
    {"six",6},
    {"seven",7},
    {"eight",8},
    {"nine",9},
    };

int main(){
    string s;
    long long sum=0;
    while (cin>>s)
    {
        vector<int> lst;
        
        for (int i = 0; i < s.length(); i++)
        {
            for(int j =2; j<6 && !(i+j > s.length()); j++)
            {
                int x=m.find(s.substr(i,j)) ->second;
                if (x != 0)
                    lst.push_back(x);
            }
            if(s[i]>47 && s[i]<58)
                lst.push_back(s[i]-48);
        }

        lst[0]=lst[0]*10+lst[lst.size()-1];

        sum+=lst[0];
    }

    cout<<sum;
    
    
}