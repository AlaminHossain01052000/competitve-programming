#include<bits/stdc++.h>
using namespace std;
int dp[1002];
int solve(int length,vector<int> &prices){
    if(length==0)return 0;
    if(dp[length]!=-1)return dp[length];
    int x=INT_MIN;
    for(int i=1;i<=prices.size();++i){
        if(length-i>=0)
            x=max(x,solve(length-i,prices)+prices[i-1]);
    }
    return dp[length]=x;
}
int cutRod(int price[], int n) {
        //code here
        memset(dp,-1,sizeof(dp));
        vector<int> prices(n);
        for(int i=0;i<n;++i){
            prices[i]=price[i];
        }
        return solve(n,prices);
}
int main(){
    int price[]={1, 5, 8, 9};
    int n=4;
    cout<<cutRod(price,n)<<endl;
    for(int i=0;i<5;++i)
        cout<<dp[i]<<" ";

}