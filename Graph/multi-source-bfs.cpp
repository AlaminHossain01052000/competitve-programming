#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int INF=1e6+10;
int n,m;
int graph[N][N];
int visited[N][N];
int level[N][N];
vector<pair<int,int>> movements={
    {1,0},{-1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}
};
bool isValid(int i,int j){
    return i>=0&&j>=0&&i<n&&j<m;
}
int bfs(){
    int maxi=0;
    vector<pair<int,int>> maxis;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            maxi=max(maxi,graph[i][j]);
            
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(graph[i][j]==maxi){
                maxis.push_back({i,j});
            }
            
        }
    }

    queue<pair<int,int>> q;
    for(auto pr:maxis){
        q.push({pr.first,pr.second});
        visited[pr.first][pr.second]=1;
        level[pr.first][pr.second]=0;
    }
    int ans=0;
    while(!q.empty()){
        auto frontPair=q.front();
        int parentX=frontPair.first;
        int parentY=frontPair.second;
        q.pop();
        for(auto movement:movements){
            int childX=parentX+movement.first;
            int childY=parentY+movement.second;
            if(!isValid(childX,childY)){
                continue;
            }
            if(visited[childX][childY]){
                continue;
            }
            visited[childX][childY]=1;
            level[childX][childY]=level[parentX][parentY]+1;
            q.push({childX,childY});
            ans=max(ans,level[childX][childY]);
        }
    }
    return ans;

}
void reset(){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            level[i][j]=INF;
            visited[i][j]=0;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
       cin>>n>>m;
       reset();
       for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>graph[i][j];
        }
       }
       cout<<bfs()<<endl;
    }
}