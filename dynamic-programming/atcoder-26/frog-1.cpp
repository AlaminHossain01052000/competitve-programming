#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> v;
int dp[N];
int myFrog(int index){
    if(index==0){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }

    int cost=INT_MAX;
    //way 1
    cost=min(cost,myFrog(index-1)+abs(v[index]-v[index-1]));

    // way 2
    if(index>=2)//if index ==1 then 1-2==-1
        cost=min(cost,myFrog(index-2)+abs(v[index]-v[index-2]));
    dp[index]=cost;
    return dp[index];
   
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<myFrog(n-1);
}