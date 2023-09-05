// https://codeforces.com/problemset/problem/277/A
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
bool visited[N];
void dfs(int node){
    visited[node]=true;
    for(auto &child:graph[node]){
        if(!visited[child])dfs(child);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;++i){
        graph[i].clear();
        visited[i]=false;
    }
    map<int, vector<int>>  languages;
    int zeroCount=0;
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        if(k==0)zeroCount++;
        for(int j=1;j<=k;++j){
            int x;
            cin>>x;
            languages[x].push_back(i);
        }
    }
    for(auto pr:languages){
        int langNo=pr.first;
        auto employees=pr.second;
        for(int i=0;i<employees.size();++i){
            for(int j=i+1;j<employees.size();++j){
                int u=employees[i];
                int v=employees[j];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
    }
    int count=0;

    for(int i=1;i<=n;++i){
        
        if(!visited[i]){
            dfs(i);
            count++;
        }
    }
    if(zeroCount<n)count--;
    cout<<count<<endl;

}