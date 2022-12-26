#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int N=105;
int W=1e5+10;
vector<ll> weights(N);
vector<ll> values(N);
ll dp[105][100015];
ll knapsack(int ind,int remainingWeight){
    if(remainingWeight==0){
        return 0; //As I have no space left in my bag so I can't make any profit
    }
    if(ind==-1){
        return 0;//As there are no product left so I can't took any product as a result can't make any profits
    }
    if(dp[ind][remainingWeight]!=-1){
        return dp[ind][remainingWeight];
    }
    ll x=LONG_LONG_MIN,y=LONG_LONG_MIN;

    //include
    if(remainingWeight-weights[ind]>=0)
         x=knapsack(ind-1,remainingWeight-weights[ind])+values[ind];
    //Exclude
    y=knapsack(ind-1,remainingWeight);
    return dp[ind][remainingWeight]=max(x,y);
}


int main()
{
    memset(dp,-1,sizeof(dp));
    int n,w;
    cout<<"Enter Number of products : ";
    cin>>n;
    cout<<"\nEnter Max Capacity of the Knapsack : ";
    cin>>w;
    cout<<endl;
    cout<<"Enter the weigths and values in space separated integers \n";
    for(int i=0;i<n;++i){
        cin>>weights[i]>>values[i];
    }
    cout<<"Max Profit Is : ";
    cout<<knapsack(n-1,w);
}