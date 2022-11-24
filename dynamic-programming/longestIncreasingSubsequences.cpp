#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> v(N);
int dp[N];


int lis(int i){
    if(dp[i]!=-1)return dp[i];
    int ans=1;//minimum 1 element is exist in each subsequence
    //calculation lis of all elements from i-1 to 0
    for(int j=i-1;j>=0;--j){
    //if v[i]>v[j] then they are a lis
        if(v[i]>v[j]){
            
            ans=max(ans,lis(j)+1);
            
        }
        
    }
  //setting dp[i] as answer and return dp[i]
    return dp[i]=ans;
}
int main(){
    //setting all elements of dp as -1
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    int ans=INT_MIN;
    for(int i=0;i<n;++i){
        ans=max(ans,lis(i));
    }
    cout<<ans<<endl;
    
}