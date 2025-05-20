// https://cses.fi/problemset/task/1672/
// https://www.youtube.com/watch?v=dgqUjD3jgPU&list=PLoa_roVVsxA094Nb0xdyXmI0yTsj42zDz&index=15
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=510;
const int INF=LONG_LONG_MAX-1000;
int dist[N][N];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i!=j)dist[i][j]=INF;
        }
    }
    
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v],w);
        dist[v][u]=min(dist[v][u],w);
    }
    //floyed warshall
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dist[i][k]!=INF&&dist[k][j]!=INF)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(dist[a][b]==INF)cout<<-1<<endl;
        else cout<<dist[a][b]<<endl;
    }
    
}