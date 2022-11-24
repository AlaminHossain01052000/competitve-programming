#include<bits/stdc++.h>
using namespace std;
#define int long long int


// if b is even then a^b=[{a^(b/2)}*{a^(b/2)}]
// if b is odd then a^b=a*[{a^(b/2)}*{a^(b/2)}]
int calcPower(int a,int b){
    if(b==0)return 1;
    if(b==1)return a;

    int subProblem=calcPower(a,b/2);

    if(b%2==1){
        return a*subProblem*subProblem;
    }
    else return subProblem*subProblem;
}
signed main(){
    int a,b;
    cin>>a>>b;
    cout<<calcPower(a,b)<<endl;
}