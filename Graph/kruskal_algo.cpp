#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N]={};
int size[N]={};
//make an independent component consists of a single node who is a parent of himself
void make(int u){
    parent[u]=u;
    size[u]=1;
    }
//find root node of a node in a union component
int find(int u){
    if(parent[u]==u)return u;
    //path compression
    return parent[u]=find(parent[u]);
}
//make union of two root node
void Union(int a,int b){
    a=find(a);//finding root node of a
    b=find(b);//finding root node of b
    //a!=b means checking whether they are joined previously or not
    if(a!=b){
        //join the smaller one under the larger one each time
        if(size[a]<size[b]){
            swap(a,b);//By the swapping function a become larger and b become smaller
        }
        parent[b]=a;
        size[a]+=size[b];//As now 'b' is a child of 'a' so the size of 'a' is inceased by 'b'
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        //making n amount of independent components
        make(i);
    }
    //As we have to store the weight as well as the connected nodes so the graph vector is declare like below
    vector<pair<int,pair<int,int>>> graph;
    for(int i=0;i<m;++i){
        int u,v,wt;
        cin>>u>>v>>wt;
        graph.push_back({wt,{u,v}});
    }
    sort(graph.begin(),graph.end());
    int totalWeight=0;
    for(auto edge:graph){
        int weight=edge.first;
        int u=edge.second.first; //edge.second is a pair<u,v>
        int v=edge.second.second;
        
        if(find(u)==find(v))continue;//if u and v has same parent then if I join them then it creates a cycle in the tree
        Union(u,v);
        //u,v is an edge of minimum spanning tree who contain weight wt
        cout<<u<<" "<<v<<" "<<weight<<endl;
        totalWeight+=weight;
    }
    cout<<totalWeight<<endl; //totalWeight of the minimum spanning tree
}

// ==========Input=======
// 6
// 9
// 5 4 9
// 5 1 4
// 1 2 2
// 1 4 1
// 2 3 3
// 2 4 3
// 3 4 5
// 2 6 7
// 3 6 8
// ========output========
// 1 4 1
// 1 2 2
// 2 3 3
// 5 1 4
// 2 6 7
// 17