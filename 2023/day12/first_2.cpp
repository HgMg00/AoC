/*
This is an algorithm my friend came up with. It uses backtracking to get the final result and speeds it up through a certain degree of optimization.

The second part can be solved using Memoization Search.
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> symbol;
vector<vector<int>> nums;

int check(string s, int pos)
{
    queue<int> check_nums;
    for(int i = 0 ; i < nums[pos].size();i++){
        check_nums.push(nums[pos][i]);
    }

    int j = 0 ;
    bool davantiok = true;
    int count = 0;
    int temp = 0;
    bool remove = false;
    while(j < s.size() && check_nums.size() != 0){
        if(s[j] == '?') return 0;
        if (s[j] == '.') {
            if(count != 0 && !remove) return -1;
            davantiok = true;
            count = 0;
        }else if (s[j] == '#') {
            count +=1;
        }
        remove = false;
        if (count > check_nums.front()) return -1;
        if ((count == check_nums.front() && j+1 == s.size() )|| (count == check_nums.front() && s[j+1] == '.')){
            davantiok = false;
            check_nums.pop();
            remove = true;
        }
        j++;
    }
    while(j < s.size()){
        if(s[j] == '#') return -1;
        j++;
    }
    return  check_nums.size()==0 ? 1: 0;
}

int backtraking(string s, int pos, int pos_nums){
    if (pos > s.size()) return 0;
    if(check(s,pos_nums) == -1) return 0; 
    if (pos == s.size() && check(s, pos_nums))  return 1;
    int sum = 0;
    if (s[pos] == '#' || s[pos] == '.') sum += backtraking(s, pos + 1, pos_nums);
    
    if (s[pos] == '?'){
        s[pos] = '#';
        sum += backtraking(s, pos + 1, pos_nums);
        s[pos] = '.';
        sum += backtraking(s, pos + 1, pos_nums);
    }
    return sum;
}

vector<int> split(string s){
    vector<int> vec;
    string temp;
    for(int i = 0 ; i < s.size();i++){
        if (s[i] == ',' || s[i] == '\n') {
            if (temp.size() != 0) vec.push_back(stoi(temp));
            temp = "";
        }else temp+=s[i];
    }
    if (temp.size() != 0) vec.push_back(stoi(temp));
    return vec;
}

void get_input(){
    string s;
    while (getline(cin, s)){
        int end = s.find(' ');
        symbol.emplace_back(s.substr(0, end));
        string num = s.substr(end + 1, s.length()-end);
        nums.emplace_back(split(num));
    }
}



int main()
{
    get_input();
    int sum = 0;
    int arrang = 0;
    for (int i = 0; i < symbol.size(); i++){
        arrang = backtraking(symbol[i], 0, i);
        sum += arrang;
    }

    cout << sum;
}