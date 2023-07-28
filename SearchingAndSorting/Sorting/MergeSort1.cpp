#include<bits/stdc++.h>
using namespace std;


//Print the array in O(n) complexity
void printArray(vector<int> &v){
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<int> &v,int low,int mid,int high){
    int i=low;
    int j=mid+1;
    vector<int> temp;

    while(i<=mid&&j<=high){
        if(v[i]<v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
        }
    }
    //if any elements remain on left subarray or right subarray then

    while(i<=mid){
        temp.push_back(v[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(v[j]);
        j++;
    }

    //Copying the sorted elements from low to high of temp array in main array
    for(int k=low;k<=high;++k){
        v[k]=temp[k-low];
    }
}

//Recursive function call to divide the array
void mergeSort(vector<int> &v,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(v,low,mid);
        mergeSort(v,mid+1,high);
        merge(v,low,mid,high);
    }
}
int main(){
        int t;
        cout<<"Enter Number of Testcases : ";
        cin>>t;
        while(t--){
            int n;
            cout<<"Enter Number of Elements of the array : ";
            cin>>n;
            vector<int> v(n);
            cout<<"Enter Space Separated Integers as Array Elements\n";
            for(int i=0;i<n;++i){
                cin>>v[i];
            }


            cout<<"The array before sorting is : ";
            printArray(v);
            mergeSort(v,0,n-1);
            cout<<"The array after sorting is : ";
            printArray(v);
        }


}
