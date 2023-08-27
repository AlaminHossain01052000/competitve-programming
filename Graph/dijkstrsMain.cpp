#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
const int INF=INT_MAX;
vector<pair<int,int>> graph[N];
void dijkstra(int source,int n){
    vector<int> distance(n+1,INF);
    // priority_queue<pair<int,int>> pq;//by default it is max heap but we need min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//min heap
    pq.push({0,source});
    distance[source]=0;
    while(!pq.empty()){
        int parentNode=pq.top().second;
        int parentDistance=pq.top().first;
        pq.pop();
        if(distance[parentNode]<parentDistance)continue; //elementing the unnecessary node
        for(auto &child:graph[parentNode]){
            int childNode=child.first;
            int childWeight=child.second;
            if(childWeight+parentDistance<distance[childNode]){
                distance[childNode]=childWeight+parentDistance;
                pq.push({distance[childNode],childNode});
            }
        }
    }
    for(int i=1;i<=n;++i){
        cout<<source<<" -> "<<i<<" : "<<distance[i]<<endl;
    }

}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    dijkstra(1,n);
}
// 6 9
// 1 2 1
// 1 3 5
// 2 3 2
// 2 4 2
// 2 5 1
// 3 5 2
// 4 5 3
// 4 6 1
// 5 6 2
// Output:
// 1 -> 1 : 0
// 1 -> 2 : 1
// 1 -> 3 : 3
// 1 -> 4 : 3
// 1 -> 5 : 2
// 1 -> 6 : 4