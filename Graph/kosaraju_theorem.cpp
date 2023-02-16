#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
vector<int> graph_reverse[N];
vector<bool> visited;
vector<int> order;
vector<int> components;
vector<int> root_nodes;//Store all root nodes
vector<int> root;//store the root of each node
vector<vector<int>> adj_scc;//adjacency strongly connected components
int n,m;//n is number of nodes and m is number if edges
void dfs1(int vertex){
    visited[vertex]=true;
    for(auto u:graph[vertex]){
        if(!visited[u]){
            dfs1(u);
        }
    }
    order.push_back(vertex);
}
void dfs2(int vertex){
    visited[vertex]=true;
    components.push_back(vertex);
    for(auto u:graph_reverse[vertex]){
        if(!visited[u]){
            dfs2(u);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph_reverse[v].push_back(u);
    }

    visited.assign(n,false);
    for(int i=0;i<n;++i){
        if(!visited[i])
            dfs1(i);
    }
    
    visited.assign(n,false);
    int numberOfComponents=0;
    reverse(order.begin(),order.end());
    
    for(auto ele:order){
        if(!visited[ele]){
            
            dfs2(ele);
            numberOfComponents++;
            components.clear();
            
        }
    }
    
    cout<<"Number of strongly connected components : "<<numberOfComponents<<endl;
}
//Input
// 5 5
// 0 3
// 0 2
// 1 0
// 2 1
// 3 4
// Output:
// Number of strongly connected components : 3s