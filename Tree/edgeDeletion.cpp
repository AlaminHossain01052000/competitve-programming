#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e9+7;
vector<int> graph[N];
int subtree_sum[N];
vector<int> value(N);
void dfs(int vertex,int parent){
    subtree_sum[vertex]+=value[vertex];
    for(auto child:graph[vertex]){
        if(child==parent) continue;
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
    }
}
int main(){
    int n;
    cin>>n;
    //value of the nodes
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        value[i]=x;
    }
    //connected nodes
    for(int i=0;i<n-1;++i){
        int n1,n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    dfs(1,0);
    int ans=0;
    // We have to delete every possible edges except root node and compare the value
     
    for(int i=2;i<=n;++i){
        int part1=subtree_sum[i];
        int part2=subtree_sum[1]-subtree_sum[i];//part 2 is the subtree sum of the full tree except the part  subtree
        ans=max(ans*1LL,(part1*1LL*part2)%M);
    }
    cout<<ans<<endl;

}
//Sample Input
// 4
// 10 5 12 6
// 1 2
// 1 4
// 4 3  
//Sample output
//270