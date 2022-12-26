#include<bits/stdc++.h>
using namespace std;
#define ll long long int


//Time complexity of linear search is O(n)
//linearSearch function will accept the array,the size of the array and the value we are searching. It will return the index of the seached value in that array if exist otherwise -1
int linearSearch(vector<int> v,int size,int searchingValue){
    
    for(int i=0;i<size;++i){
        if(v[i]==searchingValue){
            return i;
        }
    }
    //If the value can not be found then return -1
    return -1;
}

//Time complexity of binary search is O(logn)
//binarySearch function will accept the array,the size of the array and the value we are searching. It will return the index of the seached value in O(logn) time in that array if exists otherwise -1
int binarySearch(vector<int> v,int size,int searchingValue){
    //Binary Search can only be implemented in sorted array
    sort(v.begin(),v.end());

    int low=0;
    int high=size-1;

    while(low<=high){
        int mid=(low+high)/2;
        //if the value is found then return the index mid
        if(v[mid]==searchingValue){
            return mid;
        }
        //If searching value = 2
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
        cout<<"Using Binary Search : "<<endl;
        int searchingElementIndex=binarySearch(v,n,value);
        // int searchingElementIndex=linearSearch(v,n,value);
        if(searchingElementIndex>=0){
            cout<<value<<" is found on index "<<searchingElementIndex<<" "<<(char) 1 <<endl;
        }
        else cout<<"This element is not found in this array "<<(char) 2<<endl;
        cout<<"Using Linear Search : "<<endl;
        searchingElementIndex=linearSearch(v,n,value);
        // int searchingElementIndex=linearSearch(v,n,value);
        if(searchingElementIndex>=0){
            cout<<value<<" is found on index "<<searchingElementIndex<<" "<<(char) 1 <<endl;
        }
        else cout<<"This element is not found in this array "<<(char) 2<<endl;

    }


}