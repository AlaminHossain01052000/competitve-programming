#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int matrixGraph[N][N];//All matrixGraph[i][j]==0 as it is declared in global
vector<int> listGraph[N];//listGraph[i] will show the list of nodes that is connected with the i-th node
vector<pair<int,int>> listWeightedGraph[N];//Here, pair is used to store the connected node along with it's weight
int main(){
    int numberOfVertices,numberOfEdges;
    cin>>numberOfVertices>>numberOfEdges;
    for(int i=0;i<numberOfEdges;++i){
        //taking input of connected nodes of an edge
        int startNode,endNode;
        cin>>startNode>>endNode;
        //Taking input of connected nodes and weights
            // int startNode,endNode,weight;
            // cin>>startNode>>endNode>>weight;

        //Because of undirected graph as i is connected to j therefore j is also connected to i
        matrixGraph[startNode][endNode]=1;
        matrixGraph[endNode][startNode]=1;

        //Taking input of adjacency list
        listGraph[startNode].push_back(endNode);
        listGraph[endNode].push_back(startNode);
        //Taking input into adjacency list along with weight
            // listWeightedGraph[startNode].push_back({endNode,weight});
            // listWeightedGraph[endNode].push_back({startNode,weight});
    }
}
