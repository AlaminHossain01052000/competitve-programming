#include<bits/stdc++.h>
using namespace std;


void solve(vector<int> &v,int m,int n,int total,int sum,vector<int> hash,int i){
    cout<<sum<<endl;
    if(sum>m||i>=n){
        return;
    }
    if(sum==m){
        for(int i=0;i<hash.size();++i){
            cout<<hash[i]<<" ";
            return;
        }
    }
    //include
    total-=v[i];
    sum+=v[i];
    hash.push_back(i);
    solve(v,m,n,total,sum,hash,i+1);
    hash.pop_back();
    //exclude
    total-=v[i];
    solve(v,m,n,total,sum,hash,i+1);

    hash.pop_back();

}
int main(){
    vector<int> v={1,5,11,5};
    int m=16;
    int n=4;
    int total=22;
    int sum=0;
    vector<int> hash;
    solve(v,m,n,total,sum,hash,0);
}