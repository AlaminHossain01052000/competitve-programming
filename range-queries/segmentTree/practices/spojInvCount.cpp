// https://www.spoj.com/problems/INVCNT/
#include<bits/stdc++.h>
using namespace std;
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
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(auto &i:v)cin>>i;
        sort(v.rbegin(),v.rend());
        vector<int>hash(v[0]+1,0);
        for(auto &i:v)hash[i]++;
        SGTree sg(v[0]);
        sg.build(0,0,hash.size()-1,hash);
        int ans=0;
        for(auto &ele:v){
            hash[ele]--;
            sg.update(0,0,hash.size()-1,ele,-1);
            ans+=sg.query(0,0,hash.size()-1,1,ele-1);
        }
        cout<<ans<<endl;



    }
}