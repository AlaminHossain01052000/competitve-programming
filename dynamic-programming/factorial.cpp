#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+10;
int dp[N];

int dynamicFacto(int n){
    if(n==0||n==1)return 1;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=n*dynamicFacto(n-1);
}
signed main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<dynamicFacto(n)<<endl;
}