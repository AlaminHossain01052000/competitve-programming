#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int INF=1e15+123;
int n,w;
const int N=1e2+123;
const int P=1e5+123;
int dp[N][P];//N*P must be less than of equal to 10^7

void solve(){
    
    cin>>n>>w;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;++i){
        cin>>v[i].first;
        cin>>v[i].second;

    }
    for(int i=0;i<=1e5;++i){
        for(int j=0;j<n+10;++j)dp[j][i]=INF;
    }
    dp[n][0]=0;

    for(int i=0;i<n;++i)dp[i][0]=0;
    int ans=INF*-1;
    for(int i=1;i<=1e5;++i){

        for(int j=n-1;j>=0;--j){
            int ret=INF;
            if(i>=v[j].second){
                ret=min(ret,dp[j+1][i-v[j].second]+v[j].first);
            }
            ret=min(ret,dp[j+1][i]);
            dp[j][i]=ret;
        }
        if(dp[0][i]<=w){
            ans=max(ans,i);
        }
        
    }
    cout<<ans<<endl;

    
}
signed main(){
    solve();
}