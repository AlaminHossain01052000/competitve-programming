// https://codeforces.com/contest/459/problem/D
// https://www.spoj.com/problems/INVCNT/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n+1);
        for(int i=1;i<=n;++i)cin>>v[i];
        map<int,int> cnt;
        set<int>st;
        vector<int>left(n);
        for(int i=1;i<n;++i){
            cnt[v[i]]++;
            left[i]=cnt[v[i]];
            
        }
        map<int,int>cnt2;
        vector<int>right(n+1);
        for(int i=n;i>1;--i){
            cnt2[v[i]]++;
            right[i]=cnt2[v[i]];
            st.insert(right[i]);
        }
        map<int,vector<int>>mp;
        for(auto &ele:st){
            mp[ele].resize(n+1,0);
        }
        for(int i=n;i>1;--i){
            mp[right[i]][i]++;
        }
        for(auto ele:st){
            for(auto &vect:mp[ele]){
                for(int i=1;i<=n;++i)vect[i]+=vect[i-1];
            }
        }
        



    }
}