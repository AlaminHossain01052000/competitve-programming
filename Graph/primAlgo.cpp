#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
int N;//number of nodes
int findMin(vector<bool> &inMst,vector<int> &key){
    int minIndex=-1;
    int minWeight=INT_MAX;
    for(int i=0;i<N;++i){
        if(!inMst[i]&&key[i]<minWeight){
            minWeight=key[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void printMST(vector<int> &parent){
    cout << "Edge \tWeight\n";
    for (int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}
void primsAlgo(){
    vector<int> parent(N);
    vector<int> key(N,INT_MAX);
    vector<bool> inMst(N,false);//Initially the mst is empty
    parent[0]=-1;//0 is the parent node. So it has no parent node
    key[0]=0;
   
    for(int count=1;count<=N-1;++count){
        int u=findMin(inMst,key);
        inMst[u]=true;
        for(int v=0;v<N;++v){
            if(!inMst[v]&&graph[u][v]&&graph[u][v]<key[v]){
                key[v]=graph[u][v];
                parent[v]=u;
            }
        }
    }
    printMST(parent);
}
int main(){
    N=5;//0 to 4
    graph={ { 0, 2, 0, 6, 0 },
            { 2, 0, 3, 8, 5 },
            { 0, 3, 0, 0, 7 },
            { 6, 8, 0, 0, 9 },
            { 0, 5, 7, 9, 0 } };
    primsAlgo();
}