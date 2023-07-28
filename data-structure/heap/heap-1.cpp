#include<bits/stdc++.h>
using namespace std;
int leftChild(int i){
    return 2*i;
}
int rightChild(int i){
    return 2*i+1;
}
void max_heapify(vector<int> &heap,int i,int n){
    
    int left=leftChild(i);
    int right=rightChild(i);
    int largest=i;
    if(right<=n&&heap[right]>heap[largest]){
        largest=right;
    }
    if(left<=n&&heap[left]>heap[largest]){
        largest=left;
    }
    if(i!=largest){
        swap(heap[i],heap[largest]);
        max_heapify(heap,largest,n);
    }
}
void heapSort(vector<int>&heap){
    int n=heap.size()-1;
    
    for(int i=n;i>=2;--i){
        swap(heap[1],heap[i]);
        max_heapify(heap,1,--n);
    }
}
void build_max_heap(vector<int>&v){
    int n=v.size();
    for(int i=n/2;i>=1;--i){
        max_heapify(v,i,n-1);
    }
}
int main(){
        vector<int> v={0,12,6,1,3,10,16,19,2,5};
        for(auto ele:v)cout<<ele<<" ";
        build_max_heap(v);
        cout<<endl;
        for(auto ele:v)cout<<ele<<" ";cout<<endl;

        heapSort(v);
        cout<<"Sorted Array : ";
        for(auto ele:v)cout<<ele<<" ";cout<<endl;

}