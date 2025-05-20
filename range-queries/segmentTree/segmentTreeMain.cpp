#include<bits/stdc++.h>
using namespace std;
// For Range minimum queries
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
            segmentTree[index]=min(segmentTree[2*index+1],segmentTree[2*index+2]);
        }
        // O(logn)
        int query(int index,int left,int right,int l,int r){
            //no overlap [l,r][left,rigth] | [left,right][l,r]
            if(r<left||right<l){
                return INT_MAX;
            }
            //complete overlap l left right r
            if(l<=left&&right<=r){
                return segmentTree[index];
            }
            //partial overlap l left r right | left l r right etc...
            int mid=(left+right)>>1;
            int x=query(2*index+1,left,mid,l,r);
            int y=query(2*index+2,mid+1,right,l,r);
            return min(x,y);
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
            segmentTree[index]=min(segmentTree[2*index+1],segmentTree[2*index+2]);
        }
};
// For Range Sum Queries======>
// class SGTree{
//     vector<int>   segmentTree;
//     public:
//         SGTree(int n){
//             segmentTree.resize(4*n+1); // For array length n the max number of nodes of a segment tree can be at most 4*n
//         }
//         //O(4*n)
//         void build(int index,int left,int right,vector<int> &v){
//             if(left==right){
//                 segmentTree[index]=v[left];
//                 return;
//             }
//             int mid=(left+right)>>1;
//             build(2*index+1,left,mid,v); //left child
//             build(2*index+2,mid+1,right,v); //right child
//             segmentTree[index]=(segmentTree[2*index+1]+segmentTree[2*index+2]);
//         }
//         // O(logn)
//         int query(int index,int left,int right,int l,int r){
//             //no overlap [l,r][left,rigth] | [left,right][l,r]
//             if(r<left||right<l){
//                 return 0;
//             }
//             //complete overlap l left right r
//             if(l<=left&&right<=r){
//                 return segmentTree[index];
//             }
//             //partial overlap l left r right | left l r right etc...
//             int mid=(left+right)>>1;
//             int x=query(2*index+1,left,mid,l,r);
//             int y=query(2*index+2,mid+1,right,l,r);
//             return x+y;
//         }
//         // O(logn)
//         void update(int index,int left,int right,int i,int val){
//             if(left==right){
//                 segmentTree[index]=val;
//                 return;
//             }
//             int mid=(left+right)>>1;
//             if(i<=mid) update(2*index+1,left,mid,i,val);
//             else update(2*index+2,mid+1,right,i,val);
//             segmentTree[index]=(segmentTree[2*index+1]+segmentTree[2*index+2]);
//         }
// };
// Problem:
// Given 2 array v1={2,3,1,5,7} and v2={1,5,2}
// Given q queries. Each of query can have to types. If queryType=1 then l1,r1,l2, and r2 will be given and have to find the minimum of the range [l1,r1] from v1 and minimum of the range [l2,r2] from v2 and minimum of the minimum.Simply can say min(min[l1,r1],min[l2,r2])
// For query type 2 the array no, index and a value will be given. We have to update the value of the index of the given array
int main(){
    int n1,n2;
    cin>>n1;
    vector<int> v1(n1);
    for(int i=0;i<n1;++i)cin>>v1[i];
    cin>>n2;
    vector<int> v2(n2);
    for(int i=0;i<n2;++i)cin>>v2[i];
    SGTree sg1(n1);
    SGTree sg2(n2);
    sg1.build(0,0,n1-1,v1);
    sg2.build(0,0,n2-1,v2);
    int q;
    cin>>q;
    while(q--){
        int queryType;
        cin>>queryType;
        if(queryType==1){
            int  l1, r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            int mini1=sg1.query(0,0,n1-1,l1,r1);
            int mini2=sg2.query(0,0,n2-1,l2,r2);
            cout<<"Ans : ";
            cout<<min(mini1,mini2)<<endl;

        }
        else{
            int arrayNo,updateIndex,value;
            cin>>arrayNo>>updateIndex>>value;
            if(arrayNo==1){
                sg1.update(0,0,n1-1,updateIndex,value);
                v1[updateIndex]=value;
            }
            else{
                sg2.update(0,0,n2-1,updateIndex,value);
                v2[updateIndex]=value;
            }
        }
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
