#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];//Adjacency List Graph
bool visited[N];//This array will store the information of a vertext whether it is visited or not
//storing inTime and outTime
vector<int> inTime(N);
vector<int> outTime(N);
int t=1;//time
//Time complexity of dfs is O(V+E)
void dfs(int vertex){
    visited[vertex]=true;
    inTime[vertex]=t++;//Every parent node will traveresed faster than his all child node
    //Visit all the child of the vertex
    for(auto child:graph[vertex]){
        //Print parent and it's corresponding childs
    
        if(visited[child])continue;
        //Call Function dfs of the child
        dfs(child);
    }
    outTime[vertex]=t++;//After visiting his all child and setting child's inTime/outTime now I can set outTime of parent node
}
//given two nodes x and y. Tell whether y is a child of x or not
bool isChild(int x,int y){
    return ((inTime[x]<inTime[y])&&(outTime[x]>outTime[y]));
}
int main(){
    int numberOfNodes;
    cin>>numberOfNodes;
    for(int i=1;i<=numberOfNodes-1;++i){
        int node1,node2;
        cin>>node1>>node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    dfs(1);
    cout<<isChild(2,8)<<endl; //YES
    cout<<isChild(1,5)<<endl; //YES
    cout<<isChild(2,5)<<endl; //NO
    cout<<isChild(8,2)<<endl; //NO
}
// Sample input
// 9
// 1 2
// 1 3
// 2 6
// 2 7
// 3 4
// 3 5
// 6 9
// 7 8

// Output
// YES
// YES
// NO
// NO