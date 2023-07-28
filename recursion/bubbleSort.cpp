#include<bits/stdc++.h>
using namespace std;
void print(vector<int> &v){
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void bubbleSort(vector<int> &v,int n){
    if(n==1)return;
    int largestElement=v[0];
    for(int i=0;i<n-1;++i){
        if(v[i]>v[i+1])swap(v[i],v[i+1]);
    }
    // swap(largestElement,v[n-1]);

    bubbleSort(v,n-1);

}
void selectionSort(vector<int> &v,int i){
  
    if(i==v.size()-1)return;
    int smallestIndex=i;
    for(int j=i+1;j<v.size();++j){
        if(v[j]<v[smallestIndex]){
            smallestIndex=j;
        }
    }
    swap(v[i],v[smallestIndex]);
    
    selectionSort(v,i+1);
}
void insertionSort(vector<int> &v,int i){
    if(i==v.size())return;
    int j=i-1;
    int temp=v[i];
    while(j>=0&&v[j]>temp){
        v[j+1]=v[j];
        j--;
    }
    v[j+1]=temp;
    insertionSort(v,i+1);
}
int main(){
    vector<int> v={2,9,1,4};
    int n=4;
    cout<<"Before Sorting : ";
    print(v);
    // bubbleSort(v,n);
    // selectionSort(v,0);
    insertionSort(v,1);
    cout<<"After Sorting : ";
    print(v);
}