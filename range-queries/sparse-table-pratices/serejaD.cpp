// https://www.codechef.com/problems/SEAD?tab=statement
#include<bits/stdc++.h>
using namespace std;
int N=1e5+100;
int K=log2(N)+1;
vector<vector<int>>st(K,vector<int>(N));
void stMin(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n;++i)st[0][i]=v[i];
    for(int i=1;i<=K;++i){
        for(int j=0;j+(1<<i)<=n;++j){
            st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
}
int findK(vector<int>&v,int t){
    int n=v.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid+1==n)return n-1;
        if(v[mid]<=t&&v[mid+1]>t)return mid;
        if(v[mid]>t){
            high=mid;
        }
        if(v[mid]<=t&&v[mid+1]<=t)low=mid+1;
    }
    return n-1;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;++i)cin>>v[i];
    vector<int> gaps(n);
    for(int i=0;i<n-1;++i)gaps[i]=v[i+1]-v[i];
    gaps[n-1]=0;
    stMin(gaps);
    int m;
    cin>>m;
    while(m--){
        int t,d;
        cin>>t>>d;
        int ans;
        int kPos=findK(v,t);
        // cout<<"POS "<<kPos<<endl;
        int low=0;
        int high=kPos-1;
        while(low<high){
            
            int mid=(low+high)/2;
            int l=mid;
            int r=kPos;
            int i=log2(r-l+1);
            int maxGap=max(st[i][l],st[i][r-(1<<i)+1]);
            // cout<<low<<" "<<high<<" "<<maxGap<<endl;
            if(maxGap<=d){
                high=mid;
            }
            else{
                low=mid+1;
            }

        }
        if(low==high)ans=low;
        else ans=-1;
        //  int l=low;
        //     int r=kPos;
        //     int i=log2(r-l+1);
        //     int maxGap=max(st[i][l],st[i][r-(1<<i)+1]);
        //     if(maxGap<=d){
        //         ans=low;
        //     }
        //     else{
        //        int l=high;
        //     int r=kPos;
        //     int i=log2(r-l+1);
        //     int maxGap=max(st[i][l],st[i][r-(1<<i)+1]);
        //     if(maxGap<=d){
        //         ans=high;
        //     } 
        //     else ans=-2;
        //     }
            

    cout<<ans+1<<endl;
    }
    
}