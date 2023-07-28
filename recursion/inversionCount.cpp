#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &v,int low,int high){
    int count=0;
    int mid=(low+high)/2;

    int i=low;
    int j=mid+1;
    vector<int> temp;
    while(i<=mid&&j<=high){
        if(v[i]<v[j]){
            temp.push_back(v[i++]);
        }
        else{
            temp.push_back(v[j++]);
            count+=(mid-i)+1;
        }
    }
    
    while(i<=mid){
        temp.push_back(v[i++]);
    }
    while(j<=high){
        temp.push_back(v[j++]);
     
    }
    for(int k=low;k<=high;++k){
        v[k]=temp[k-low];
    }
    return count;
    
}
int mergeSort(vector<int> &v,int low,int high){
    int count=0;
    if(low<high){
        int mid=(low+high)/2;
        count+=mergeSort(v,low,mid);
        count+=mergeSort(v,mid+1,high);
        count+=merge(v,low,high);
    }
    return count;
}
int main(){
    vector<int> v={1, 20, 6, 4, 5};
    int n=5;
    int count=0;
    cout<<mergeSort(v,0,n-1)<<endl;
    // cout<<count<<endl;
    
}