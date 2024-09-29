#include<bits/stdc++.h>
using namespace std;

// ===== recursive lsc will return the length of Longest common subequence(non contiguous) of 2 strings s1 & s2
int recursiveLCS(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){

        if(i<0||j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        int ret=0;
        if(s1[i]==s2[j]){
            
            ret=1+recursiveLCS(i-1,j-1,s1,s2,dp);
        }
        else{
            ret=max(recursiveLCS(i,j-1,s1,s2,dp),recursiveLCS(i-1,j,s1,s2,dp));
        }
        
        return dp[i][j]=ret;
}

//Iterative lcs will give the longest commong substring(non contiguous) as well as the length of longest common substring
void lcs(string &s,string &t){
    //Complexity is O(n*m) where n is the length of string s and m is the length of string t
    int n=s.length();
    int m=t.length();
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1)); //Initialize to -1 is you call the recursiveLCA
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // cout<<"Length of Longest common Subsequence is: ";
    // cout<<recursiveLCS(n-1,m-1,s,t,dp)<<endl;
  
    
    
    for(int i=n-1;i>=0;--i){
        for(int j=m-1;j>=0;--j){
            int ret=0;
            if(s[i]==t[j]){
                ret=1+dp[i+1][j+1];
            }
            else 
                ret=max(dp[i][j+1],dp[i+1][j]);
            dp[i][j]=ret;
        }
    }
 
    int i=0;
    int j=0;
    string ans="";
    while(i<n&&j<m){
        if(s[i]==t[j]){
            ans+=s[i];
            i++;
            j++;
            continue;
        }
        else if(dp[i+1][j]>dp[i][j+1]){
            i++;
        }
        else{
            j++;
        }
    }
    cout<<"Length of Longest common Subsequence is: ";
    cout<<dp[0][0]<<endl;
    cout<<"The longest common subsequence is: ";
    cout<<ans<<endl;//It is the longest common subsequence of s and t
    
}
signed main(){
    string s="abcd";
    string t="eafbgcd";
    lcs(s,t);
}