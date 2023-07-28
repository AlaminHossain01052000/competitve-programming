
// https://codeforces.com/problemset/problem/872/B
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;++i)cin>>v[i];
    if(k>2)cout<<*max_element(v.begin(),v.end())<<endl;
    else if(k==1)cout<<*min_element(v.begin(),v.end())<<endl;
    else{
        cout<<max(v[0],v[n-1])<<endl;
    }
}