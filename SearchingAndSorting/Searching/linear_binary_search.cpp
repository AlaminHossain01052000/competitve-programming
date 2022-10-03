#include<bits/stdc++.h>
using namespace std;
#define ll long long int


//Time complexity of linear search is O(n)
int linearSearch(vector<int> v,int size,int searchingValue){
    
    for(int i=0;i<size;++i){
        if(v[i]==searchingValue){
            return i;
        }
    }
    return -1;
}

//Time complexity of linear search is O(logn)
int binarySearch(vector<int> v,int size,int searchingValue){
    //Binary Search can only be implemented in sorted array
    sort(v.begin(),v.end());

    int low=0;
    int high=size-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(v[mid]==searchingValue){
            return mid;
        }
        //If searching value =2
        // -11 -9 0 1 2 3
        else if(v[mid]<searchingValue){
            low=mid+1;
        }

        //If searching value =-9
        // -11 -9 0 1 2 3
        else if(v[mid]>searchingValue){
            high=mid-1;
        }

    }
    return -1;
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

        for(int i=0;i<n;++i){
            cout<<"Enter "<<i+1<<" no element of the array : ";
            cin>>v[i];
        }

        int value;
        cout<<"Enter the element you want to find in the array : ";
        cin>>value;
        
        int searchingElementIndex=binarySearch(v,n,value);
        // int searchingElementIndex=linearSearch(v,n,value);
        if(searchingElementIndex>=0){
            cout<<value<<" is found on index "<<searchingElementIndex<<" "<<(char) 1 <<endl;
        }
        else cout<<"This element is not found in this array "<<(char) 2<<endl;

    }


}