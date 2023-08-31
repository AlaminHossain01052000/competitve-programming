#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
const int INF=INT_MAX;
vector<pair<int,int>> graph[N];
int dist[N];
void dijkstra(int source,int n){
    for(int i=0;i<=n;++i)dist[i]=INF;
    // priority_queue<pair<int,int>> pq;//by default it is max heap but we need min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//min heap
    pq.push({0,source});
    dist[source]=0;
    while(!pq.empty()){
        int parentNode=pq.top().second;
        int parentDistance=pq.top().first;
        pq.pop();
        if(dist[parentNode]<parentDistance)continue; //elementing the unnecessary node
        for(auto &child:graph[parentNode]){
            int childNode=child.first;
            int childWeight=child.second;
            if(max(childWeight,parentDistance)<dist[childNode]){
                dist[childNode]=max(childWeight,parentDistance);
                pq.push({dist[childNode],childNode});
            }
        }
    }
    

}
int main(){
    int tx;
    cin>>tx;
    for(int t=1;t<=tx;++t){
        int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;++i)graph[i].clear();
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int s;
    cin>>s;

    dijkstra(s,n);
    cout<<"Case "<<t<<": \n";
    for(int i=0;i<n;++i){
        if(dist[i]==INF)cout<<"Impossible\n";
        else cout<<dist[i]<<endl;
    }
    // cout<<endl;
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
// Output:
// 1 -> 1 : 0
// 1 -> 2 : 1
// 1 -> 3 : 3
// 1 -> 4 : 3
// 1 -> 5 : 2
// 1 -> 6 : 4