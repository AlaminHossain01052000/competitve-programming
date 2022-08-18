#include<bits/stdc++.h>
using namespace std;
const int M=1e6+7;
// calculate a^b
int bigMod(int a,int b){
    if(b==0) return 1;
    int x=bigMod(a,b/2);
    if(b&1){
        x=(x*1LL*x)%M;
        x=(x*1LL*a)%M;
    }
    else x=(x*1LL*x)%M;
    return x;

}


int main(){
cout<<bigMod(12,13)<<endl;

}