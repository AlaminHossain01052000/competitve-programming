#include<bits/stdc++.h>
using namespace std;
vector<int> v(100);
int size=0;

void insert(int value){
    if(size==0){
        size++;
        v[size]=value;
        return;
    }
    size++;
    v[size]=value;
    int index=size;
    while(index>1){
        int parentIndex=index/2;
        if(v[parentIndex]<v[index]){
            swap(v[parentIndex],v[index]);
            index=parentIndex;
        }
        else return;
    }


}

void deleteRoot(){
    if(size==0){
        cout<<"Nothing to delete";return;
    }
    v[1]=v[size];
    size--;
    int i=1;
    while(i<size){
        int leftChild=i*2;
        int rightChild=(i*2)+1;
      
        if(v[leftChild]>v[i]&&leftChild<=size){
            swap(v[leftChild],v[i]);
            i=leftChild;
        }
        else if(v[rightChild]>v[i]&&rightChild<=size){
            swap(v[rightChild],v[i]);
            i=rightChild;
        }
        else return;

    }

}
void heapify(vector<int> &arr,int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n&&arr[left]>arr[largest]){
        largest=left;
    }
    if(right<=n&&arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void printHeap(){
    for(int i=1;i<=size;++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    

    insert(60);
    insert(50);
    insert(40);
    insert(20);
    insert(30);
    printHeap();
    deleteRoot();
    printHeap();

    vector<int> ar={-1,1,2,3,4,5};
    int n=5;
    for(int i=n/2;i>0;--i){
        heapify(ar,n,i);
    }
    for(int i=1;i<=n;++i){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}