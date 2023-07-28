#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> tree[N];
int parent[N]; //parent[i]=parent of ith node,i.e. parent of 12 is 8 for sample input
void dfs(int vertex,int par=-1){
    //par means parent node
    parent[vertex]=par;  //parent of root node=-1
    for(auto child:tree[vertex]){
        //as child node is a parent of parent node so we have to avoid this situation using "continue"
        if(child==par)continue;
        dfs(child,vertex);
    }
}
//finding path from root node to any node. Path of node 6: 1->2->5->6 according to sample input
vector<int> findPath(int v){
    vector<int> ans;
    //parent of root node is -1
    while(v!=-1){
        ans.push_back(v);
        v=parent[v];
    }
    //Now the ans vector indicating path from node to root. To get path from root to node we have to reverse ans
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int numberOfNodes;
    cin>>numberOfNodes;
    //number of edges of any tree is numberOfNodes-1
    for(int i=1;i<=numberOfNodes-1;++i){
        int node1,node2;
        cin>>node1>>node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }
    dfs(1);//considering 1 as root node
    //Input 2 nodes to find there ancestor
    int x,y;
    cin>>x>>y;
    vector<int> pathOfX=findPath(x);
    vector<int> pathOfY=findPath(y);

    int minLength=min(pathOfX.size(),pathOfY.size());
    int lca=-1;
    //The lca is nearest common node between pathOfX and pathOfY
    for(int i=0;i<minLength;++i){
        if(pathOfX[i]==pathOfY[i]){
            lca=pathOfX[i]; // lca=pathOfY[i] is also okay
        }
        else break;
    }
    cout<<"LCA of "<<x<<" and "<<y<<" is => ";
    cout<<lca<<endl;
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


//Input of nodes are 6 and 12 and the answer is 5
//Input of nodes are 9 and 10 and the answer is 4
//Input of nodes are 9 and 11 and the answer is 4
//Input of nodes are 9 and 13 and the answer is 1