// https://cses.fi/problemset/task/1197/
// https://www.youtube.com/watch?v=3H7F5sZ0sa0
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int INF=1e18;
int n,m;//n=number of nodes and m=number of edges
int sourceNode;
struct Edge{
    int u,v,weight;
};
vector<Edge> graph;

void bellman_ford_2(vector<int> &distance,vector<int> &parent){
    distance[sourceNode]=0;
    int x=-1;
    for(int i=0;i<n;++i){
        x=-1;
        for(auto edge:graph){
            int node1=edge.u;
            int node2=edge.v;
            int wght=edge.weight;
            // if(distance[node1]==INF)continue;
            if(distance[node1]+wght<distance[node2]){
                distance[node2]=max(-INF,distance[node1]+wght);//To avoid integer overflow for negative weighted cycle we have used INF*-1
                parent[node2]=node1;
                x=node2;
            }
        }
    }
    // for(int i=1;i<=n;++i)cout<<i<<" "<<distance[i]<<endl;
    // cout<<endl;
        if(x==-1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            int y=x;
            for(int i=0;i<n;++i){
                y=parent[y];
            }
            vector<int> path;
            for(int current=y;;current=parent[current]){
                path.push_back(current);
                if(current==y&&path.size()>1){
                    //we are fall in a negative cycle as current =y and path.size()>1
                    break;
                }
            }
            reverse(path.begin(),path.end());
            // cout<<"The path of negative weighted cycle is : ";
            for(auto ele:path){

                cout<<ele<<" ";
            }
            cout<<endl;
        }
    
}
signed main(){
   
    cin>>n>>m;
    graph.clear();
    for(int i=0;i<m;++i){
        int u,v,weight;
        cin>>u>>v>>weight;
        Edge newEdge;
        newEdge.u=u;
        newEdge.v=v;
        newEdge.weight=weight;
        graph.push_back(newEdge);
        // graph.push_back({v,u,weight});
    }
    sourceNode=1;
    vector<int> distance(n+10,INF);
    vector<int> parent(n+10,-1);
    bellman_ford_2(distance,parent);
}
// Input:
// 6 9
// 0 1 6
// 0 2 4 
// 0 3 5 
// 1 4 -1
// 2 1 -2
// 2 4 3 
// 3 2 -2
// 3 5 -1
// 4 5 3 
// 0
// 5
// 4
// 3
// 2
// 1
// 0

// output:
// Distance from source 0 to 0 is : 0
// Distance from source 0 to 1 is : 1
// Distance from source 0 to 2 is : 3
// Distance from source 0 to 3 is : 5
// Distance from source 0 to 4 is : 0
// Distance from source 0 to 5 is : 3


//Input for checking negative weighted cycle
// 4 4
// 0 1 4
// 1 2 2
// 2 3 -5
// 3 1 -8
// 0

// Output:
// The path of negative weighted cycle is : 3 -> 1 -> 2 -> 3 ->