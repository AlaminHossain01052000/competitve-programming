#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &v, int x, int y, int n)
{
    
    for (int i = x - 1; i >= 0; --i)
    {
        if (v[i][y] == 1)
        {
            return false;
        }
    }
    int i = x - 1;
    int j = y - 1;
    while (i >= 0 && j >= 0)
    {
        if (v[i][j] == 1)
            return false;
        i--;
        j--;
    }
    
    i = x - 1;
    j = y + 1;
    while (i >= 0 && j < n)
    {
        if (v[i][j] == 1)
            return false;
        i--;
        j++;
    }
    return true;
}
bool nQueen(vector<vector<int>> &v, int x, int n)
{
    if (x >= n)
    {
        return true;
    }
    for (int j = 0; j < n; ++j)
    {

        if (isSafe(v, x, j, n))
        {

            v[x][j] = 1;

            if (nQueen(v, x + 1, n))
            {
                return true;
            }
            v[x][j] = 0;
        }
    }
    return false;
}
int main()
{
    int n;
    n = 4;
    vector<vector<int>> v = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}

    };

    cout << nQueen(v, 0, n) << endl;
    if (nQueen(v, 0, n))
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
}