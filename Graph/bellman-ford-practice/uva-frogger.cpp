#include <bits/stdc++.h>
using namespace std;
double INF = 1e9 + 10;
int n, m; // n=number of nodes and m=number of edges
int sourceNode;
struct Edge
{
    int u, v;
    double weight;
};
vector<Edge> graph;

void minimumDistance(vector<int> &distance)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "Distance from source " << sourceNode << " to " << i << " is : " << distance[i] << endl;
    }
}
// Finding a path from source to a node
void findPath(int node, vector<int> &parent, vector<int> &distance)
{
    if (distance[node] == INF)
    {
        cout << "There is node path from " << sourceNode << " to " << node << endl;
        return;
    }
    vector<int> path;
    // parent of source node is -1
    for (int v = node; v != -1; v = parent[v])
    {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    cout << "The path from source node " << sourceNode << " to " << node << " is : ";
    for (auto ele : path)
    {
        cout << ele << " -> ";
    }
    cout << endl;
}
void bellman_ford_algo(vector<double> &distance, vector<int> &parent)
{
    // Answer will store here

    distance[sourceNode] = 0.0; // Most of the time assume that source node is 0
    while (1)
    {
        bool isModified = false;
        for (auto &edge : graph)
        {
            int node1 = edge.u;
            int node2 = edge.v;
            double weightOfEdge = edge.weight;
            if (distance[node1] == INF)
                continue; // If we do not continue here then in next line if the weightOfEdge is negative then INF+(-weightOfEdge)=INF-weightOfEdge will store the distance of node 2 as INF-2 or INF-3,...INF-x etc. Which will hamper our code

            if (distance[node1] + weightOfEdge < distance[node2])
            {
                distance[node2] = distance[node1] + weightOfEdge;
                isModified = true;
                parent[node2] = node1; // To know the path we store the parent data
            }
        }
        // To reduce time complexity we used isModified variable as we know if there is no modification in the graph it means we acheive our desired least distance from source to each node
        if (isModified == false)
            break;
    }
}
int main()
{
    int t = 1;
    while (cin >> n)
    {
        if (n == 0)
            break;
        graph.clear();
        vector<pair<int, int>> temp;
        for (int i = 1; i <= n; ++i)
        {
            int x, y;
            cin >> x >> y;
            temp.push_back({x, y});
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                double wt = abs(temp[i].first - temp[j].first) * abs(temp[i].first - temp[j].first);
                wt += abs(temp[i].second - temp[j].second) * abs(temp[i].second - temp[j].second);
                wt = sqrt(wt);
                graph.push_back({i, j, wt});
            }
        }
        sourceNode=0;
        vector<double> distance(n, INF);
        vector<int> parent(n, -1);
        bellman_ford_algo(distance, parent);

        cout << "Scenario #" << t << endl;
        cout << "Frog Distance = " << fixed <<setprecision(3)<<distance[n - 1] << endl<<endl;
        t++;
        // cout<<distance[n-1]<<endl;
    }
    // cout<<"Enter Number of Nodes and Number of Edges of the graph : ";
    // cin>>n>>m;
    // cout<<"Enter "<<m<<" edges in next " <<m <<" lines just like this : node1 node2 weight\n";
    // for(int i=0;i<m;++i){
    //     int u,v,weight;
    //     cin>>u>>v>>weight;
    //     Edge newEdge;
    //     newEdge.u=u;
    //     newEdge.v=v;
    //     newEdge.weight=weight;
    //     graph.push_back(newEdge);
    // }
    // cout<<"Enter the source node : ";
    // cin>>sourceNode;

    // vector<int> distance(n,INF);
    // vector<int> parent(n,-1);

    // Bellman ford 1
    //  bellman_ford_algo(distance,parent);
    //  minimumDistance(distance);
    //  while(1){
    //      printf("Enter a node from %d to %d to find the sortest path from source-node %d to that node (else press -1 to break the loop): ",0,n-1,sourceNode);

    //     int randNode;
    //     cin>>randNode;
    //     if(randNode==-1){
    //         break;
    //     }
    //     findPath(randNode,parent,distance);
    // }
    // Bellman ford 2
    // bellman_ford_2(distance,parent);
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

// Input for checking negative weighted cycle
//  4 4
//  0 1 4
//  1 2 2
//  2 3 -5
//  3 1 -8
//  0

// Output:
// The path of negative weighted cycle is : 3 -> 1 -> 2 -> 3 ->