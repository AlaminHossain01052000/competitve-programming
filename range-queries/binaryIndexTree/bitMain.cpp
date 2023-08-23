// https://www.youtube.com/watch?v=DPiY9wFxGIw&t=74s
#include<bits/stdc++.h>
using namespace std;
#define int long long int
// i-(i&-i) will remove the last set from x. Suppose x=1101 then x-(x&-x)=1100
int N=2e5+10;//max array size
vector<int> bit(N);

int sum(int i){
    int ans=0;
    for(;i>0;i-=(i&(-i))){
        ans+=bit[i];
    }
    return ans;
}
//update will increase the value of ith index of bit by x and all other index which hold the value of ith index will be increase by 1
void update(int i,int x){
   
    for(;i<N;i+=(i&(-i))){
        bit[i]+=x;
    }
}

signed main(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n+1);
    for(int i=1;i<=n;++i)cin>>v[i];
    for(int i=1;i<=n;++i){
        update(i,v[i]);
    }
    
    while(q--){
        int qType;
        cin>>qType;
        if(qType==2){
            int l,r;
            cin>>l>>r;
            cout<<sum(r)-sum(l-1)<<endl;
        }
        else{
            int i,val;
            cin>>i>>val;
            update(i,val-v[i]);
            v[i]=val;
        }
    }
}