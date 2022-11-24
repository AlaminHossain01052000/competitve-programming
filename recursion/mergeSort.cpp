#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v,int low,int high){
    
    vector<int> temp;
    int mid=(low+high)/2;
    int i=low,j=mid+1;
    
    while(i<=mid&&j<=high){
        if(v[i]<v[j]){
            temp.push_back(v[i++]);
        }
        else {
            temp.push_back(v[j++]);
        }
        

    }
    while(i<=mid){
        temp.push_back(v[i++]);
    }
    while(j<=high){
        temp.push_back(v[j++]);
    }
    for(int p=low;p<=high;++p){
        v[p]=temp[p-low];
    }

}
void mergeSort(vector<int> &v,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
    mergeSort(v,low,mid);
    mergeSort(v,mid+1,high);
    merge(v,low,high);
    }
    else return;

}
void print(vector<int> v){
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v={18,2,-10,0,1,0};
    int n=6;
    print(v);
    cout<<endl;

    mergeSort(v,0,n-1);
    print(v);
}
