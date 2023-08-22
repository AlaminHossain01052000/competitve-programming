// https://cses.fi/problemset/task/1651
// http://www.shafaetsplanet.com/planetcoding/?p=1591
// Lazy propagation is basically used to update value in a range. It use a propagation method along with each sum and the propagation value denotes that all child of that node must be increased by propagte value.
//time complexity is O(4*n) to build, O(logn) for each query and update
#include<bits/stdc++.h>
using namespace std;
#define int long long int
struct info{
    int sum=0;
    int propate=0;
};
class LazySGTree{
    public:
        vector<info> segmentTree;
        LazySGTree(int n){
            segmentTree.resize(4*n+1);
        }
        void build(int index,int left,int right,vector<int> &v){
            if(left==right){
                segmentTree[index].sum=v[left];
                segmentTree[index].propate=0;
                return;
            }
            int mid=(left+right)>>1;
            build(2*index+1,left,mid,v);
            build(2*index+2,mid+1,right,v);
            segmentTree[index].sum=segmentTree[2*index+1].sum+segmentTree[2*index+2].sum;
            segmentTree[index].propate=0;
            

        }
        int query(int index,int left,int right,int l,int r,int parentsPropagate){
            //no overlap
            //left right l r || l r left right
            if(r<left||l>right){
                return 0;
            }
            //complete overlap 
            // l left right r
            //
            if(l<=left&&right<=r){
                return segmentTree[index].sum+parentsPropagate*(right-left+1);
            }
            int mid=(left+right)>>1;
            //If a child's multiple parent carries propagate value then each of it will summed up
            int x = query(2*index+1,left,mid,l,r,parentsPropagate+segmentTree[index].propate);
            
            int y = query(2*index+2,mid+1,right,l,r,parentsPropagate+segmentTree[index].propate);
            return x+y;
        }
        void update(int index,int left,int right,int l,int r,int value){
            //no overlap
            //left right l r || l r left right
            if(r<left||l>right){
                return;
            }
            //complete overlap 
            // l left right r
            if(l<=left&&right<=r){
                segmentTree[index].sum+=(right-left+1)*value;
                segmentTree[index].propate+=value;
                return;
            }
            int mid=(left+right)>>1;
            
            update(2*index+1,left,mid,l,r,value);
            update(2*index+2,mid+1,right,l,r,value);
            
            //clear all previous segmentTree[index].sum and assign the new sum of childs
            segmentTree[index].sum=segmentTree[2*index+1].sum+segmentTree[2*index+2].sum+(right-left+1)*segmentTree[index].propate;
            
        }

};
signed main(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    for(auto &ele:v)cin>>ele;
    LazySGTree segTree(n);
    segTree.build(0,0,n-1,v);
    while(q--){
        int qType;
        cin>>qType;
        if(qType==1){
            //update each value of the range [l,r] by one
            int l,r,value;
            cin>>l>>r>>value;
            l--;
            r--;
            segTree.update(0,0,n-1,l,r,value);
        }
        else{
            //print the value at index k
            int k;
            cin>>k;
            k--;
            cout<<segTree.query(0,0,n-1,k,k,0)<<endl;
        }
    }
}