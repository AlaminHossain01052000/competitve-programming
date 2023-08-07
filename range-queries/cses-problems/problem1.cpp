// https://cses.fi/problemset/task/1646
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e7+100;
const int K=log2(N)+1;
const int INF=1e9+100;
//complexiy O(Nlogn)
//for calculating sum of the given query. Note that prefix sum is a better approach
vector<vector<int>> sparseTableForSumQuery(vector<int>&v){
    int n=v.size();
    vector<vector<int>>st(K,vector<int>(n));
    // vector<vector<int>>st(K,vector<int>(n,INF*-1));//if calculating max query
    copy(v.begin(),v.end(),st[0].begin());//st[0]=v;


    for(int i=1;i<=K;++i){
        for(int j=0;j+(1<<i)<=n;++j){//j+(1<<i) must be less than n to ensure runtime error handling
            st[i][j]=st[i-1][j]+st[i-1][j+(1<<(i-1))];
        }
    }


   return st;
}
// total Complexity O(n*q)
signed main(){
    
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;++i)cin>>v[i];
    // vector<vector<int>> st=sparseTableForMinimumQuery(v);
    vector<vector<int>> stSum=sparseTableForSumQuery(v);
   
    //calculate minimum and sum of the range l to r
    while(q--){
        int l,r;
        cin>>l>>r;        
        //calculating minimum
        int i=log2(r-l+1);
        r--;//if query is basen on 0-based index
        l--;
        // cout<<min(st[i][l],st[i][r-(1<<i)+1])<<endl;

        //calculating sum
        long long sum=0;
        for(i=K;i>=0;--i){
            if((1<<i)<=(r-l+1)){ //here r-l+1 is the range length

                sum+=stSum[i][l];
                l+=(1<<i);//new range is from l+(2^i) to r

            }
        }
        cout<<sum<<endl;
    }

}
// 10
// 3 7 9 21 -6 4 2 1 19 4
// 3
// 1 4
// 4 7
// 8 10