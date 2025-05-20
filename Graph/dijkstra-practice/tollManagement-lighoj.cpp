// https://lightoj.com/problem/toll-management
// https://www.youtube.com/watch?v=GJU-n3PMg-k&list=PLoa_roVVsxA2Gqs0jsxzgvzXgcFpT-RYx&index=7
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e4+100;
vector<vector<int>> dist(2,vector<int>(N));
vector<pair<int,int>> graph[2][N];
const int INF=INT_MAX;
struct edgeInfo{
    int u,v,w;
};
void dijkstra(int s,int n,int f){
    for(int i=1;i<=n;++i)dist[f][i]=INF;
    using pii=pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
    dist[f][s]=0;
    while(!pq.empty()){
        int parentNode=pq.top().second;
        int parentDistance=pq.top().first;
        pq.pop();
        if(parentDistance>dist[f][parentNode])continue;
        for(auto &child:graph[f][parentNode]){
            int childNode=child.first;
            int childDis=child.second;
            if(childDis+parentDistance<dist[f][childNode]){
                dist[f][childNode]=childDis+parentDistance;
                pq.push({dist[f][childNode],childNode});
            }
        }
    }
}
void solve(int t){
    int n,m,s,t2,p;
    cin>>n>>m>>s>>t2>>p;
    for(int i=1;i<=n;++i){
        graph[0][i].clear();
        graph[1][i].clear();
    }
    vector<edgeInfo> edges;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        graph[0][u].push_back({v,w});
        graph[1][v].push_back({u,w});
        // graph[v].push_back({v,w});
        edges.push_back({u,v,w});
    }
    dijkstra(s,n,0);
    dijkstra(t2,n,1);
    int ans=-1;
    for(auto &edge:edges){
        int x=dist[0][edge.u]+edge.w+dist[1][edge.v];
        // if(x<0)continue;
        if(x<=p){
            ans=max(ans,edge.w);
        }
    }
    cout<<"Case "<<t<<": "<<ans<<endl;
}
signed main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        solve(i);
    }
}