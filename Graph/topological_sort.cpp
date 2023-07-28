// https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<int> graph[N]; // Here pair is used to store the connected node as well as the weight
vector<bool> visited(N, false);
vector<int> ans;
vector<int> inDegree(N);
int n;
int m;
void dfs(int vertex)
{
    visited[vertex] = true;
    for (auto child : graph[vertex])
    {
        if (!visited[child])
            dfs(child);
    }
    ans.push_back(vertex);
}
void topoSort()
{
    // code here
    
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto ele:ans)cout<<ele<<" ";
    cout<<endl;
    // return ans;
}
void bfs(int numberOfNodes){
    queue<int> q;
    
    vector<int> topoSortedGraph;
    for(int i=0;i<numberOfNodes;++i){
        if(inDegree[i]==0){
            q.push(i);
            visited[i]=true;
            topoSortedGraph.push_back(i);
        }
    }
    while(!q.empty()){
        int parent=q.front();
        q.pop();
        for(auto child:graph[parent]){
            if(visited[child])continue;
            inDegree[child]--;
            if(inDegree[child]==0){
                q.push(child);
                topoSortedGraph.push_back(child);
            }
        }
    }
    for(auto ele:topoSortedGraph){
        cout<<ele<<' ';
    }
    

}
int main()
{
    
    cin >> n >> m; // n=number of nodes and m=number of edges
    for (int i = 0; i < m; ++i)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph[vertex1].push_back(vertex2);
        inDegree[vertex2]++;
    }
    cout<<"Topological Sort using DFS : ";
    topoSort();
    cout<<endl;
    for(int i=0;i<n;++i){
        visited[i]=false;
    }
    //I can run a topological sort using bfs if all the components are connected
    cout<<"Topological Sort using BFS : ";
    bfs(n);
    
}

// sample input:
// 6 6
// 5 0
// 5 2
// 4 0
// 4 1
// 2 3
// 3 1

// Sample Output:
// 5 4 2 3 1 0 
