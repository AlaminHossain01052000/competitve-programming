#include<bits/stdc++.h>
using namespace std;
int strilingSecond(int n,int k){
    if(k==n||k==1) return 1;
    
    int result=strilingSecond(n-1,k-1)+k*(strilingSecond(n-1,k));
    return result;

}

int main(){

    cout<<strilingSecond(4,2)<<endl;

}