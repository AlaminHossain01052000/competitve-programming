#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];//Adjacency List Graph
bool visited[N];//This array will store the information of a vertext whether it is visited or not

//Time complexity of dfs is O(V+E)
void dfs(int vertex){
    visited[vertex]=true;
    cout<<vertex<<" "<<endl;
    //Visit all the child of the vertex
    for(auto child:graph[vertex]){
        //Print parent and it's corresponding childs
        cout<<"Parent "<<vertex<<" Child : "<<child<<endl;
        if(visited[child])continue;
        //Call Function dfs of the child
        dfs(child);
    }
}
int main(){
    int numberOfNodes,numberOfEdges;
    cin>>numberOfNodes>>numberOfEdges;
    for(int i=0;i<numberOfEdges;++i){
        int node1,node2;
        cin>>node1>>node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    dfs(1);
}
//Sample Input:
// 6 8 
// 1 3
// 1 5
// 2 3
// 2 6
// 3 4
// 3 5
// 3 6
// 4 6