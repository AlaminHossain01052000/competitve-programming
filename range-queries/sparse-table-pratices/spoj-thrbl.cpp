// https://www.spoj.com/problems/THRBL/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N=1e7+100;
const int K=log2(N)+1;
const int INF=-1e9+100;
//complexiy O(Nlogn)
vector<vector<int>> sparseTableMax(vector<int>&v){
    int n=v.size();
    vector<vector<int>>st(K,vector<int>(n,INF));
    // vector<vector<int>>st(K,vector<int>(n,INF*-1));//if calculating max query
    for(int j=0;j<n;++j)st[0][j]=v[j];


    for(int i=1;i<=K;++i){
        for(int j=0;j+(1<<i)<=n;++j){//j+(1<<i) must be less than or equal to n to ensure runtime error handling
            st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }


   return st;
}
int32_t main(){
    fast
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;++i)cin>>v[i];
    vector<vector<int>> st=sparseTableMax(v);
    // cout<<st.size()<<" "<<st[0].size()<<endl;
    int ans=0;
    while (m--)
    {
        /* code */
        int l,r;
        cin>>l>>r;
        if(r-l<=1){
            ans++;
            continue;
        }
        r--;//0 based index
        r--;// do not consider city B. Original Range is between city A+1 to B-1

        int i=log2(r-l+1);
        // cout<<max(st[i][l],st[i][(r-(1<<i)+1)])<<endl;

        // cout<<max(st[i][l],st[i][(r-(1<<i)+1)])<<" "<<v[l-1]<<endl<<endl;
        if((max(st[i][l],st[i][(r-(1<<i)+1)]))<=v[l-1]){
            
            ans++;
        }
    }
    cout<<ans<<endl;
}