#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+10;
struct edge{
    int u,v,w;
};
vector<edge> graph;
void bellmanFord(vector<int> &destination,int sourceNode,int n){
    destination[sourceNode]=0;
    for(int i=1;i<=n;++i){
        for(auto &e:graph){
            int u=e.u;
            int v=e.v;
            int w=e.w;
            if(destination[u]==INF)continue;
            if(destination[v]>destination[u]+w){
                destination[v]=destination[u]+w;
            }

        }
    }
}
void solve(int t){
    int n;
    cin>>n;
    vector<int> cost(n+1);
    for(int i=1;i<=n;++i){
        cin>>cost[i];
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        int weight=(cost[v]-cost[u])*(cost[v]-cost[u])*(cost[v]-cost[u]);
        graph.push_back({u,v,weight});

    }
    vector<int> destination(n+1,INF);
    bellmanFord(destination,1,n);
    // for(int i=1;i<=n;++i)cout<<destination[i]<<" ";cout<<endl;
    int q;
    cin>>q;
    cout<<"Case "<<t<<": \n";
    while(q--){
        int v;
        cin>>v;
        if(destination[v]<3||destination[v]==INF){
            cout<<"?\n";
        }else{
            cout<<destination[v]<<endl;
        }
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        solve(i);
    }
}