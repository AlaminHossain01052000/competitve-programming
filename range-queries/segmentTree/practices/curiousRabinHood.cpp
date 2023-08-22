#include<bits/stdc++.h>
using namespace std;
#define int long long int
class SGTree{
    vector<int>   segmentTree;
    public:
        SGTree(int n){
            segmentTree.resize(4*n+1); // For array length n the max number of nodes of a segment tree can be at most 4*n
        }
        //O(4*n)
        void build(int index,int left,int right,vector<int> &v){
            if(left==right){
                segmentTree[index]=v[left];
                return;
            }
            int mid=(left+right)>>1;
            build(2*index+1,left,mid,v); //left child
            build(2*index+2,mid+1,right,v); //right child
            segmentTree[index]=(segmentTree[2*index+1]+segmentTree[2*index+2]);
        }
        // O(logn)
        int query(int index,int left,int right,int l,int r){
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
            int x=query(2*index+1,left,mid,l,r);
            int y=query(2*index+2,mid+1,right,l,r);
            return x+y;
        }
        // O(logn)
        void update(int index,int left,int right,int i,int val){
            if(left==right){
                segmentTree[index]=val;
                return;
            }
            int mid=(left+right)>>1;
            if(i<=mid) update(2*index+1,left,mid,i,val);
            else update(2*index+2,mid+1,right,i,val);
            segmentTree[index]=(segmentTree[2*index+1]+segmentTree[2*index+2]);
        }
};
void solve(int t){
    cout<<"Case "<<t<<":"<<endl;
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    for(auto &ele:v)cin>>ele;
    SGTree sg(n);
    sg.build(0,0,n-1,v);
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            int i;
            cin>>i;
            cout<<v[i]<<endl;
            v[i]=0LL;
            sg.update(0,0,n-1,i,0LL);

        }
        else if(x==2){
            int i,val;
            cin>>i>>val;
            // int val=
            sg.update(0,0,n-1,i,val+v[i]);
            v[i]+=val;

        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<sg.query(0,0,n-1,l,r)<<endl;
        }
      
    }

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        
        solve(i);
    }

}
// Input:
// 5
// 2 3 1 5 7
// 3
// 1 5 2
// 6
// 1
// 0 2 0 1
// 2
// 1 2 4
// 1
// 1 3 1 2
// 2
// 2 1 0
// 2
// 2 1 1
// 1 
// 0 5 0 2
// Output:
// 1
// 2
// 1
