#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
//Fibonacci Series : 0 1 1 2 3 5 8 ...(0th number is 0,1th number is 1, 4th number is 3. We have to find nth number of fibonacci series)
//Brute Force Recursion
//Time Complexity : 2^n
int fibo(int n){
    //Base Conditions
    if(n==0)return 0;
    if(n==1)return 1;

    //Recursive Calls
    return fibo(n-1)+fibo(n-2);
}

//Dynamic Programming Approach
//Top Down Approach
//Time Complexity O(n)
int dp[N];
int dynamicFibo(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(dp[n]!=-1){
        return dp[n];
    }
    else{
        int x=dynamicFibo(n-1);
        int y=dynamicFibo(n-2);
        dp[n]=x+y;
        return dp[n];
        //upper 4 line can be written in 1 line as
        //return dp[n]=dynamicFibo[n-1]+dynamicFibo[n-2];
    }
}
int main(){
    //Setting all the value of dp array -1
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    // cout<<fibo(n)<<endl;
    // cout<<dynamicFibo(n)<<endl;
    //Bottom up Approach
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;++i){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
}