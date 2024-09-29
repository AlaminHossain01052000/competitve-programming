#include<bits/stdc++.h>
using namespace std;

//Given a string. Return the longest Palindromic substring(contiguous) of that string
//For example if s=fdoabbaik then the lps is "abba"
string longestPalindromeSubstring(string s){
    int n=s.length();
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    int maxi=1;
    int start=0;
    int endI=0;
    for(int i=0;i<n;++i){
        dp[i][i]=1;
        for(int j=0;j<i;++j){
            if(s[i]==s[j]&&(dp[j+1][i-1]||i-j<=2)){
                dp[j][i]=1;
                if(i-j+1>maxi){
                    maxi=i-j+1;
                    start=j;
                    endI=i;
                }
            }
        }
    }
    string ret="";
    for(int i=start;i<=endI;++i)ret+=s[i];
    return ret;
}
int main(){
    cout<<longestPalindromeSubstring("fdoabbaik")<<endl;
}
