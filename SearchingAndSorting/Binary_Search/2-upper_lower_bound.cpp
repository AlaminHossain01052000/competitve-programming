#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int> &v,int element){
    int low=0;
    int high=v.size()-1;
    while(high-low>1){
        int mid=(low+high)/2;
        if(v[mid]<element){
            low=mid+1;
        }
        else high=mid;
    }
    if(v[low]>=element)return low;
    if(v[high]>=element)return high;
    return -1;
}
int upper_bound(vector<int>&v,int element){
    int low=0;
    int high=v.size()-1;
    while((high-low)>1){
        int mid=(low+high)/2;
        //as upper bound will return strictly greater than element
        if(v[mid]<=element){
            low=mid+1;
        }
        else high=mid;
    }
    if(v[low]>element)return low;
    if(v[high]>element)return high;
    else return -1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;++i)cin>>v[i];
        int element;
        cin>>element;
        int x=lower_bound(v,element);
        cout<<"Lower bound of "<<element<<" is "<<(x!=-1?v[x]:-1)<<endl;
        x=upper_bound(v,element);
        cout<<"Upper bound of "<<element<<" is "<<(x!=-1?v[x]:-1)<<endl;
    }
}
// 2
// 10
// 2 4 6 8 10 12 16 18 20 22
// 10
// Lower bound of 10 is 10
// Upper bound of 10 is 12
// 10
// 2 4 6 8 10 12 16 18 20 22
// 22
// Lower bound of 22 is 22
// Upper bound of 22 is -1