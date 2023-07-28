// https://codeforces.com/contest/1245/problem/D
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

void make(int i,int parent[],int size[]){
    parent[i]=i;
    size[i]=1;
}
int find(int x,int parent[]){
    if(parent[x]==x)return x;
    return parent[x]=find(parent[x],parent);
}
void Union(int a,int b,int parent[],int size[]){
    a=find(a,parent);
    b=find(b,parent);
    if(a!=b){
        if(size[a]<size[b])swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}
int main(){
    int n;
    cin>>n;
    int parent[N];
    int size[N];
    vector<pair<int,int>> cities(n+1);
    vector<int> costs(n+1);
    vector<int> k(n+1);
    for(int i=1;i<=n;++i){
        cin>>cities[i].first>>cities[i].second;
    }
    for(int i=1;i<=n;++i)cin>>costs[i];
    for(int i=1;i<=n;++i)cin>>k[i];

    for(int i=1;i<=n;++i){
        make(i,parent,size);
    }
    vector<pair<long long,pair<int,int>>> graph;
    for(int i=1;i<=n;++i){
        graph.push_back({costs[i]+0LL,{0,i}});
    }

    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            long long distance=abs(cities[i].first-cities[j].first)+abs(cities[i].second-cities[j].second);
            long long cost=distance*(k[i]+k[j]);
            graph.push_back({cost,{i,j}});
        }
    }
    sort(graph.begin(),graph.end());
    long long total_cost=0;
    vector<int> powerHouse;
    vector<pair<int,int>> wires;
    for(auto &edges:graph){
        int u=edges.second.first;
        int v=edges.second.second;
        long long wt=edges.first;
        if(find(u,parent)==find(v,parent))continue;
        Union(u,v,parent,size);
        if(u==0||v==0)powerHouse.push_back(max(u,v));
        else{
            wires.push_back({u,v});
        }
        total_cost+=wt;
    }
    cout<<total_cost<<endl;
    cout<<powerHouse.size()<<endl;
    for(auto ele:powerHouse)cout<<ele<<" ";
    cout<<endl;
    cout<<wires.size()<<endl;
    for(auto prs:wires)cout<<prs.first<<" "<<prs.second<<endl;
}
// Input:
// 3
// 2 1
// 1 2
// 3 3
// 23 2 23
// 3 2 3

// Output:
// 27
// 1
// 2 
// 2
// 1 2
// 2 3
