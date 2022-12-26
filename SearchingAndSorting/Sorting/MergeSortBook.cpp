#include <bits/stdc++.h>
using namespace std;
vector<int> B(1000);
vector<int> A(1000);
void printArray(vector<int> &A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

//Mere sort follow divide and conquer approach to sort an array. 
void mergeSort( int low, int high){
    if(low==high)return; //base case
    //dividing array to two portion. 1. low to mid 2. mid+1  to high
        int mid = (low + high) /2;
        mergeSort( low, mid);
        mergeSort( mid+1, high);
        int i=low,j=mid+1;
        //merge the portions of the divided array together
        for(int k=low;k<=high;++k){
            if(i==mid+1)B[k]=A[j++]; //If there are no elements in left portion
            else if(j==high+1)B[k]=A[i++];//If there are no elements in right portion
            else if(A[i]<A[j])B[k]=A[i++];//if left[i] is smaller than right[i]
            else B[k]=A[j++];//if right[i] is smaller or equal than left[i]
        }   

        //copy the element of B into A
        for(int k=low;k<=high;++k){
            
            A[k]=B[k];
        }
    
}

int main()
{
    int n;
    cout<<"Enter Number of elements : ";
    cin>>n;
    cout<<"Enter "<<n<<" Space Separated Integers as Elements of the Array :"<<endl;
    for(int i=0;i<n;++i){
        cin>>A[i];
    }
    cout<<"Array Before Sort : ";
    printArray(A, n);
    mergeSort( 0, n-1);
    cout<<"Array After Sort : ";
    printArray(A, n);
    return 0;
}
