#include<bits/stdc++.h>
using namespace std;
//Given 2 strings. You can allow to do 3 types of operation each of them cost is 1.
// 1. Replace a character from s1 to s2 or s2 ro s1
// 2. Remove a char from s1 or s2
// 3. Adding a character is s1 or s2
// You have to calculate the minimum number of operation required to make s1 equal to s2
// For love and movies we can replace 'l' by 'm'."love" become "move" now.Then remove character 'i' and 's' from "movies". Now movies become move. Hence,"love" and "movies" both transformed to "move" in total 3 operations
int editDistance(string &s1,string &s2){
  
    int n=s1.length();
    int m=s2.length();
    const int INF=1e8;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<n;++i)dp[i][m]=n-i;
    for(int i=0;i<m;++i)dp[n][i]=m-i;
    dp[n][m]=0;
    for(int i=n-1;i>=0;--i){
        for(int j=m-1;j>=0;--j){
            int ret=10000;
            if(s1[i]==s2[j]){
                ret=min(ret,dp[i+1][j+1]);
            }
            else{
                ret=min(ret,dp[i+1][j]+1);
                ret=min(ret,dp[i][j+1]+1);
                ret=min(ret,dp[i+1][j+1]+1);
            }
            dp[i][j]=ret;
        }
    }
    return dp[0][0];
}
signed main(){
    string s1="love";
    string s2="movies";
    cout<<editDistance(s1,s2);
}