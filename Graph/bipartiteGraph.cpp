//A graph is a bipartite if it can be colored in at most 2 color. In other words we can say that a graph contain no odd number of cycles is a bipartite graph
//Youtube explanation:https://www.youtube.com/watch?v=szDk4q4nHF4
//Question Link: https://www.geeksforgeeks.org/bipartite-graph/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
bool ans=true;
int n,m;//n is number of nodes and m is nimber of edges
vector<int> graph[N];//Adjacency list
vector<int> visited(N,-1);
void dfs(int vertex,int parent,int color){
    visited[vertex]=color;//visited array will store the color as well as the answer whether the node is visited or not;
    //visiting through all adjacency nodes
    for(auto adjacency:graph[vertex]){
        if(visited[adjacency]==-1){
            dfs(adjacency,vertex,3-color);//if color==2 then 3-color will be 1 and if the color is 1 then 3-1==2 as a result we got two color using this 3-color method
        }
        else{
            if(adjacency!=parent&&visited[adjacency]==color){
                //if color of adjacency nodes are same and they are not in parent-child relationship for undirected graph
                ans=false;//not bipariate
                break;
            }
        }
    }
}
int main(){
    cout<<"enter number of nodes and edges of the graph: ";
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=0;i<n;++i){
        //Traversing through all the unvisted nodes as, if they are not connected then we will not get our desired answer
        if(visited[i]==-1){
            dfs(i,-1,1);
        }
    }
    if(ans)cout<<"This graph is Bipartite\n";
    else cout<<"The graph is not a Bipartite\n";
}
//Sample input:
// 5 5
// 0 1
// 1 2
// 2 3
// 3 4
// 4 0

// Output:NO
//Explanation: Here is a cycle 0->1->2->3->4->0 which is consist of 5 nodes and 5 is odd. So this graph is not Bipartite
//Sample input:
// 5 4
// 0 1
// 1 2
// 2 3
// 3 4

// Output:YES

//Explanation: Here is no cycle so it is bipartite. Even if a even numbered cycle then it would be bipartite
