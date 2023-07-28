#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int INF=1e9+10;
int n,m;
int main(){
    int distance[N][N];
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            
            if(i==j)distance[i][j]=0;//distance[1][1]==distance[2][2]=0
            else distance[i][j]=INF;
        }
    }
    for(int i=0;i<m;++i){
        int n1,n2,dist;
        cin>>n1>>n2>>dist;
        distance[n1][n2]=dist;//here weight is used as the distance
    }
    //Floyd Warshell Algorithm
    //k=1 means including node 1 in each pair if there exist a path through 1. Similarly, k=2,k=3...k=n means including node k int eack pair of i to j and calculate the path distance i to k and k to j
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                //if distance[i][k]==INF then there is no path between i to k as well as if distance[k][j]==INF then there is no path between k to j. We can go i to j via k if and only if there exist a path i to k and k to j
                if(distance[i][k]!=INF&&distance[k][j]!=INF)
                    distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);

            }
        }
    }
    for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(distance[i][j]==INF)cout<<"I"<<" ";
                else cout<<distance[i][j]<<" ";

            }
            cout<<endl;
        }
}
//sample input:
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
//Sample Output:
// 0 1 3 3 2 4 
// I 0 2 2 1 3 
// I I 0 I 2 4 
// I I I 0 3 1 
// I I I I 0 2 
// I I I I I 0 