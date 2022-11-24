#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &m, vector<vector<int>> &visited, int x, int y, int n)
{
    if (x >= 0 && y >= 0 && x <= n - 1 && y <= n - 1 && visited[x][y] == 0 && m[x][y] == 1)
    {
        return true;
    }
    else
        return false;
}

void solve(vector<string> &ans, vector<vector<int>> &m, vector<vector<int>> &visited, int x, int y, string path, int n)
{
    if (x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    // up
    int newX = x - 1;
    int newY = y;
    if (isSafe(m, visited, newX, newY, n))
    {
        path += "U";
        solve(ans, m, visited, newX, newY, path, n);
        path.pop_back();
    }
    // down
    newX = x + 1;
    newY = y;
    if (isSafe(m, visited, newX, newY, n))
    {
        path += "D";
        solve(ans, m, visited, newX, newY, path, n);
        path.pop_back();
    }
    // left
    newX = x;
    newY = y - 1;
    if (isSafe(m, visited, newX, newY, n))
    {
        path += "L";
        solve(ans, m, visited, newX, newY, path, n);
        path.pop_back();
    }
    // right
    newX = x;
    newY = y + 1;
    if (isSafe(m, visited, newX, newY, n))
    {
        path += "R";
        solve(ans, m, visited, newX, newY, path, n);
        path.pop_back();
    }
    visited[x][y] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{

    // Your code goes here
    vector<string> ans;
    if (m[0][0] == 0)
    {
        return ans;
    }
    string path = "";
    auto visited = m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            visited[i][j] = 0;
        }
    }
    
    solve(ans, m, visited, 0, 0, path, n);

    return ans;
}
int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    int n = 4;
    auto ans=findPath(maze,n);
    for(auto str:ans){
        cout<<str<<" ";
    }
    cout<<endl;
}