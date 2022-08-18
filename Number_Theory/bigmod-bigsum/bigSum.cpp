#include<bits/stdc++.h>
using namespace std;

int bigSum(int a,int b){
    if(b==0) return 1;
    int x=bigSum(a*a,b/2);
    x=x+(a*x);
    return x;
    
}
int main(){
    cout<<bigSum(2,4)<<endl;
}