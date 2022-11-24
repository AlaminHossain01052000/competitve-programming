#include <bits/stdc++.h>
using namespace std;

int change(int amount, vector<int> &coins)
{   
    sort(coins.begin(),coins.end());
    int p=coins.size();
    int q=amount+1;
    
    int dp[p][q];
    for(int i=0;i<p;++i){
        for(int j=0;j<q;++j){
            dp[i][j]=0;
        }
    }
    for(int j=0;j<=amount;++j){
        if(j%coins[0]==0){
            dp[0][j]=1;
        }
        
    }
    for(int i=0;i<p;++i){
        dp[i][0]=1;
    }
   
    for(int i=1;i<p;++i){
        for(int j=1;j<=amount;++j){
            
            if(coins[i]>j){
                dp[i][j]=dp[i-1][j];
                
            }
            else 
                dp[i][j]=dp[i-1][j]+dp[i][(j-coins[i])];
        }
    }
  
    return dp[p-1][q-1];
}
int main()
{
    vector<int> coins = {1,2,5};
    int amount = 5;
    cout << change(amount, coins) << endl;
}