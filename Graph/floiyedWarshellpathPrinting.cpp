// https://www.youtube.com/watch?v=UBJICmkiAPs&list=PLoa_roVVsxA094Nb0xdyXmI0yTsj42zDz&index=16
#include<bits/stdc++.h>
using namespace std;
const int N=100;
const int INF=1e9;
int dist[N][N];
int nxt[N][N];//helps to store path
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            //setting dist[i][j]=0 if i==j otherwise INF
            if(i!=j)dist[i][j]=INF;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            //setting dist[i][j]=0 if i==j otherwise INF
            nxt[i][j]=j;//Assuming all path can be accessed from each other using the second node
        }
    }
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v],w);//one directional graph
    }
    
    //floyed warshall
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dist[i][k]!=INF&&dist[k][j]!=INF&&dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];

                    //if [i][j] is relaxed then update the path
                    nxt[i][j]=nxt[i][k];//we can go from i to j via the node (i to k) or the node we need to go from i to k
                    
                }
            }
        }
    }

    int q;
    cin>>q;
    while (q--)
    {
        int src,dest;
        cin>>src>>dest;
        cout<<src<<" ";
        int currentNode=src;
        while(currentNode!=dest){
            currentNode=nxt[currentNode][dest];
            cout<<currentNode<<" ";
        }
        cout<<endl;
    }
    
        
    

    
    }
/*
Input:
4 6
1 2 2
2 3 2
3 4 2
1 2 10
1 3 12
2 4 11
6
1 2
1 3
1 4
2 3
2 4
3 4

Output:
1 2
1 2 3
1 2 3 4
2 3
2 3 4
3 4
*/   

