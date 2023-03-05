// https://codeforces.com/contest/799/problem/B

#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> p(n);
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;++i)cin>>p[i];
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    priority_queue<int,vector<int>,greater<int>>pq[5][5];//pq[1][2]={200,400,500};
    for(int i=0;i<n;++i){
        pq[a[i]][b[i]].push(p[i]);
    }
    int m;
    cin>>m;
    while(m--){
        int c;
        cin>>c;
        int ans=LONG_LONG_MAX;
        int frontColor,backColor;
        //let c a front color and i is a back color
        for(int i=1;i<=3;++i){
            if(!pq[c][i].empty()&&pq[c][i].top()<ans){
                ans=pq[c][i].top();
                frontColor=c;
                backColor=i;
            }   

        }
        //let i a front color and c is a back color
        for(int i=1;i<=3;++i){
            if(!pq[i][c].empty()&&pq[i][c].top()<ans){
                ans=pq[i][c].top();
                frontColor=i;
                backColor=c;
            }   

        }
        if(ans==LONG_LONG_MAX)ans=-1;
        else{
            pq[frontColor][backColor].pop();
        }
        // ans==LONG_LONG_MAX?ans=-1:pq[frontColor][backColor].pop();
        cout<<ans<<" ";
    }
    cout<<endl;

}
