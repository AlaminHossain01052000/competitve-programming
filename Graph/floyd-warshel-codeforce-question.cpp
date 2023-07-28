// https://codeforces.com/problemset/problem/295/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
    int n;
    cin>>n;
    int distance[n+1][n+1];
    
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                cin>>distance[i][j];
            }
        }
        vector<int> v(n);
        for(int i=0;i<n;++i)cin>>v[i];
        reverse(v.begin(),v.end());
        vector<int> ans;
        for(int k=0;k<n;++k){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    distance[i][j]=min(distance[i][j],distance[i][v[k]]+distance[v[k]][j]);
                }
            }
            int sum=0;
            for(int i=0;i<=k;++i){
                for(int j=0;j<=k;++j){
                    sum+=distance[v[i]][v[j]];
                }
            }
            ans.push_back(sum);
        }
        reverse(ans.begin(),ans.end());
        for(auto val:ans){
            cout<<val<<" ";
        }cout<<endl;
    
}
// Input
// 4
// 0 3 1 1
// 6 0 400 1
// 2 4 0 1
// 1 1 1 0
// 4 1 2 3
// Output
// 17 23 404 0 
