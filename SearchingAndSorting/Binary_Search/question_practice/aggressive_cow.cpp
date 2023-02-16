// https://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool canReplaceCows(int gap,int totalsCows,int numberOfStalls,vector<int> &stallsPosition){
    int left=-1;
    int count=0;
    for(int i=0;i<numberOfStalls;++i){
        if(left==-1||stallsPosition[i]-left>=gap){
            count++;
            left=stallsPosition[i];
        }
        if(count==totalsCows)break;
    }
    return count==totalsCows;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int> v(n);
        for(int i=0;i<n;++i){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int low=0;
        int high=*max_element(v.begin(),v.end());
        //TTTTTFFFF
        while(high-low>1){
            int mid=(low+high)/2;
            if(canReplaceCows(mid,c,n,v)){
                low=mid;
            }
            else{
                high=mid-1;
            }
        }
        if(canReplaceCows(high,c,n,v)){
            cout<<high<<endl;
        }
        else cout<<low<<endl;
    }
}