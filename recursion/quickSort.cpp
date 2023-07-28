#include<bits/stdc++.h>
using namespace std;

int partitionIndex(vector<int> &v,int low,int high){
    int pivot=v[low];
    int i=low+1;
    int j=high;
    do{
        while(v[i]<=pivot){
            i++;
        }
        while(v[j]>pivot){
            j--;

        }
        if(i<j){
            swap(v[i],v[j]);
        }
    }while(i<j);
    swap(v[j],v[low]);
    return j;

}

void quickSort(vector<int> &v,int low,int high){
    int part_index;
    if(low<high){
        
         part_index=partitionIndex(v,low,high);

        quickSort(v,low,part_index-1);
        quickSort(v,part_index+1,high);
    }

}

int main(){
    vector<int> v={8,4,2,1};
    int n=4;
    quickSort(v,0,n-1);
    for(int i=0;i<n;++i)cout<<v[i]<<" ";
}