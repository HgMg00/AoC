#include <bits/stdc++.h>
using namespace std;

#define P pair<int, int>

P Start;

int y[2] = {-2, -2};
int x[2] = {-2, -2};

vector<string> get_input()
{
    string s;
    vector<string> input;
    int x = 0;
    int y = -1;
    while (getline(cin, s))
    {
        if (s.find('S') == string::npos)
        {
            x++;
        }
        else
        {
            y = s.find('S');
            Start = make_pair(x, y);
        }
        input.emplace_back(s);
    }

    return input;
}

void get_direction(char c)
{
    switch (c)
    {
    case '|':
        y[0] = -1;
        x[0] = 0; // north

        y[1] = 1;
        x[1] = 0; // south
        break;
    case '-':
        y[0] = 0;
        x[0] = 1; // east

        y[1] = 0;
        x[1] = -1; // west
        break;
    case 'L':
        y[0] = -1;
        x[0] = 0; // north

        y[1] = 0;
        x[1] = 1; // east
        break;
    case 'J':
        y[0] = -1;
        x[0] = 0; // north

        y[1] = 0;
        x[1] = -1; // west
        break;
    case '7':
        y[0] = 1;
        x[0] = 0; // south

        y[1] = 0;
        x[1] = -1; // west
        break;
    case 'F':
        y[0] = 1;
        x[0] = 0; // south

        y[1] = 0;
        x[1] = 1; // east
        break;

    case 'S':
        y[0] = 0;
        x[0] = 1; // east

        y[1] = 0;
        x[1] = -1; // west
        break;

    default:
        break;
    }

}

int main()
{

    vector<string> grid = get_input();
    int distance[grid.size()][grid[0].length()];

    queue<P> lst;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            distance[i][j] = INT_MAX;
        }
    }

    lst.push(P(Start.first, Start.second));

    distance[Start.first][Start.second] = 0;

    while (lst.size())
    {
        P p = lst.front();
        lst.pop();

        get_direction(grid[p.first][p.second]);

        for (int i = 0; i < 2; i++)
        {
            int next_y = p.first + y[i], next_x = p.second + x[i];

            if (0 <= next_y && next_y < grid.size() && 0 <= next_x && next_x < grid[0].length() && grid[next_y][next_x] != '.' && distance[next_y][next_x] == INT_MAX)
            {
                lst.push(P(next_y, next_x));
                distance[next_y][next_x] = distance[p.first][p.second] + 1;
            }
        }
    }

    int maxValue = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].length(); j++)
        {
            maxValue = max(distance[i][j] != INT_MAX ? distance[i][j]:0, maxValue);
        }
    }

    cout << maxValue;
}