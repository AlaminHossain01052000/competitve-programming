#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
bool visited[N];
vector<int> color(N,0);
int cycleStart,cycleEnd;
//detection cycle in directed graph
bool hasCycle(int vertex){
    color[vertex]=1;
    for(auto child:graph[vertex]){
        if(color[child]==0){
            if(hasCycle(child)){
                return true;
            }
        }
        else if(color[child]==1){
            cycleStart=child;
            cycleEnd=vertex;
            return true;
        }
    }
    color[vertex]=2;
    return false;
}
bool dfs(int vertex,int parent){
    visited[vertex]=true;
    bool hasCycle=false;
    for(auto child:graph[vertex]){
        if(visited[child]&&child==parent)continue;
        if(visited[child]&&child!=parent){
            return true;
        }
        hasCycle|=dfs(child,vertex);
    }
    return hasCycle;
}
int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;++i){
        int n1,n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    bool ans=false;
    for(int i=1;i<=n;++i){
        if(visited[i])continue;
        if(dfs(i,0)){
            ans=true;
            break;
        }
    }
    cout<<ans<<endl;
}
// Sample input:
// 8 6
// 1 2
// 2 3
// 2 4
// 3 5
// 6 7
// 1 5
//Sample output
// 1