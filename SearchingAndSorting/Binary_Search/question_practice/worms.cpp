// https://codeforces.com/problemset/problem/474/B
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i)cin>>v[i];
    vector<int> prefixSum(n);
    prefixSum[0]=v[0];
    for(int i=1;i<n;++i){
        prefixSum[i]=v[i]+prefixSum[i-1];
    }
    // for(auto ele:prefixSum)cout<<ele<<" ";
    // cout<<endl;
    int m;
    cin>>m;
    for(int i=1;i<=m;++i){
        int q;
        cin>>q;
        int low=0;
        int high=n-1;
        //fffttttfff
        while(high-low>1){
            int mid=(high+low)/2;
            if(prefixSum[mid]>=q){
                high=mid;
            }
            else low=mid+1;
        }
        // cout<<prefixSum[low]<<" "<<q<<" "<<prefixSum[high]<<endl;
        if(prefixSum[low]>=q)cout<<low+1;
        
        else cout<<high+1;
        cout<<endl;
    }
}
