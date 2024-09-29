#include<bits/stdc++.h>
using namespace std;
//Given 3 string. Return the length of the longest common subsequence(non-contiguous) of these strings. If s1="usab",s2="buszza" & s3="upoasa" the the length of the lcs is 3 and the lcs is "usa"
int dp[51][51][51];
int lcs3string(int i,int j,int k,string &s1,string &s2,string &s3){
        if(i<0||j<0||k<0)return 0;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int ret=0;
        if(s1[i]==s2[j]&&s2[j]==s3[k]){
            
            ret=1+lcs3string(i-1,j-1,k-1,s1,s2,s3);
        }
        else{
            ret=max({lcs3string(i,j-1,k,s1,s2,s3),lcs3string(i-1,j,k,s1,s2,s3),lcs3string(i,j,k-1,s1,s2,s3)});
        }
            
        
        return dp[i][j][k]=ret;
}

signed main(){
    
    string s,t,q;
    s="usab";
    t="buszza";
    q="upoasa";
    int n=s.length();
    int m=t.length();
    int o=q.length();
    
    memset(dp,-1, sizeof dp);
    
    cout<<lcs3string(n-1,m-1,o-1,s,t,q)<<"\n";
}