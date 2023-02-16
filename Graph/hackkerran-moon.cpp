#include<bits/stdc++.h>
using namespace std;
#define int long long int
void dfs(int vertex,vector<bool> &visited,vector<int> graph[],vector<int> &temp){
   
    visited[vertex]=true;
    temp.push_back(vertex);
    // list[i].push_back(vertex);
    for(auto child:graph[vertex]){
        if(visited[child])continue;
        dfs(child,visited,graph,temp);
    }
}
int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int> graph[n];
    int j=0;
    for(auto vect:astronaut){
        graph[vect[0]].push_back(vect[1]);
        graph[vect[1]].push_back(vect[0]);
    }
    vector<bool> visited(n,false);
    vector<vector<int>> list;
    
    for(int i=0;i<n;++i){
        if(visited[i])continue;
        vector<int> temp;
        dfs(i,visited,graph,temp); 
        list.push_back(temp);
    }
    
    vector<int> counter;
    for(auto vect:list){
        counter.push_back(vect.size());
    }
    int m=counter.size();
    auto counterSum=counter;
    for(int i=counter.size()-2;i>=0;--i){
        counterSum[i]+=counterSum[i+1];

    }
    int ans=0;
    for(int i=0;i<counter.size()-1;++i){
        ans+=counter[i]*counterSum[i+1];
    }
    return ans;
}

signed main(){
    int n=100000;
    vector<vector<int>> astronaut={{1,2},{3,4}};
    cout<<journeyToMoon(n,astronaut)<<endl;
}