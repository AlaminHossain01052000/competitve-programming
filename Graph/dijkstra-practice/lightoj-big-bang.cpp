// https://lightoj.com/problem/instant-view-of-big-bang
// https://www.youtube.com/watch?v=m6gODVCa8UI
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int sourceNode=0,n,m;
const int INF=1e9+10;
struct Edge{
    int u,v,w;
};
vector<Edge> graph;
vector<int> adj[N];
bool isRelaxed[N];
bool visited[N];
void dfs(int &node){
    visited[node]=true;
    for(auto &child:adj[node]){
        if(!visited[child]){
            dfs(child);
        }
    }
}
void bellmanFord(vector<int> &distance){
    distance[sourceNode]=0;
    for(int i=1;i<=n;++i){
        for(auto &edge:graph){
        int v=edge.v;
        int u=edge.u;
        int w=edge.w;
        if(distance[u]+w<distance[v]){
            distance[v]=distance[u]+w;
            if(i==n)isRelaxed[v]=true;
        }
    }
    }
    
}
void solve(int t){
    cin>>n>>m;
    graph.clear();
    for(int i=0;i<=n;++i){
        visited[i]=false;
        adj[i].clear();
        isRelaxed[i]=false;
    }
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        //take input in reverse
        graph.push_back({v,u,w});
        adj[v].push_back(u);
    }
        vector<int> distance(n,INF);
        bellmanFord(distance);
        bool hasCycle=false;
        for(int i=0;i<n;++i){
            if(isRelaxed[i]){
                dfs(i);
                hasCycle=true;
            }
        }
        if(!hasCycle){
            cout<<"Case "<<t<<": "<<"impossible\n";
            return;
        }
        cout<<"Case "<<t<<":";
        for(int i=0;i<n;++i){
            if(visited[i]){
                cout<<" "<<i;
            }
        }
        cout<<endl;
    

}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        solve(i);
    }
}