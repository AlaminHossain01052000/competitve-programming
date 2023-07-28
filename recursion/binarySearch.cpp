#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int left,int right,int key){
    //base case
    // for(int i=left;i<=right;++i){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    if(left>right)return -1;

    int mid=(left+right)/2;

    if(a[mid]==key)return mid;

    if(a[mid]>key){
        return binarySearch(a,left,mid-1,key);
    }
    else return binarySearch(a,mid+1,right,key);
}

int main(){
    int a[]={2,4,6,8,10};
    int n=5;
    int key=100;
    cout<<binarySearch(a,0,n-1,key)<<endl;
    // cout<<binarySearch(a,n,21)<<endl;
}