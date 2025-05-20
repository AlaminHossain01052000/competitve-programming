#include<bits/stdc++.h>
using namespace std;
int INF=1e9+10;
int n,m;//n=number of nodes and m=number of edges
int sourceNode;
struct Edge{
    int u,v,weight;
};
vector<Edge> graph;

void minimumDistance(vector<int> &distance){
    for(int i=0;i<n;++i){
        cout<<"Distance from source "<<sourceNode<<" to "<<i<<" is : "<<distance[i]<<endl;
    }
}
//Finding a path from source to a node
void findPath(int node,vector<int> &parent,vector<int> &distance){
        if(distance[node]==INF){
            cout<<"There is node path from "<<sourceNode<<" to "<<node<<endl;
            return;
        }
        vector<int> path;
        //parent of source node is -1
        for(int v=node;v!=-1;v=parent[v]){
            path.push_back(v);
        }
        reverse(path.begin(),path.end());
        cout<<"The path from source node "<<sourceNode<<" to "<<node<<" is : ";
        for(auto ele:path){
            cout<<ele<<" -> ";
        }
        cout<<endl;
}
void bellman_ford_algo(vector<int> &distance,vector<int> &parent){
    //Answer will store here
    
    distance[sourceNode]=0;//Most of the time assume that source node is 0
    while(1){
        bool isModified=false;
        for(auto edge:graph){
            int node1=edge.u;
            int node2=edge.v;
            int weightOfEdge=edge.weight;
            if(distance[node1]==INF)continue;//If we do not continue here then in next line if the weightOfEdge is negative then INF+(-weightOfEdge)=INF-weightOfEdge will store the distance of node 2 as INF-2 or INF-3,...INF-x etc. Which will hamper our code.*You must remove this condition if souce code is not defined
            
            if(distance[node1]+weightOfEdge<distance[node2]){
                distance[node2]=distance[node1]+weightOfEdge;
                isModified=true;
                parent[node2]=node1;//To know the path we store the parent data 

            }
        }
        //To reduce time complexity we used isModified variable as we know if there is no modification in the graph it means we acheive our desired least distance from source to each node
        if(isModified==false)break;
    }

}
//Case of negative weighted cycle
void bellman_ford_2(vector<int> &distance,vector<int> &parent){
    // distance[sourceNode]=0;
    int x=-1;
    for(int i=0;i<n;++i){
        x=-1;
        for(auto edge:graph){
            int node1=edge.u;
            int node2=edge.v;
            int wght=edge.weight;
            // if(distance[node1]==INF)continue;
            if(distance[node1]+wght<distance[node2]){
                distance[node2]=max(INF*-1,distance[node1]+wght);//To avoid integer overflow for negative weighted cycle we have used INF*-1
                parent[node2]=node1;
                x=node2;
            }
        }
    }
        if(x==-1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            return;
            int y=x;
            for(int i=0;i<n;++i){
                y=parent[y];
            }
            vector<int> path;
            for(int current=y;;current=parent[current]){
                path.push_back(current);
                if(current==y&&path.size()>1){
                    //we are fall in a negative cycle as current =y and path.size()>1
                    break;
                }
            }
            reverse(path.begin(),path.end());
            cout<<"The path of negative weighted cycle is : ";
            for(auto ele:path){

                cout<<ele<<" -> ";
            }
            cout<<endl;
        }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;++tc){
        graph.clear();
        int p;
        cin>>n>>m>>p;
        for(int i=0;i<m;++i){
        int u,v,in,e;
        cin>>u>>v>>in>>e;
        Edge newEdge;
        newEdge.u=u;
        newEdge.v=v;
        newEdge.weight=(p*e)-in;
        graph.push_back(newEdge);
        }
        // sourceNode=0;
        vector<int> distance(n,INF);
        vector<int> parent(n,-1);
        cout<<"Case "<<tc<<": ";
        bellman_ford_2(distance,parent);
    }



    

    //Bellman ford 1
    // bellman_ford_algo(distance,parent);
    // minimumDistance(distance);
    // while(1){
    //     printf("Enter a node from %d to %d to find the sortest path from source-node %d to that node (else press -1 to break the loop): ",0,n-1,sourceNode);
    
    //     int randNode;
    //     cin>>randNode;
    //     if(randNode==-1){
    //         break;
    //     }
    //     findPath(randNode,parent,distance);
    // }
    //Bellman ford 2
  
}
// Input:
// 6 9
// 0 1 6
// 0 2 4 
// 0 3 5 
// 1 4 -1
// 2 1 -2
// 2 4 3 
// 3 2 -2
// 3 5 -1
// 4 5 3 
// 0
// 5
// 4
// 3
// 2
// 1
// 0

// output:
// Distance from source 0 to 0 is : 0
// Distance from source 0 to 1 is : 1
// Distance from source 0 to 2 is : 3
// Distance from source 0 to 3 is : 5
// Distance from source 0 to 4 is : 0
// Distance from source 0 to 5 is : 3


//Input for checking negative weighted cycle
// 4 4
// 0 1 4
// 1 2 2
// 2 3 -5
// 3 1 -8
// 0

// Output:
// The path of negative weighted cycle is : 3 -> 1 -> 2 -> 3 ->