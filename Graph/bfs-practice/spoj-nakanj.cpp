// https://www.spoj.com/problems/NAKANJ/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
map<pair<int,int>,bool> visited;
map<pair<int,int>,int> level;

vector<int> fx={-1,-2,-2,-1,1,2,2,1};
vector<int> fy={-2,-1,1,2,2,1,-1,-2};

//bfs use queue data structure to traverse a graph
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[{x,y}]=true; //mark the node as visited which is inserted in the queue once
    while(!q.empty()){
        auto frontNode=q.front();
        q.pop();
        // cout<<frontNode<<" ";
        //Traverse through all the childnode of the frontNode and inserted them in the queue as well as marked the child nodes as visited
        for(int i=0;i<8;++i){
            int left=frontNode.first+fx[i];
            int right=frontNode.second+fy[i];
            if(left<1||left>8||right<1||right>8)continue;
            if(visited[{frontNode.first+fx[i],frontNode.second+fy[i]}]==false){
                q.push({frontNode.first+fx[i],frontNode.second+fy[i]});
                visited[{frontNode.first+fx[i],frontNode.second+fy[i]}]=true;
                level[{frontNode.first+fx[i],frontNode.second+fy[i]}]=level[{frontNode.first,frontNode.second}]+1;
            }
            
        }
    }
    // cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=8;++i){
            for(int j=1;j<=8;++j){
                visited[{i,j}]=false;
                level[{i,j}]=0;
            }
        }
        pair<int,int> src;
    pair<int,int> des;

    string a,b;
    cin>>a>>b;
    src.first=a[1]-'0';
    src.second=a[0]-96;
    des.first=b[1]-'0';
    des.second=b[0]-96;
    
    level[{src.first,src.second}]=0;
    bfs(src.first,src.second);
    cout<<level[{des.first,des.second}]<<endl;
    }
    
    // bfs(1); //Considering the node 1 as root node
    // for(int i=1;i<=n;++i){
    //     cout<<"Level of node "<<i<<" => "<<level[i]<<endl;
    // }
}

// Sample Input
// 13 12
// 1 2
// 1 3
// 1 13
// 2 5
// 3 4
// 4 9
// 4 10
// 5 6
// 5 7
// 5 8
// 8 12
// 10 11
//Sample Output
//1 2 3 13 5 4 6 7 8 9 10 12 11 