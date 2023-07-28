// https://leetcode.com/problems/flood-fill/
#include<bits/stdc++.h>
using namespace std;
// const int N=1e3+10;
// bool visited[N][N];
void dfs(int i,int j,vector<vector<char>>& grid,bool visited[501][501]){
    int n=grid.size();
    int m=grid[0].size();
    if(i<0||j<0)return;
    if(i>=n||j>=m)return;
    if(grid[i][j]=='0')return;
    if(visited[i][j]==true)return;
    visited[i][j]=true;
    dfs(i-1,j,grid,visited);
    dfs(i+1,j,grid,visited);
    dfs(i,j-1,grid,visited);
    dfs(i,j+1,grid,visited);
    dfs(i-1,j+1,grid,visited);
    dfs(i-1,j-1,grid,visited);
    dfs(i+1,j-1,grid,visited);
    dfs(i+1,j+1,grid,visited);
}
int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans=0;
        bool visited[501][501];
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(visited[i][j]==true||grid[i][j]=='0')continue;
                // cout<<"Hit\n";
                dfs(i,j,grid,visited);
                ans++;
            }
        }
        return ans;
}
int main(){
    vector<vector<char>> graph;
    graph={{'0','1','1','1','0','0','0'},{'0','0','1','1','0','1','0'}};
    // graph=floodFill(graph,1,1,2);
    cout<<numIslands(graph)<<endl;
    // for(auto vect:graph){
    //     for(auto ele:vect){
    //         cout<<ele<<" ";
    //     }cout<<endl;
    // }
    return 0;
}