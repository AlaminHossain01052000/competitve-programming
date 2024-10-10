#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e6+123;
const int MOD=1e9+7;
int fact[N];
inline void normal(int &a) { a %= MOD; (a < 0) && (a += MOD); }
inline int modMul(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline int modAdd(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline int modSub(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline int modPow(int b, int p) { int r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline int modInverse(int a) { return modPow(a, MOD-2); }
inline int modDiv(int a, int b) { return modMul(a, modInverse(b)); }
void factFun(){
    fact[0]=1;
    for(int i=1;i<N;++i)fact[i]=modMul(fact[i-1],i);
}
int ncr(int n,int r){
    if(n<0||r<0||n<r)return 0;
    return modDiv(fact[n],modMul(fact[r],fact[n-r]));
}
//The complexity of below code is O(r).***Remember nCr=nC(n-r)=((n-1)C(r-1))+((n-1)Cr)
int complexNcr(int n,int r){
    if(n<0||r<0||n<r)return 0;
    int ret=1;
    for(int i=0;i<=r-1;++i){
        ret=modMul(ret,modDiv(n-i,i+1));
    }
    return ret;
}
signed main(){
    factFun();
    cout<<ncr(20,7)<<endl; 
    cout<<complexNcr(20,7)<<endl; 
}
