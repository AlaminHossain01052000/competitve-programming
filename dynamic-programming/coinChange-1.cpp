#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& coins,int amount,int dp[]){
    if(amount==0)return 0;
    if(dp[amount]!=-1){
        return dp[amount];
    }
    int ans=INT_MAX;
    for(auto coin:coins){
        if(amount-coin>=0)
        //converting ans to long long data type by ans+0ll as if the ansewer is INT_MAX then INT_MAX+1 will be long long data type
            ans=min(ans+0LL,solve(coins,amount-coin,dp)+1LL);
    }
    return dp[amount]=ans;
}
int coinChange(vector<int>& coins, int amount) {
    int dp[10010];
    memset(dp,-1,sizeof(dp));
    return solve(coins,amount,dp);
}
int main(){
    vector<int> coins={1,2,5};
    int amount=11;
    cout<<coinChange(coins,amount)<<endl;

}