#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
bool visited[N];
vector<vector<int>> connectedComponentsStorage;
vector<int> tempCC_Storage;//temporary connected components storage
void dfs(int vertex){
    tempCC_Storage.push_back(vertex);
    visited[vertex]=true;
    for(auto child:graph[vertex]){
        if(visited[child])continue;
        dfs(child);
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;++i){
        int n1,n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    int countOfComponents=0;
    for(int i=1;i<=n;++i){
        if(visited[i])continue;
        tempCC_Storage.clear();
        dfs(i);
        connectedComponentsStorage.push_back(tempCC_Storage);
        countOfComponents++;
    }
    cout<<countOfComponents<<endl;
    for(auto components:connectedComponentsStorage){
        for(auto ele:components){
            cout<<ele<<' ';
        }
        cout<<endl;
    }
}
// Sample input:
// 8 5
// 1 2
// 2 3
// 2 4
// 3 5
// 6 7

// Sample Output:
// 3