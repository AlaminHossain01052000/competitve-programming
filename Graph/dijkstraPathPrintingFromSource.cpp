#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+100;
const int INF=LONG_LONG_MAX;
vector<pair<int,int>> graph[N];
vector<int> par(N,-1);//store parent of each node
void dijkstra(int source,int n){
    vector<int> distance(n+1,INF);
    // priority_queue<pair<int,int>> pq;//by default it is max heap but we need min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//min heap
    pq.push({0,source});
    distance[source]=0;
    // par[source]=-1;
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
                par[childNode]=parentNode;
            }
        }
    }
    
   

}
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    dijkstra(1,n);
    int destinationNode;
    cin>>destinationNode;
    int sourceNode=1;
    int x=par[destinationNode];
    if(x==-1)cout<<"No path is availabele\n";
    vector<int> path;
    path.push_back(destinationNode);
    while(x!=-1){
        path.push_back(x);
        if(x==sourceNode)break;
        x=par[x];
    }
    reverse(path.begin(),path.end());
    if(path[0]!=sourceNode)cout<<"No shortest path is exist between "<<sourceNode<<" to "<<destinationNode<<endl;
    else{
        for(auto &ele:path)cout<<ele<<' ';
        cout<<endl;
    }
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
// 6
// Output:
//1 2 5 6