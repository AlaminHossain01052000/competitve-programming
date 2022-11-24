#include<bits/stdc++.h>
using namespace std;


int digitSum(int n){
    if(n==0) return 0;
    return digitSum(n/10)+(n%10);
}
int main(){
    int n;
    cin>>n;
    cout<<digitSum(n)<<endl;
}
