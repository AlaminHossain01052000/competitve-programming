// https://www.spoj.com/problems/INVCNT/
// https://www.youtube.com/watch?v=NOykDuH1_OY
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e7+10;
int sum(int i,vector<int> &bit){
    int ans=0;
    for(;i>0;i-=(i&(-i))){
        ans+=bit[i];
    }
    return ans;
}
//update will increase the value of ith index of bit by x and all other index which hold the value of ith index will be increase by 1
void update(int i,int x,vector<int> &bit){
   
    for(;i<N;i+=(i&(-i))){
        bit[i]+=x;
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n+1);
        vector<int>bit(N);
        // bit.resize(N,0);
        for(int i=1;i<=n;++i){
            cin>>v[i];
            update(v[i],0,bit);
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            int x=v[i];
            ans+=(sum(N-5,bit)-sum(x,bit));
            update(x,1,bit);
        }
        cout<<ans<<endl;
    }
    
}
// Input:
// 2

// 3
// 3
// 1
// 2

// 5
// 2
// 3
// 8
// 6
// 1


// Output:
// 2
// 5


// Explanation:
// Given Array: 2 3 8 6 1
// inv[2]=0
// inv[3]=0
// inv[8]=0
// inv[6]=1
// inv[1]=4
// Ans=4+1=5
// The approach is that first we go to an element suppose 3. Then see how many numbers greater than 3 is occured in the element before 3 by using sum(Max)-Sum(3). Thenwe've updated the 3 by 1