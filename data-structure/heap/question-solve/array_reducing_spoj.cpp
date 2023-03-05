// https://www.spoj.com/problems/REDARR2/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;++i){
            int x;
            cin>>x;
            pq.push(x);
        }
        int ans=0;
        while(pq.size()>1){
            int x1=pq.top();
            pq.pop();
            int x2=pq.top();
            pq.pop();
            ans+=x1+x2;
            pq.push(x1+x2);
        }
        cout<<ans<<endl;

    }
}
