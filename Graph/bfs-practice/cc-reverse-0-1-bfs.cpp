#include<bits/stdc++.h>
using namespace  std;
const int INF=1e9+10;
const int N=1e5+100;
vector<pair<int,int>> graph[N];
vector<int>level(N,INF);
void bfs(){
    deque<int> q;
    q.push_back(1);
    level[1]=0;
    while (!q.empty())
    {   
        auto parent=q.front();
        q.pop_front();
        for(auto &child:graph[parent]){
            if(level[child.first]>level[parent]+child.second){
                level[child.first]=level[parent]+child.second;
                if(child.second==1){
                    q.push_back(child.first);
                }
                else q.push_front(child.first);

            }
        }

        /* code */
    }
    
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        graph[u].push_back({v,0});
        graph[v].push_back({u,1});
    }
    bfs();
    cout<<level[n]<<endl;
}
// Sample input
// 7 7
// 1 2 
// 3 2
// 3 4
// 7 4
// 6 2
// 5 6
// 7 5
// Output:
// 2