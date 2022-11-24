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


void mergeSort( int low, int high){
    if(low==high)return;
    
        int mid = (low + high) /2;
        mergeSort( low, mid);
        mergeSort( mid+1, high);
        int i=low,j=mid+1;
        // vector<int> B(high-low+1);
        for(int k=low;k<=high;++k){
            if(i==mid+1)B[k]=A[j++];
            else if(j==high+1)B[k]=A[i++];
            else if(A[i]<A[j])B[k]=A[i++];
            else B[k]=A[j++];
        }   

        
        for(int k=low;k<=high;++k){
            
            A[k]=B[k];
        }
    
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    A= {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    cout<<"Array Before Sort :-- ";
    printArray(A, n);
    mergeSort( 0, 6);
    cout<<"Array After Sort :-- ";
    printArray(A, n);
    return 0;
}

// void merge(int A[], int mid, int low, int high)
// {
//     int i, j, k, B[100];
//     i = low;
//     j = mid + 1;
//     k = low;

//     while (i <= mid && j <= high)
//     {
//         if (A[i] < A[j])
//         {
//             B[k] = A[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             B[k] = A[j];
//             j++;
//             k++;
//         }
//     }
//     while (i <= mid)
//     {
//         B[k] = A[i];
//         k++;
//         i++;
//     }
//     while (j <= high)
//     {
//         B[k] = A[j];
//         k++;
//         j++;
//     }
//     for (int i = low; i <= high; i++)
//     {
//         A[i] = B[i];
//     }
    
// }