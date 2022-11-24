#include<bits/stdc++.h>
using namespace std;

int linearSearch(int a[],int n,int findingValue){
    //base case
    if(n==1&&a[0]!=findingValue){
        return -1;
    }
    else if(n==1&&a[0]==findingValue){
        return n;
    }
    if(a[0]==findingValue){
        return 1;
    }
    return linearSearch(a+1,n-1,findingValue);
}

int main(){
    int a[]={2,15,9,18,15,21};
    int n=6;
    cout<<linearSearch(a,n,21)<<endl;
}