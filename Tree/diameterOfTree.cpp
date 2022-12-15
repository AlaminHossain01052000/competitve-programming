#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> tree[N];
int depth[N];
void dfs(int vertex,int parent=-1){
    //Traversing through all child nodes of vertex
    for(auto child:tree[vertex]){
        //As parent and child are connected as neighbour so we have to handle the situation by avoiding the situation
        if(child==parent)continue;
        //Depth of any node=depth of parent node +1
        depth[child]=depth[vertex]+1;

        //dfs on child where parent is vertex
        dfs(child,vertex);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n-1;++i){
        int n1,n2;
        cin>>n1>>n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    dfs(1);//Let's consider 1 as root node

    //Finding max depth of the tree when 1 is the root as well as farest or deepest node from root
    int maxDepth=INT_MIN;
    int deepestNode=-1;
    for(int i=1;i<=n;++i){
        maxDepth=max(maxDepth,depth[i]);
        if(maxDepth==depth[i]){
            deepestNode=i;
        }
    }
    //Clear all value of depth array which is calculated using root 1
    memset(depth,0,sizeof(depth));

    //considering the deepest node as root and run a dfs
    dfs(deepestNode);

    //new max depth of the deepest node is the diameter of the tree
    maxDepth=INT_MIN;
    for(int i=1;i<=n;++i){
        maxDepth=max(maxDepth,depth[i]);
    }
    cout<<"Diameter of the tree is : "<<maxDepth<<endl;
}
// Sample Input
// 13
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
//8