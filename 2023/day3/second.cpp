#include <bits/stdc++.h>
using namespace std;

vector<string> var_matrix;
long long int sum = 0;
string num = "";
int mul = 0;

bool is_Star(int i, int j)
{
    return var_matrix[i][j] == '*';
}

bool around_point(int r, int c)
{

    if (r < 0 || c < 0)
        return false;
    if (r >= var_matrix.size() || c >= var_matrix[0].size())
        return false;
    return true;
}

int find_num(int r, int c)
{
    num = "";
    char prev = var_matrix[r][c - 1];
    char next = var_matrix[r][c + 1];
    if (isdigit(prev) && isdigit(next))
    {

        num = num + prev + var_matrix[r][c] + next;
        mul *= stoi(num);
         return 1;
    }

    if (isdigit(prev) && !isdigit(next))
    {
        int j = 0;
        do
        {
            num = var_matrix[r][c - j] + num;
            j++;
        } while (isdigit(var_matrix[r][c - j]));
        mul *= stoi(num);
         return c;
    }

    if (!isdigit(prev) && isdigit(next))
    {
        int j = 0;
        do
        {
            num = num + var_matrix[r][c + j];
            j++;
        } while (isdigit(var_matrix[r][c + j]));
        mul *= stoi(num);
        return c + j;
    }

    num = var_matrix[r][c];
    mul *= stoi(num);
    return c;
}
void operation(int r, int c, bool check)
{
    if (!check)
    {
        return;
    }

    mul = 1;
    for (int dr = -1; dr < 2; dr++)
    {
        for (int dc = -1; dc < 2; dc++)
        {
            if ((dr != 0 || dc != 0) && around_point(dr + r, dc + c))
            {
                char symbol = var_matrix[r + dr][c + dc];
                if (isdigit(symbol))
                {
                    dc =abs( find_num(r + dr, c + dc) - (c+dc));
                }
            }
        }
    }

    if (num == "" || mul == stoi(num))
    {
        mul = 0;
        num = "";
    }
}

int main()
{

    string s;
    while (cin >> s)
    {
        var_matrix.push_back(s + '\n');
    }

    for (int i = 0; i < var_matrix.size(); i++)
    {
        for (int j = 0; j < var_matrix[i].size(); j++)
        {
            operation(i, j, is_Star(i, j));
            sum += mul;
            mul = 0;
        }
    }

    cout << sum;
}