#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int M=1e6+5;
int factorial[N];

void factorialMethod(){
    factorial[0]=factorial[1]=1;
    for(int i=2;i<N;++i){
        factorial[i]=(factorial[i-1]*1LL*i)%M;
    }
}
int stirlingFirst(int n,int k){
    if(k==n) return 1;
    if(k==1) return factorial[n-1];
    int result=stirlingFirst(n-1,k-1)+((n-1)*stirlingFirst(n-1,k));
    return result;
}


int main(){
    factorialMethod();
    cout<<stirlingFirst(6,2)<<endl;

}