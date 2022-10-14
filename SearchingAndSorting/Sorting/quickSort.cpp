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

int partition(vector<int> &v,int low,int high){
    int pivot=v[high];
    int partitionIndex=low;
    for(int i=low;i<high;++i){
        if(v[i]<=pivot){
            swap(v[i],v[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(v[partitionIndex],v[high]);

    return partitionIndex;

}
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
