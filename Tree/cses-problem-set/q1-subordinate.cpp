#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int> height[N];

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n+1);
    for(int i=2;i<=n;++i){
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    
    vector<int> size(n+1,0);
    for(int i=n;i>=1;--i){
        for(auto ele:v[i]){
            // cout<<ele<<" ";
            size[i]+=size[ele]+1;
        }
    }
    for(int i=1;i<=n;++i){
        cout<<size[i]<<" ";
    }
    cout<<endl;
}