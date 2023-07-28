#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> tree[N];
int subtreeSum[N];
int evenCount[N];
void dfs(int vertex,int parent){
    if(vertex%2==0){
        evenCount[vertex]++;
    }
    subtreeSum[vertex]+=vertex;
    for(auto child:tree[vertex]){
        if(child==parent)continue;
        dfs(child,vertex);
        subtreeSum[vertex]+=subtreeSum[child];
        evenCount[vertex]+=evenCount[child];
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
        cout<<subtreeSum[i]<<" "<<evenCount[i]<<endl;
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
// 91 6
// 40 4
// 37 2
// 34 2
// 38 3
// 6 1
// 7 0
// 20 2
// 9 0
// 21 1
// 11 0
// 12 1
// 13 0