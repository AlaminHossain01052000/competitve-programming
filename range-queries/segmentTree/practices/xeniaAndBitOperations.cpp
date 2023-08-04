// https://codeforces.com/contest/339/problem/D
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class SGTree{
    
    public:
        vector<int>   segmentTree;
        SGTree(int n){
            segmentTree.resize(4*n+1); // For array length n the max number of nodes of a segment tree can be at most 4*n
        }
        //O(4*n)
        void build(int index,int left,int right,vector<int> &v,int level){
            if(left==right||level==0){
                segmentTree[index]=v[left];
                return;
            }
            int mid=(left+right)>>1;
            build(2*index+1,left,mid,v,level-1); //left child
            build(2*index+2,mid+1,right,v,level-1); //right child
            
          
                if(level&1){
                    segmentTree[index]=(segmentTree[2*index+1]|segmentTree[2*index+2]);
                }
                else{
                    segmentTree[index]=(segmentTree[2*index+1]^segmentTree[2*index+2]);
                }
            
            
        }
        // O(logn)
        int query(int index,int left,int right,int l,int r,int level){
            //no overlap [l,r][left,rigth] | [left,right][l,r]
            if(r<left||right<l){
                return 0;
            }
            //complete overlap l left right r
            if(l<=left&&right<=r){
                return segmentTree[index];
            }
            //partial overlap l left r right | left l r right etc...
            int mid=(left+right)>>1;
            int x=query(2*index+1,left,mid,l,r,level-1);
            int y=query(2*index+2,mid+1,right,l,r,level-1);
            if(level&1){
                    return x|y;
                }
                else{
                    return x^y;
                }
        }
        // O(logn)
        void update(int index,int left,int right,int i,int val,int level){
            if(left==right){
                segmentTree[index]=val;
                return;
            }
            int mid=(left+right)>>1;
            if(i<=mid) update(2*index+1,left,mid,i,val,level-1);
            else update(2*index+2,mid+1,right,i,val,level-1);
            if(level&1){
                    segmentTree[index]=(segmentTree[2*index+1]|segmentTree[2*index+2]);
                }
                else{
                    segmentTree[index]=(segmentTree[2*index+1]^segmentTree[2*index+2]);
                }
        }
};
signed main(){
    fast
    int n,m;
    cin>>n>>m;
    int sz=1<<n;
    vector<int> v(sz);
    for(int i=0;i<sz;++i)cin>>v[i];
    SGTree sg(sz);
    sg.build(0,0,sz-1,v,n);
    // for(auto &ele:sg.segmentTree)cout<<ele<<' ';
    // cout<<endl;
    // return 0;
    while(m--){
        int index,value;
        cin>>index>>value;
        v[index-1]=value;
        sg.update(0,0,sz-1,index-1,value,n);
        cout<<sg.segmentTree[0]<<endl;

    }
}