#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> tree[N];
vector<int> depth(N);
vector<int> height(N);
void dfs(int vertex,int parent){
    for(auto child:tree[vertex]){
        if(child==parent)continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);
    }
}
int main(){
    int n;
    cin>>n;

    for(int i=0;i<n-1;++i){
        int n1,n2;
        cin>>n1>>n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    dfs(1,0);
    for(int i=1;i<=n;++i){
        cout<<depth[i]<<" "<<height[i]<<endl;
    }
}
// sample input
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
// sample output
// 0 4
// 1 3
// 1 3
// 2 2
// 2 2
// 3 0
// 3 0
// 3 1
// 3 0
// 3 1
// 4 0
// 4 0
// 1 0