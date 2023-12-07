#include <bits/stdc++.h>
using namespace std;

vector<string> var_matrix;
long long int sum = 0;
string num;
bool nearSymbol = false;


void operation(int r, int c, bool check)
{

    if (!check)
    {
        if (nearSymbol){
            sum += stoi(num);
            
        }
        num = "";
        nearSymbol=0;
        return;
    }

    num.push_back(var_matrix[r][c]);
    for (int dr = -1; dr < 2; dr++)
    {
        for (int dc = -1; dc < 2; dc++)
        {
            if ((dr != 0 || dc != 0) &&
                !((dr + r) < 0 || (dc + c) < 0 || (r + dr) >= var_matrix.size() || (c + dc) > var_matrix[0].size()))
            {
                char symbol = var_matrix[r + dr][c + dc];
                if (!isalnum(symbol) && symbol != '.' && symbol != '\n')
                {
                    nearSymbol = true;
                }
            }
        }
    }
}


int main()
{

    string s;
    while (cin >> s)
    {
        var_matrix.push_back(s+'\n');
        
    }

    for (int i = 0; i < var_matrix.size(); i++)
    {
        for (int j = 0; j < var_matrix[i].size(); j++)
        {
            operation(i, j, isdigit(var_matrix[i][j]));
        }
    }

    cout << sum;
}