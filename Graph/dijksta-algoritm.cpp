#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;
vector<pair<int,int>> graph[N];//Here pair is used to store the connected node as well as the weight

//Here n is the number of nodes
void dijkstra(int source,int n){
    vector<int> distance(N,INF);
    vector<int> visited(N,0);
    //to access the smallest distance at O(logn) time here set is used
    set<pair<int,int>> st;
    st.insert({0,source});//pair<int,int>={distance,node}
    distance[source]=0;
    while(st.size()>0){
        //Find the element who has smallest distance. It is d(u)
        auto smallestDistancedElement=*st.begin();
        int smallestDistance=smallestDistancedElement.first;
        int smallestNode=smallestDistancedElement.second;
        st.erase(st.begin());//pop out the recently visited node
        if(visited[smallestNode]==1)continue; //if the node is already visited then skip
        visited[smallestNode]=1;//mark the node as visited
        
        for(auto childPair:graph[smallestNode]){
            //Traverse through all the children or adjacent node of the smallest node or d(u)
            int childNode=childPair.first;
            int childWeight=childPair.second; //it is the weight from u to v;
            //if(d(u)+weight<d(v))then d(v)=d(u)+weight
            if((smallestDistance+childWeight)<distance[childNode]){
                distance[childNode]=(smallestDistance+childWeight);
                st.insert({distance[childNode],childNode});
            }
        }
        
    }

    for(int i=1;i<=n;++i){
        //distance from 1 to i is:
        cout<<i<<" "<<distance[i]<<" "<<endl;
    }

}
int main(){
    int n,m;
    cin>>n>>m;//n=number of nodes and m=number of edges
    for(int i=0;i<m;++i){
        int vertex1,vertex2,weight;
        cin>>vertex1>>vertex2>>weight;
        graph[vertex1].push_back({vertex2,weight});
    }
    dijkstra(1,n);
}

//sample input:
// 6 9
// 1 2 1
// 1 3 5
// 2 3 2
// 2 4 2
// 2 5 1
// 3 5 2
// 4 5 3
// 4 6 1
// 5 6 2
//Sample Output:
// 1 0 
// 2 1 
// 3 3 
// 4 3 
// 5 2 
// 6 4