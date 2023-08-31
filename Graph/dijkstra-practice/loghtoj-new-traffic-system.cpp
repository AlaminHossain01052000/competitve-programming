// https://www.youtube.com/watch?v=SbeKmqzmAoA&list=PLoa_roVVsxA2Gqs0jsxzgvzXgcFpT-RYx&index=8
// https://lightoj.com/problem/new-traffic-system
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e4+10;
#define pii pair<int,int>

int d;
const int INF=LONG_LONG_MAX;
int dist[11][N];
struct nodeInfo{
    int weight;
    int count;
    int node;
};
struct edgeInfo{
    int v,w,type;
};
vector<edgeInfo> graph[N];
void dijkstra(int s,int n){
    int count=0;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=d;++j){
            dist[j][i]=INF;
        }
        
    }
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({0,0,s});
    while(!pq.empty()){
        int parentWeight=(pq.top())[0];
        int parentCount=(pq.top())[1];
        int parentNode=(pq.top())[2];
        pq.pop();
        if(dist[parentCount][parentNode]<parentWeight)continue;
        for(auto &child:graph[parentNode]){
            int childNode=child.v;
            int childWeight=child.w;
            int childType=child.type;
            int temp=parentCount;
            temp+=(childType==1);
            if(temp<=d&&dist[temp][childNode]>childWeight+parentWeight){
                dist[temp][childNode]=childWeight+parentWeight;
                pq.push({dist[temp][childNode],temp,childNode});
            }
        }
    }
    // priority_queue<nodeInfo,vector<nodeInfo>,greater<nodeInfo>> pq;
    // pq.push({0,0,s});
    // while(!pq.empty()){
    //     int parentWeight=pq.top().weight;
    //     int parentCount=pq.top().count;
    //     int parentNode=pq.top().node;
    //     pq.pop();
    //     if(dist[parentCount][parentNode]<parentWeight)continue;
    //     for(auto &child:graph[parentNode]){
    //         int childNode=child.v;
    //         int childWeight=child.w;
    //         int childType=child.type;
    //         int temp=parentCount;
    //         temp+=(childType==1);
    //         if(temp<=d&&dist[temp][childNode]>childWeight+parentWeight){
    //             dist[temp][childNode]=childWeight+parentWeight;
    //             pq.push({dist[temp][childNode],temp,childNode});
    //         }
    //     }
    // }


}
void solve(int t){
    int n,m,k;
    cin>>n>>m>>k>>d;
    for(int i=0;i<=n;++i){
        graph[i].clear();
        
    }
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w,0});
    }
    for(int i=1;i<=k;++i){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w,1});
    }
    dijkstra(0,n);
    int ans=INT_MAX;
    for(int i=0;i<=d;++i){
        // cout<<dist[i][n-1]<<endl;
        ans=min(ans,dist[i][n-1]);
    }
    if(ans==INF){
        cout<<"Case "<<t<<": Impossible\n";
    }
    else{
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    
    
}
signed main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        solve(i);
    }
}