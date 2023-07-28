// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
#include<bits/stdc++.h>
using namespace std;
int dfs(int i,int j,vector<vector<int>>& matrix,int parent,int visited[201][201],int dp[201][201]){
    int n=matrix.size();
    int m=matrix[0].size();
    if(i<0||j<0)return 0;
    if(i>=n||j>=m)return 0;
    if(matrix[i][j]<=parent)return 0;
    // if(visited[i][j]==1)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    visited[i][j]=1;
    int ans=INT_MIN;
    ans=max(ans,(dfs(i-1,j,matrix,matrix[i][j],visited,dp)+1));
    ans=max(ans,(dfs(i+1,j,matrix,matrix[i][j],visited,dp)+1));
    ans=max(ans,(dfs(i,j+1,matrix,matrix[i][j],visited,dp)+1));
    ans=max(ans,(dfs(i,j-1,matrix,matrix[i][j],visited,dp)+1));
    return dp[i][j]=ans;
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int visited[201][201];
        int dp[201][201];
        memset(dp,-1,sizeof(dp));
        int ans=INT_MIN;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                memset(visited, 0, sizeof(visited)); 
                ans=max(ans,dfs(i,j,matrix,-1,visited,dp));
            }

        }
        // cout<<ans<<endl;
        int maxOfDp=INT_MIN;
        // int myAns=INT_MIN;
        for(int i=0;i<201;++i){
            for(int j=0;j<201;++j){
                
                maxOfDp=max(maxOfDp,dp[i][j]);
            }
        }
        return maxOfDp;
}
int main(){
    vector<vector<int>> graph;
    graph={{13,5,13,9},{5,0,2,9},{10,13,11,10},{0,0,13,13}};
    cout<<longestIncreasingPath(graph)<<endl;
}