// https://www.codechef.com/problems/REVERSE
// https://www.youtube.com/watch?v=SQOQ99stCas
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int INF=1e9+10;
vector<pair<int,int>> graph[N];//this graph array will contain list of nodes along with their weights. pair is used to store the connected node as well as the weight
vector<int> level(N,INF);
int bfs(int n){
    deque<int> q;
    q.push_back(1);
    level[1]=0;
    while(!q.empty()){
        int currentNode=q.front();
        // cout<<currentNode<<endl;
        q.pop_front();
        for(auto child:graph[currentNode]){
            int node=child.first;
            int weight=child.second;
            if(level[currentNode]+weight<level[node]){
                level[node]=level[currentNode]+weight;
                if(weight==0){
                    q.push_front(node);
                }
                else q.push_back(node);
            }
        }
    }
    return level[n]==INF?-1:level[n];
}
int main(){
    int n,m;//n=number of nodes and m=number of edges
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int n1,n2;
        cin>>n1>>n2;//n1 and n2 is a pair of nodes of an edge
        if(n1==n2)continue;
        graph[n1].push_back({n2,0});
        graph[n2].push_back({n1,1});//create a reverse edge and give a penalty 1
    }
    cout<<bfs(n)<<endl;
    return 0;
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