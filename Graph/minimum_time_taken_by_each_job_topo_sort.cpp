#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
vector<bool> visited(N,false);
vector<int> topoSort;
vector<int> inDegree(N,0);
vector<int> job(N,0);
//topological sort
void bfs(int numberOfNodes){
    queue<int> q;
    
    for(int i=1;i<=numberOfNodes;++i){
        if(inDegree[i]==0){
            q.push(i);
            job[i]=1;
        }
    }
    while(!q.empty()){
        int parent=q.front();
        q.pop();
        for(auto child:graph[parent]){
            inDegree[child]--;
            if(inDegree[child]==0){
                q.push(child);
                job[child]=job[parent]+1;
            }
        }
    }

}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        inDegree[y]++;
    }

    bfs(n);
    for(int i=1;i<=n;++i){
        cout<<job[i]<<" ";
    }
    cout<<endl;
}

// 10 13
// 1 3
// 1 4
// 1 5
// 2 3
// 2 8
// 2 9
// 3 6
// 4 6
// 4 8
// 5 8
// 6 7
// 7 8
// 8 10

// output:
// 1 1 2 2 2 3 4 5 2 6