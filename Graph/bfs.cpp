#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
bool visited[N];
int level[N];
//bfs use queue data structure to traverse a graph
void bfs(int root){
    queue<int> q;
    q.push(root);
    visited[root]=true; //mark the node as visited which is inserted in the queue once
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        cout<<frontNode<<" ";
        //Traverse through all the childnode of the frontNode and inserted them in the queue as well as marked the child nodes as visited
        for(auto child:graph[frontNode]){
            if(visited[child]==false){
                q.push(child);
                visited[child]=true;
                level[child]=level[frontNode]+1;
            }
            
        }
    }
    cout<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int n1,n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    level[1]=0;
    bfs(1); //Considering the node 1 as root node
    for(int i=1;i<=n;++i){
        cout<<"Level of node "<<i<<" => "<<level[i]<<endl;
    }
}

// Sample Input
// 13 12
// 1 2
// 1 3
// 1 13
// 2 5
// 3 4
// 4 9
// 4 10
// 5 6
// 5 7
// 5 8
// 8 12
// 10 11
//Sample Output
//1 2 3 13 5 4 6 7 8 9 10 12 11 