#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}


int main(){


while(1){
    int a,b;
    cin>>a>>b;
    cout<<"GCD :- "<<__gcd(a,b)<<" LCM :- "<<a*b/(__gcd(a,b))<<endl;

}


}
