#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int sizeA[N];
void make(int v){
    parent[v]=v;//parent of independent node is itself
    sizeA[v]=1;//sizeA of a single node is 1
}
//find root parent of a node
int find(int v){
    //root node is a parent of himself
    if(v==parent[v])return v;
    //path compression
    return parent[v]=find(parent[v]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    //joining the smaller one with the bigger tree
    // if(size[a]<size[b]){
    //     parent[a]=b;
    //     size[b]+=size[a];
    // }
    // else {
    //     parent[b]=a;
    //     size[a]+=size[b];
    // }
    if(a!=b){
        if(sizeA[a]<sizeA[b])swap(a,b);
        parent[b]=a;
        sizeA[a]+=sizeA[b];
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        make(i);
    }
    int q;
    cin>>q;
    while(q--){
        int n1,n2;
        cin>>n1>>n2;
        Union(n1,n2);
    }
    // find number of disjoint components
    int ans=0;
    for(int i=1;i<=n;++i){
        if(find(i)==i){
            ans++;
        }
    }
    cout<<ans<<endl;
}

//sample input
// 4
// 2
// 1 2
// 3 4

// Sample output
// 2
