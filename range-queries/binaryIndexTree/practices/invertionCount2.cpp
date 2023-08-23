// https://www.youtube.com/watch?v=DPiY9wFxGIw&t=74s
// https://www.spoj.com/problems/INVCNT/
// This problem is as same as invertion count but here the constraints are 1<=N<=1e9
// https://github.com/luvk1412/youtube_codes/blob/master/binary_indexed_trees/q2_inversion_ct.cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e7+10;//max array size
vector<int>bit(N);
int sum(int i){
    int ans=0;
    for(;i>0;i-=(i&-i))ans+=bit[i];
    return ans;
}
void update(int i,int val){
    for(;i<N;i+=(i&-i))bit[i]+=val;
}
signed main(){
    int n;
    cin>>n;
    vector<int>v(n+1);
    map<int,int>m;
    for(int i=1;i<=n;++i){
        cin>>v[i];
        m[v[i]];
    }
    int temp=1;
    for(auto &pr:m){
        pr.second=temp++;
    }
    //compressing the numbers
    for(int i=1;i<=n;++i){
        v[i]=m[v[i]];
    }
    for(int i=1;i<=n;++i){
        update(v[i],0);
    }
    int invCount=0;
    for(int i=1;i<=n;++i){
        invCount+=(sum(N-5)-sum(v[i]));
        update(v[i],1);
    }
    cout<<invCount<<endl;

    
}
// Input:
// 5
// 2000000000 3000000000 8000000000 6000000000 1000000000
// Output:
// 5