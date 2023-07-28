#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool isSufficientWood(vector<int> &heightOfTrees,int currentCuttingHeight,int requiredWoods){
    int amountOfWoods=0;
    for(auto ele:heightOfTrees){
        if(ele>=currentCuttingHeight){
            amountOfWoods+=(ele-currentCuttingHeight);
        }
    }
    if(amountOfWoods>=requiredWoods)return true;
    else return false;
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;++i)cin>>v[i];
    int low=0;
    int high=*max_element(v.begin(),v.end());
    
    while(high-low>1){
        int mid=(low+high)/2;
        if(isSufficientWood(v,mid,m)){
            low=mid;
        }
        else{
            high=mid-1;
        }
    }
    if(isSufficientWood(v,high,m)){
        cout<<high<<endl;
    }
    else cout<<low<<endl;
}