// https://codeforces.com/contest/380/problem/C
#include<bits/stdc++.h>
using namespace std;
struct nodeInfo{
    int opening=0;
    int closing=0;
    int full=0;
};
void build(int index,int left,int right,string &v,vector<nodeInfo>&segmentTree){
    if(left==right){
        segmentTree[index].opening=(v[left]=='(');
        segmentTree[index].closing=(v[left]==')');
        return;
    }
    int mid=(left+right)>>1;
    build(2*index+1,left,mid,v,segmentTree);
    build(2*index+2,mid+1,right,v,segmentTree);
    segmentTree[index].full=min(segmentTree[2*index+1].opening,segmentTree[2*index+2].closing)+segmentTree[2*index+1].full+segmentTree[2*index+2].full;
    segmentTree[index].opening=segmentTree[2*index+1].opening+segmentTree[2*index+2].opening-min(segmentTree[2*index+1].opening,segmentTree[2*index+2].closing);
    segmentTree[index].closing=segmentTree[2*index+1].closing+segmentTree[2*index+2].closing-min(segmentTree[2*index+1].opening,segmentTree[2*index+2].closing);
}
nodeInfo query(int index,int left,int right,int l,int r,vector<nodeInfo>&segmentTree){
    //no overlap l r lefdt right left right l r
    if(r<left||right<l){
        nodeInfo node;
        return node;
    }
     
   //complete overlap l left right r
    if(l<=left&&right<=r){
       return segmentTree[index];
    }
    // partial overlap
    int mid=(left+right)>>1;
    nodeInfo x=query(2*index+1,left,mid,l,r,segmentTree);
    nodeInfo y=query(2*index+2,mid+1,right,l,r,segmentTree);
     nodeInfo node;
       node.full=x.full+y.full+min(x.opening,y.closing);
       node.opening=x.opening+y.opening-min(x.opening,y.closing);
       node.closing=x.closing+y.closing-min(x.opening,y.closing);
    //    node.closing-=min(x.opening,y.closing);
       return node;
}
// void update(int index,int left,int right, int i,int val,vector<int>&segmentTree){
//     if(left==right){
//         segmentTree[index]=val;
//         return;
//     }
//     int mid=(left+right)>>1;
//     if(i<=mid)update(2*index+1,left,mid,i,val,segmentTree);
//     else update(2*index+2,mid+1,right,i,val,segmentTree);
//     segmentTree[index]=min(segmentTree[2*index+1],segmentTree[2*index+2]);

// }
int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<nodeInfo> segementTree(4*n+1);
    build(0,0,n-1,s,segementTree);
    map<pair<int,int>,int> preAns;
    int q;
    cin>>q;
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        if(preAns[make_pair(l,r)]){
            cout<<preAns[make_pair(l,r)]<<endl;
            continue;
        }
        int ans=2*query(0,0,n-1,l,r,segementTree).full;
        preAns[make_pair(l,r)]=ans;
        cout<<ans<<endl;
        
    }
    
}