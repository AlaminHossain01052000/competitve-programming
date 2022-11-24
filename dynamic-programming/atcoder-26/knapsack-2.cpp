#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int N=105;
vector<ll> weights(N);
vector<ll> values(N);
ll dp[105][100005];

ll knapsack2(ll ind,ll remainingValue){
    if(remainingValue==0){
        return 0;
    }
    if(ind<0){
        return 1e15;
    }
    if(dp[ind][remainingValue]!=-1)return dp[ind][remainingValue];
    // exclude
    ll x=knapsack2(ind-1,remainingValue);

    //include
    if(remainingValue-values[ind]>=0)
        x=min(x,knapsack2(ind-1,remainingValue-values[ind])+weights[ind]);
    return dp[ind][remainingValue]=x;        

}


int main()
{
    memset(dp,-1,sizeof(dp));
    ll n,w;
    cin>>n>>w;
    for(int i=0;i<n;++i){
        cin>>weights[i]>>values[i];
    }
    for(int i=1e5;i>=0;--i){
        if(knapsack2(n-1,i)<=w){
            cout<<i<<endl;
            break;
        }
    }

}