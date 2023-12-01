#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    long long sum=0;
    while (cin>>s)
    {
        vector<int> lst;
        
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]>47 && s[i]<58)
                lst.push_back(s[i]-48);
        }

        lst[0]=lst[0]*10+lst[lst.size()-1];

        sum+=lst[0];
    }

    cout<<sum;
    
    
}