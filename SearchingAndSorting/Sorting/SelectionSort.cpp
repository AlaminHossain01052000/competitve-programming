#include<bits/stdc++.h>
using namespace std;
#define ll long long int


//Print the array in O(n) complexity
void printArray(vector<int> &v){
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


//Time complexity is O(n^2)
void selectionSort(vector<int> &v){
    int n=v.size();
    //As the last element of (n-1)th element will be sorted automitically so we wiil run the loop till (n-2)th element
    for(int i=0;i<=n-2;++i){
        int minimumIndex=i;

        //From i+1 to n-1 it will find the minimum element then v[i]
        for(int j=i+1;j<=n-1;++j){
            if(v[j]<v[minimumIndex]){
                minimumIndex=j;
            }
        }
        //Swap the minimum element with v[i]
        int temp=v[i];
        v[i]=v[minimumIndex];
        v[minimumIndex]=temp;
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

        for(int i=0;i<n;++i){
            cout<<"Enter "<<i+1<<" no element of the array : ";
            cin>>v[i];
        }

        cout<<"The array before sorting is : ";
        printArray(v);

        selectionSort(v);

        cout<<"The array after sorting is : ";
        printArray(v);

    }


}