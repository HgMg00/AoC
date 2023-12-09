#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string label = "AKQT98765432J";

enum TYPE
{
    FIVE_KIND,
    FOUR_KIND,
    FULL_HOUSE,
    THREE_KIND,
    TWO_PAIR,
    ONE_PAIR,
    HIGH_CARD
};

vector<vector<int>> type_value = {
    {5},            // Five of a kind
    {1, 4},         // Four of a kind
    {2, 3},         // Full house
    {1, 1, 3},      // Three of a kind
    {1, 2, 2},      // Two pair
    {1, 1, 1, 2},   // One pair
    {1, 1, 1, 1, 1} // High card
};

struct Hand
{
    int bid;
    string cards;
    TYPE type;
};

vector<Hand> get_input()
{
    string s;
    vector<Hand> lst;
    while (getline(cin, s))
    {
        stringstream ss(s);
        Hand tmp;
        ss >> tmp.cards;
        ss >> tmp.bid;
        lst.emplace_back(tmp);
    }
    return lst;
}

TYPE check_type(int result)
{
    TYPE type;
    switch (result)
    {
    case 0:
        type = FIVE_KIND;
        break;
    case 1:
        type = FOUR_KIND;
        break;

    case 2:
        type = FULL_HOUSE;
        break;
    case 3:
        type = THREE_KIND;
        break;
    case 4:
        type = TWO_PAIR;
        break;
    case 5:
        type = ONE_PAIR;
        break;
    default:
        type = HIGH_CARD;
        break;
    }

    return type;
}

TYPE get_type(string s)
{
    multiset<char> cards;
    for (int i = 0; i < s.length(); i++)
    {
        cards.insert(s[i]);
    }

    cards.erase('J');
    vector<int> nums_label;
    char prev='a';
    for (auto &&i : cards)
    {
        if(i == prev) continue;
        prev=i;
        nums_label.emplace_back(cards.count(i));
    }


    int n = s.length()-cards.size();
    sort(nums_label.begin(), nums_label.end());
    nums_label[nums_label.size()-1] = 
            nums_label.size() == 0 ?
            nums_label.emplace_back(n) : nums_label[nums_label.size()-1]+n;

    int result;
    for (int i = 0; i < type_value.size(); i++)
    {
        result = equal(nums_label.begin(), nums_label.end(), type_value[i].begin(), type_value[i].end()) ? i : result;
    }

    return check_type(result);  
}

bool compare(Hand a, Hand b)
{
    if (a.type==b.type)
    {
        for (int i = 0; i < a.cards.length(); i++)
        {
            int index_a=label.find(a.cards[i]);
            int index_b=label.find(b.cards[i]);

            if (index_a==index_b) continue;
            return index_a>index_b;
        }
    }
    return a.type>b.type;
}

int main()
{
    vector<Hand> lst = get_input();

    ll sum=0;

    for (auto &&i : lst)
    {
        i.type=get_type(i.cards);
    }

    sort(lst.begin(),lst.end(),compare);

    for (int i = 0; i < lst.size(); i++)
    {
        sum += (i+1)*lst[i].bid;
    }

    cout<<sum;
    
}