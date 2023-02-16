#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> v(n);
        for(int i=0;i<n;++i)cin>>v[i];
        while(q--){
            int h;
            cin>>h;
            int low=0;
            int high=n-1;
            while(high-low>1){
                int mid=(low+high)/2;
                if(v[mid]>h){
                    high=mid-1;
                }
                else low=mid;
            }
            int sum=0;
            for(int i=0;i<high;++i){
                sum+=v[i];
            }
            cout<<sum<<endl;
        }
    }
}