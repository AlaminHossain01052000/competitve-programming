#include<bits/stdc++.h>
using namespace std;
string a1,b1;
string ans="";
int dp[3010][3010];
vector<string> v;
int lcs(int i,int j){
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int a=lcs(i-1,j);
    a=max(a,lcs(i,j-1));
    int b=lcs(i-1,j-1)+(a1[i]==b1[j]);
    
    if(b>a){
       
        a=b;
    }
    
    
    
    return dp[i][j]=a;
}   
int main(){
    memset(dp,-1,sizeof(dp));
    a1="abracadabra";
    b1="avadakedavra";
   int p=lcs(a1.size()-1,b1.size()-1);
 
   cout<<p<<endl;
    cout<<ans<<endl;
}