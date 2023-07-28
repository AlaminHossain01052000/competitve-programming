#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool canEat(vector<int> &piles,int k,int hour,int totalBananas){
    int bananaEaten=0;
    int time=0;
    for(int i=0;i<piles.size();++i){
        if(k>=piles[i]){
            bananaEaten+=piles[i];
            time++;
        }
        else{
            time+=(piles[i]/k);
            if(piles[i]%k>0)time++;
            bananaEaten+=piles[i];
        }
        
    }
    if(time<=hour&&bananaEaten>=totalBananas){
        // cout<<k<<endl;
        return true;
    }
    else return false;

}
signed main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,h;
        cin>>n>>h;
        vector<int> v(n);
        
        for(int i=0;i<n;++i){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int totalBananas=0;
        for(int i=0;i<n;++i)totalBananas+=v[i];
        int low=1;
        int high=*max_element(v.begin(),v.end());
        //TTTTTFFFF
        while(high-low>1){
            int mid=(low+high)/2;
            if(canEat(v,mid,h,totalBananas)){
                high=mid;
            }
            else low=mid+1;
        }
        if(canEat(v,low,h,totalBananas)){
            cout<<low<<endl;
        }
        else cout<<high<<endl;
    }
    
}