/*
Get idea from 
https://github.com/tcbrindle/advent_of_code_2023/blob/main/dec10/main.cpp
*/

#include <bits/stdc++.h>
using namespace std;

#define P pair<int, int>

P Start;
vector<string> grid;

int y[2] = {-2, -2};
int x[2] = {-2, -2};

void get_input()
{
    string s;
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
        grid.emplace_back(s);
    }
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

char get_nxtTile(int x, int y)
{
    for (int i = 1; i < grid[x].length(); i++)
    {
        if (grid[x][y + i] != '-')
        {
            return grid[x][y + i];
        }
    }
}

int main()
{

    get_input();
    int distance[grid.size()][grid[0].length()];

    queue<P> lst;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].length(); j++)
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

    grid[Start.first][Start.second]='-';
    int num = 0;

    for (int x = 0; x < grid.size(); x++)
    {
        bool inside = false;
        for (int y = 0; y < grid[0].length(); y++)
        {
            if (distance[x][y] != INT_MAX)
            {
                char tile = grid[x][y];

                if (tile == '|')
                    inside = !inside;
                else if (tile == 'L' || tile == 'F')
                {
                    char next_tile = get_nxtTile(x, y);
                    if ((tile == 'L' && next_tile == '7') ||
                        (tile == 'F' && next_tile == 'J'))
                    {
                        inside = !inside;
                    }
                }
            }
            else
            {
                num +=inside;
            }
            
        }
    }

    cout << num;
}