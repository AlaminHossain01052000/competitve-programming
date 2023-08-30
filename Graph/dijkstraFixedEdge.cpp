// https://lightoj.com/problem/not-the-best
// Explanation:https://www.youtube.com/watch?v=QHzlWjlQLb0&list=PLoa_roVVsxA2Gqs0jsxzgvzXgcFpT-RYx&index=6
#include<bits/stdc++.h>
using namespace std;
const int N=5010;
vector<pair<int,int>> graph[N];
vector<vector<int>> dist(2,vector<int>(N));
const int INF=INT_MAX;
struct edgeInfo{
    int u,v,w;
};
void diskstra(int s,int n,int f){
    for(int i=1;i<=n;++i)dist[f][i]=INF;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    dist[f][s]=0;
    while(!pq.empty()){
        int parentNode=pq.top().second;
        int parentWeight=pq.top().first;
        pq.pop();
        if(dist[f][parentNode]<parentWeight)continue;
        for(auto &child:graph[parentNode]){
            int childWeight=child.second;
            int childNode=child.first;
            if(childWeight+parentWeight<dist[f][childNode]){
                dist[f][childNode]=childWeight+parentWeight;
                pq.push({dist[f][childNode],childNode});
            }
        }
    }
}
void solve(int t){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)graph[i].clear();
    vector<edgeInfo> edges;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
        edges.push_back({u,v,w});

    }
    diskstra(1,n,0);
    diskstra(n,n,1);
    int s1=dist[0][n];
    int s2=INF;
    for(auto &edge:edges){
        int node1=edge.u;
        int node2=edge.v;
        int weight=edge.w;
        int distance=min(dist[0][node1]+dist[1][node2],dist[1][node1]+dist[0][node2]);
        if(distance+weight>s1)s2=min(s2,distance+weight);
        else if(distance+weight==s1){
            s2=min(s2,distance+(3*weight));
        }
    }
    // cout<<s2<<endl;
    cout<<"Case "<<t<<": "<<s2<<endl;

}
signed main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;++i){
        solve(i);
    }
}