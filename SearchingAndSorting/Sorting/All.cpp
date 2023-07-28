#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &v,int n){
    for(int i=0;i<n;++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void countSort(vector<int> &v,int n){
    int maxElement=*max_element(v.begin(),v.end());
    vector<int> count(maxElement+1,0);
    for(int i=0;i<n;++i){
        count[v[i]]++;
    }
    for(int i=1;i<=maxElement;++i){
        count[i]+=count[i-1];
    }
    vector<int> ans(n);

    for(int i=v.size()-1;i>=0;--i){
        ans[--count[v[i]]]=v[i];
    }
    // for(int i=0;i<v.size();++i) v[i]=ans[i];
    v=ans;
}
void heapify(vector<int> &v,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    while(left<v.size()&&v[largest]<v[left]){
        largest=left;
    }
    while(right<v.size()&&v[largest]<v[right]){
        largest=right;
    }
    if(largest!=i){
        swap(v[i],v[largest]);
        heapify(v,largest);
    }
}

vector<int> heapSort(vector<int> &v){
    int n=v.size();
    vector<int> ans;
    while(n>0){
        swap(v[n-1],v[0]);
        ans.push_back(v[n-1]);
        v.pop_back();
        heapify(v,0);
        n=v.size();
    }
    return ans;


}
int partition(vector<int> &v,int low,int high){
    int pivot=v[low];
    int i=low;
    int j=high;

    do{
        while(v[i]<=pivot){
            i++;
        }
        while(v[j]>pivot){
            j--;
        }
        if(i<j)swap(v[i],v[j]);
    }while(i<j);

    swap(v[low],v[j]);
    return j;
}
void quickSort(vector<int> &v,int low,int high){
    if(low<=high){
        int partitionIndex=partition(v,low,high);
        quickSort(v,low,partitionIndex-1);
        quickSort(v,partitionIndex+1,high);
    }
}
void mergerSort(vector<int> &v,int low,int high){
    if(low==high)return;
    int mid=(low+high)/2;
    mergerSort(v,low,mid);
    mergerSort(v,mid+1,high);
    int i,j,k;
    vector<int> ans(high+1);
    for(i=low,j=mid+1,k=low;k<=high;++k){
        if(i==mid+1)ans[k]=v[j++];
        else if(j==high+1) ans[k]=v[i++];
        else if(v[i]<v[j])ans[k]=v[i++];
        else ans[k]=v[j++];
    }
    for(int k=low;k<=high;++k){
        v[k]=ans[k];
    }
}
void bubbleSort(vector<int> &v,int n){
    for(int i=0;i<n-1;++i){
        int isSwapped=0;
        for(int j=0;j<n-i-1;++j){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                isSwapped=1;
            }
        }
        if(!isSwapped)break;
    }
}
void selectionSort(vector<int> &v,int n){
    for(int i=0;i<n-1;++i){
        int minimumIndex=i;
        for(int j=i+1;j<n;++j){
            if(v[minimumIndex]>v[j]){
                minimumIndex=j;
            }
        }
        swap(v[minimumIndex],v[i]);
    }
}
void insertionSort(vector<int> &v,int n){
    
    for(int i=1;i<n;++i){
        int insertableValue=v[i];
        int hole=i;

        while(hole>0&& insertableValue<v[hole-1]){
            v[hole]=v[hole-1];
            hole--;
        }
        v[hole]=insertableValue;
    }
}
int main(){
    vector<int> v={1002,3,43,56,65,0,1,0,1002};
    int n=9;
    // for(int i=n/2-1;i>=0;--i){
    //     heapify(v,i);
    // }
    cout<<"The Array Before Sorting Is : ";
    printArray(v,n);
    // quickSort(v,0,n-1);
    // mergerSort(v,0,n-1);
    // bubbleSort(v,n);
    // selectionSort(v,n);
    // insertionSort(v,n);
    // auto ans=heapSort(v);
    countSort(v,n);
    
    cout<<"The Array After Sorting Is : ";
    printArray(v,v.size());
    
    
}