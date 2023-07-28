#include<bits/stdc++.h>
using namespace std;

int sumOfArray(int a[],int n){
    if(n==1)return a[0];

    int sum=0;

    sum+=a[0]+sumOfArray(a+1,n-1);

    return sum;


} 

int main(){
    int v[]={2,4,6,9,11,13};
    int n=6;
    cout<<sumOfArray(v,n)<<endl;
    
}