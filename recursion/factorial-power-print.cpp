#include<bits/stdc++.h>
using namespace std;

void printFront(int n){
    if(n==0)return;

    cout<<n<<endl;
    printFront(n-1);
}
void printBack(int n){
    if(n==0)return;
    printBack(n-1);
    cout<<n<<endl;
    
}

int powerOfTwo(int n){
    if(n==0) return 1;

    int smallerProblem=powerOfTwo(n-1);
    int biggerProblem=2*smallerProblem;
    return biggerProblem;
}
int fact(int n){
    if(n==0)return 1;
    return n*fact(n-1);
}
int main(){
    int n;
    cin>>n;

    cout<<"Factorial of n is "<<fact(n)<<endl;

    cout<<"2^n ======> "<<fact(n)<<endl;

    cout<<"Frontward Print : "<<endl;
    printFront(n);
    cout<<endl;

    cout<<"Backward Print : "<<endl;
    printBack(n);
    cout<<endl;

    
}