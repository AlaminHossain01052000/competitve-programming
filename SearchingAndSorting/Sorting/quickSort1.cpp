#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}
//It will consider an index as pivot and the arrange the array as like as that the small and equal number from the pivot will arranged in the left side of the pivot and the larger elements from the pivot will be arranged in the right side of the pivot. After such an arranging the function will return the partition index
int partition(vector<int> &v, int low, int high)
{
    int pivot = v[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (v[i] <= pivot)
        {
            i++;
        }

        while (v[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = v[low];
    v[low] = v[j];
    v[j] = temp;
    return j;
}
//the quickSort algorithm uses recursive approach to divide the problem in sub problems and sort the sub problems. It is also knows as divide and conquer approach
void quickSort(vector<int> &v,int low,int high){
    if(low<high){
        int partitionIndex=partition(v,low,high);

        quickSort(v,low,partitionIndex-1);
        quickSort(v,partitionIndex+1,high);
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
            quickSort(v,0,n-1);
            cout<<"The array after sorting is : ";
            printArray(v);
        }


}
